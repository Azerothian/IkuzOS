org 0x0			; offset to 0, we will set segments later

bits 16

jmp main		; Jump to main
main:
	
	;Dont know whats in the segment registers so lets just reload them anyway :)
	xor ax, ax
	mov ds, ax
	mov es, ax
	mov fs, ax
	mov gs, ax
	mov ss, ax
	
	mov ax, 0x9000
	mov ss, ax
	mov sp, 0xFFFF
	
	jmp switch_to_prot
	
	
EnableA20:
	mov ax, 0x2401
	int 0x15
	ret
	
;*************************************************************************
; PROCEDURE DisplayMessage
; display ASCIIZ string at "ds:si" via BIOS
;*************************************************************************
DisplayMessage:
     lodsb                                       ; load next character
     or      al, al                              ; test for NUL character
     jz      .DONE
     mov     ah, 0x0E                            ; BIOS teletype
     mov     bh, 0x00                            ; display page 0
     mov     bl, 0x07                            ; text attribute
     int     0x10                                ; invoke BIOS
     jmp     DisplayMessage
.DONE:
     ret

switch_to_prot:

	cli ;None of these

	;Dont know whats in the segment registers so lets just reload them anyway :)
	xor ax, ax
	mov ds, ax
	mov es, ax
	mov fs, ax
	mov gs, ax
	mov ss, ax

	; Load the GDT
	lgdt [GDTptr]

	; Enter Protected Mode
	mov eax, cr0
	or eax, 1
	mov cr0, eax
	jmp 0x8:In32


bits 32
In32:
	;-------------------------------;
	;   Set registers		;
	;-------------------------------;

	mov		ax, 0x8		; set data segments to data selector (0x10)
	mov		ds, ax
	mov		ss, ax
	mov		es, ax
	mov		esp, 90000h		; stack begins from 90000h

	cli
	hlt
	


	;----------------------
	dochar:
	    call cprint              ; print one character
	sprint:
	    mov eax, [esi]          ; string char to AL
	    lea esi, [esi+1]
	    cmp al, 0
	    jne dochar               ; else, we're done
	    add byte [ypos], 1       ; down one row
	    mov byte [xpos], 0       ; back to left
	    ret

	cprint:
	    mov ah, 0x0F             ; attrib = white on black
	    mov ecx, eax             ; save char/attribute
	    movzx eax, byte [ypos]
	    mov edx, 160             ; 2 bytes (char/attrib)
	    mul edx                  ; for 80 columns
	    movzx ebx, byte [xpos]
	    shl ebx, 1               ; times 2 to skip attrib

	    mov edi, 0xb8000         ; start of video memory
	    add edi, eax             ; add y offset
	    add edi, ebx             ; add x offset

	    mov eax, ecx             ; restore char/attribute
	    mov word [ds:edi], ax
	    add byte [xpos], 1       ; advance to right

	    ret

	;------------------------------------


; Offset 0 in GDT: Descriptor code=0

gdt_data: 
	dd 0 				; null descriptor
	dd 0 

; Offset 0x8 bytes from start of GDT: Descriptor code therfore is 8

; gdt code:				; code descriptor
	dw 0FFFFh 			; limit low
	dw 0 				; base low
	db 0 				; base middle
	db 10011010b 			; access
	db 11001111b 			; granularity
	db 0 				; base high

; Offset 16 bytes (0x10) from start of GDT. Descriptor code therfore is 0x10.

; gdt data:				; data descriptor
	dw 0FFFFh 			; limit low (Same as code)
	dw 0 				; base low
	db 0 				; base middle
	db 10010010b 			; access
	db 11001111b 			; granularity
	db 0				; base high

;...Other descriptors begin at offset 0x18. Remember that each descriptor is 8 bytes in size?
; Add other descriptors for Ring 3 applications, stack, whatever here...

end_of_gdt:
GDTptr: 
	dw end_of_gdt - gdt_data - 1 	; limit (Size of GDT)
	dd gdt_data 			; base of GDT
		
xpos db 0
ypos db 0
strIkzLdrStart db 'IKZLDR is setting up the environment',0x0D, 0x0A, 0x00
strIn32 db 'Entering 32Bit Protected Mode: ', 0 
strEA20 db 'Enabling the A20 Gate: ', 0
strMessageOK db '[OK]',0x0D, 0x0A, 0x00
strKB db ' Kb',0x0D, 0x0A, 0x00
kb_ram db 0