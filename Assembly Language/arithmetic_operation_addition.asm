; ADDITION OF TWO INTEGERS WHICH SUM IS LESS THAN 10

.model small
.stack 100h
.data                              
    PROMPT_1 DB "Enter A Number : $"         
    PROMPT_2 DB "Addition of Two Numbers Are: $"
    NUM1 DB ?
    NUM2 DB ?
.code
main proc
    ; DS Init.
    MOV AX, @data
    MOV DS, AX
    
    
    ; DISPLAYING PROMPT_1
    MOV AH, 9
    LEA DX, PROMPT_1
    INT 21h
    
    XOR AX, AX  ; CLEARING AX
    MOV AH, 1   ; TAKING INPUT
    INT 21H
    
    MOV NUM1, AL    ; MOVING THE VALUE TO VARIABLE 
    
    XOR AX, AX      ; CLEARING AX
    
    ; PRINTING NEWLINE
    MOV AH, 2
    MOV DL, 0AH
    INT 21H
    MOV AH, 2
    MOV DL, 0DH
    INT 21H
    
    ; DISPLAYING PROMPT_1
    MOV AH, 9
    LEA DX, PROMPT_1
    INT 21h
    
    MOV AH, 1       ; TAKING INPUT
    INT 21H
    
    MOV NUM2, AL    ; MOVING THE VALUE TO VARIABLE
    
    ; PRINTING NEWLINE
    MOV AH, 2
    MOV DL, 0AH
    INT 21H
    MOV AH, 2
    MOV DL, 0DH
    INT 21H
    
    ; DISPLAYING PROMPT_2
    MOV AH, 9
    LEA DX, PROMPT_2
    INT 21H
    
    SUB NUM1, 48    ; CONVERTING ASCII TO DECIMAL
    SUB NUM2, 48    ; CONVERTING ASCII TO DECIMAL
    MOV AL, NUM2    ; MOVING THE NUM2 VALUE TO AL
    
    ADD NUM1, AL    ; PERFORMING ADDITION
    ADD NUM1, 48    ; CONVERTING TO ASCII VALUE
    
                    ; PRINTING NUM1 WHICH IS OUR RESULT
    MOV AH, 2
    MOV DL, NUM1
    INT 21H
    
    ; RETURN
    MOV AH, 4ch
    INT 21h
    main endp
end main