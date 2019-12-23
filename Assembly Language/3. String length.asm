INCLUDE 'emu8086.inc'
.model small
.stack 100h
.data                              
    MESSAGE DB 100 DUP('$')
.code
main PROC
    MOV AX, @data
    MOV DS, AX
    print 'Enter a Message: '
    MOV SI, OFFSET MESSAGE
    XOR CX, CX
    TAKEINPUT:
        MOV AH, 1
        INT 21H
        CMP AL, 13
        JE ENDOFINPUT
        INC CX
        MOV [SI], AL
        INC SI
        JMP TAKEINPUT
    ENDOFINPUT:
        printn ''
        print 'Length of the string: '
        XOR AX, AX
        MOV AX, CX
        CALL OUTDEC
        MOV AH, 4ch
        INT 21h
    main ENDP  

    OUTDEC PROC   
       PUSH BX
       PUSH CX
       PUSH DX
       CMP AX, 0
       JGE @START
       PUSH AX
       MOV AH, 2
       MOV DL, '-'
       INT 21H
       POP AX
       NEG AX
       @START:
       XOR CX, CX
       MOV BX, 10
       @OUTPUT:
         XOR DX, DX
         DIV BX
         PUSH DX
         INC CX
         OR AX, AX
       JNE @OUTPUT
       MOV AH, 2
       @DISPLAY:
         POP DX
         OR DL, 30H
         INT 21H
       LOOP @DISPLAY
       POP DX
       POP CX
       POP BX
       RET
     OUTDEC ENDP
END main