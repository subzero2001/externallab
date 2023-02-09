data segment
    msg1 db 10,13,"Enter the string:$"
    msg2 db 10,13,"Palindrome $"
     msg3 db 10,13,"Not Palindrome $"
     str db 10h dup("$")
     data ends

extra segment
    revstr db 10h dup("$")
    extra ends

code segment
    assume cs:code,ds:data,es:extra
    start:
   
    mov ax,data
    mov ds,ax    
   
     
    mov ax,extra
    mov es,ax
               
               
     lea dx,msg1
     mov ah,09h
     int 21h
     
     mov ah,0ah  
     lea dx,str
     int 21h

               
     lea si,str
     inc si
     mov cl,[si]
     mov bl,cl
     mov ch,0
     inc si
     
     
     lea di,revstr
     add di,cx
     dec di
     
     back:cld
     lodsb
     std
     stosb
     loop back
     
     lea si,str
     inc si
     inc si
     lea di,revstr
     mov cl,bl
     mov ch,0
     
     
     cld
     repe cmpsb
     jnz no
     
     mov ah,09h
     lea dx,msg2
     int 21h  
     jmp skip
     
     
     no  : mov ah,09h
     lea dx,msg3
     int 21h
     
     skip:mov ah,4ch
     int 21h  
     
     code ends
end start