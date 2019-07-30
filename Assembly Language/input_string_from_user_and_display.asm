; DISPLAY STRING

.MODEL SMALL
.STACK 100H

.DATA              ; DATA SEGMENT  

    MESSAGE DB "HELLO WORLD FROM ASSEMBLY LANGUAGE$" 
    
.CODE              ; CODE SEGMENT   

MAIN PROC          ; INT MAIN()
                
    MOV AX, @DATA ; INIT. DATA SEGMENT
    MOV DS, AX            
    
    ; PRINTING MESSAGE
    MOV AH, 9            
    LEA DX, MESSAGE 
    INT 21H   
                      
    ; NEW LINE
    
    MOV AH, 2
    MOV DL, 0AH
    INT 21H
    MOV DL, 0DH
    INT 21H
    
    ; RETURN 0
    MOV AH, 4CH
    INT 21H   
    
    MAIN ENDP  

END MAIN 