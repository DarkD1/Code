; DISPLAY USER INPUT SINGLE CHARACTER

.MODEL SMALL
.STACK 100H

.DATA              ; DATA SEGMENT  

    CHAR DB ? 
    
.CODE              ; CODE SEGMENT   

MAIN PROC          ; INT MAIN()
                
    MOV AX, @DATA ; INIT. DATA SEGMENT
    MOV DS, AX            
                
                
    ; USER INPUT
    MOV AH, 1
    INT 21H
           
       ; USER INPUT DATA IS STORED IN AL    
           
    ; MOVING DATA INTO NUM
    MOV CHAR, AL
    
    ; NEW LINE
    MOV AH, 2
    MOV DL, 0AH
    INT 21H
    MOV DL, 0DH
    INT 21H
    
    ; OUTPUT 
    MOV DL, CHAR
    INT 21H
    
    ; RETURN 0
    MOV AH, 4CH
    INT 21H   
    
    MAIN ENDP  

END MAIN 