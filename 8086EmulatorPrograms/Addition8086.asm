DATA SEGMENT
    MSG1 DB 0DH,0AH,"pLEASE ENTER FIRST NUMBER $"
    MSG2 DB 0DH,0AH,"pLEASE ENTER SECOND NUMBER $"
    
    A DB 00H
    B DB 00H
    SUM DB ?
    CARRY DB 00H
    MSG3 DB 0DH,0AH,"SUM IS $"  
    MSG4 DB 0DH,0AH,"CARRY IS $" 
    
DATA ENDS

CODE SEGMENT
    ASSUME CS:CODE,DS:DATA
    START:
    
    MOV AX,DATA
    MOV DS,AX
    
    MOV AH,09H
    LEA DX,MSG1
    INT 21H
    
    MOV AH,01H
    INT 21H
    
    MOV BH,AL 
    
     
    MOV AH,01H
    INT 21H
    
    MOV BL,AL 
    
     MOV AH,09H
    LEA DX,MSG2
    INT 21H
    
    MOV AH,01H
    INT 21H
    
    MOV CH,AL 
    
     
    MOV AH,01H
    INT 21H
    
    MOV CL,AL
              
    MOV AL,BL
    MOV AH,00H
    ADD AL,CL
    AAA
    ADD AX,3030H
    
    MOV BL,AL  
    
    
    MOV AL,AH
    MOV AH,00H
    ADD AL,BH
    ADD AL,CH
    AAA
    ADD AX,3030H
    MOV BH,AL   
    MOV CL,AH
    
    
    LEA DX,MSG3
    MOV AH,09H
    INT 21H
    
    MOV DL,BH
     MOV AH,02H
    INT 21H 
    
    
    MOV DL,BL
    MOV AH,02H
    INT 21H   
    
     
    LEA DX,MSG4
    MOV AH,09H
    INT 21H
    
    MOV DL,CL
     MOV AH,02H
    INT 21H 
 
    MOV AH,4CH
    INT 21H
    
CODE ENDS
END START