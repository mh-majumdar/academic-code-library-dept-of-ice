.MODEL SMALL
.STACK 100H
.DATA
.CODE

MAIN PROC
    MOV AH,1
    INT 21H
    MOV BL,AL 
    
    MOV AH,1
    INT 21H
    MOV CL,AL 
    
    ADD BL,CL
    SUB BL,30H
    
    MOV AH,2
    MOV DL,BL
    INT 21H
    
    MOV AH,4CH
    INT 21H
    
    MAIN ENDP
END MAIN