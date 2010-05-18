org 0x0			; offset to 0, we will set segments later

[BITS 16]

jmp main		; Jump to main
main:

	cli			; Clear Interrupts
	push cs		; Insure DS=CS
	pop ds
	sti
	
	mov si,strIkzLdrStart
	call DisplayMessage

	mov si,strEA20
	call DisplayMessage
	
	call EnableA20
	
	mov si,strMessageOK
	call DisplayMessage
	
	; Clear and Halt making sure there is no triple faults
	cli
	hlt
	
	
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

xpos db 0
ypos db 0
strIkzLdrStart db 'IKZLDR is setting up the environment',0x0D, 0x0A, 0x00
strIn32 db 'Entering 32Bit Protected Mode: ', 0 
strEA20 db 'Enabling the A20 Gate: ', 0
strMessageOK db '[OK]',0x0D, 0x0A, 0x00
strKB db ' Kb',0x0D, 0x0A, 0x00
kb_ram db 0