INCLUDE 'emu8086.inc'
.model small
.stack 100h
.data              
STR DB 40 dup('?')                      
.code
main PROC
    MOV AX, @data
    MOV DS, AX
    MOV SI, OFFSET STR
    XOR CX, CX
    TAKEINPUT1:
        MOV AH, 1   
        INT 21H
        CMP AL, 13    
        JE ENDOFINPUT1
        MOV [SI], AL 
        INC SI     
        JMP TAKEINPUT1
    ENDOFINPUT1:
    printn ''
    TAKEINPUT2:
        MOV AH, 1   
        INT 21H
        CMP AL, 13    
        JE ENDOFINPUT2
        MOV [SI], AL 
        INC SI   
        JMP TAKEINPUT2
    ENDOFINPUT2:
    MOV [SI], '$'
    printn ''    
    MOV AH, 9
    LEA DX, STR
    INT 21H
    MOV AH, 4ch
    INT 21h
    main ENDP  
END main