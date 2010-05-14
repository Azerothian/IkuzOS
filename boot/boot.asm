; boot.asm  %macro fn_RealPrint 1

; Sets up a macro for printing a message on the screen in RealMode 

mov si, word %1  real_print:  
lodsb 
or al, al
; zero=end of str 
jz hang

; get out 
mov ah, 0x0E 
int 0x10 
jmp real_print done: %endmacro  [ORG 0x7c00]

;Setup our Entry Point  
xor ax, ax 
mov ds, ax 
 
fn_RealPrint wel_msg 
 hang: 
jmp hang 
 wel_msg db 'Welcome to IkuzOS',13,10,0 
tim
