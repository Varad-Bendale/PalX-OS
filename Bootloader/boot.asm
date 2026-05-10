bits 16
org 0x7C00

start: 
    mov cl , 0  
    mov ax  , 0x0003
    int 0x10
    
    mov ah , 0x02 
    mov bh , 0x00 
    mov dh , 9 
    mov dl , 27 
    int 0x10 

    mov si, msg
    call print
   
    mov ah , 0x02
    mov bh , 0x00
    mov dh , 10
    mov dl , 37
    int 0x10
    mov si , msg1
    call print
    jmp start_loop 

load_bar :
   push ax 
   push cx 
   mov ah , 0x02
   mov bh , 0x00
   mov dh , 12
   mov dl , 35
   add dl , cl
   int 0x10 
   mov ah , 0x0E  
   mov al , '#' 
   int 0x10
   pop cx
   pop ax 
   ret

start_loop :
   
    cmp cl ,10 
    je  halt
    mov ah, 0x02
    mov bh, 0x00
    mov dh, 11
    mov dl, 40      
    int 0x10
    mov ah , 0x0E
    mov al ,cl
    add al , 48 
    int 0x10 
    call load_bar
    inc cl
    call delay  
    jmp short start_loop

delay :
   push cx
   push dx
   mov ah , 0x00
   int 0x1A
   mov bx , dx 

wait_loop : 
  mov ah , 0x00 
  int 0x1A 
  sub dx,bx 
  cmp dx , 9
  jb wait_loop 
  pop dx 
  pop cx 
  ret 


print:
    lodsb
    or al, al
    jz done
    mov ah, 0x0E
    int 0x10
    jmp short  print

done:
    ret
halt: 
    cli 
    hlt

msg db 'Welcome to new revolution',13 ,10 , 0
msg1 db 'PALX OS'  , 0 

times 510-($-$$) db 0
dw 0xAA55
