.model small
.stack 100h
.data                              
    PROMPT_1 DB "Enter a Message: $"
    PROMPT_2 DB "Enter the Value of N: $"
    MESSAGE DB 100 DUP('$')
.code
main proc
    ; DS Init.
    MOV AX, @data
    MOV DS, AX
    
    ; Displaying PROMPT_1
    MOV AH, 9
    LEA DX, PROMPT_1
    INT 21h
    
    MOV SI, OFFSET MESSAGE
    
    TAKEINPUT:
        MOV AH, 1
        INT 21H
        
        CMP AL, 13
        JE ENDOFINPUT
        MOV [SI], AL
        INC SI
        JMP TAKEINPUT
        
    ENDOFINPUT:
    
        ; New Line
        MOV AH, 2
        MOV DL, 0AH
        INT 21H
        MOV DL, 0DH
        INT 21H
        
        ; Displaying PROMPT_2 
        MOV AH, 9
        LEA DX, PROMPT_2
        INT 21H
        
        ; Taking User Input
        MOV AH, 1
        INT 21H  
        
        XOR CX, CX      ; Clearing CX
                       
        MOV CL, AL      ; Putting User Input into CL
        SUB CL, 30h     ; Converting the Ascii value to Decimal
        
        ; New Line
        MOV AH, 2
        MOV DL, 0AH
        INT 21H
        MOV DL, 0DH
        INT 21H
        
        ; For Loop
        FOR:   
            MOV AH, 9
            LEA DX, MESSAGE
            INT 21H
            MOV AH, 2
            MOV DL, 0AH
            INT 21H
            MOV DL, 0DH
            INT 21H
        LOOP FOR         
        
    
        ; Return
        MOV AH, 4ch
        INT 21h
    main endp
end main