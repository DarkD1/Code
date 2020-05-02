INCLUDE 'emu8086.inc'
.model small
.stack 100h
.data                              
.code
main PROC
    MOV AX, @data
    MOV DS, AX
    print 'Enter a Number: '
    MOV AH, 1
    INT 21h
    SUB AL, 48
    XOR AH, AH
    MOV CX, AX
    MOV AX, 1
    FACT:
        MUL CX
    LOOP FACT
    EXIT:
    printn ''
    print 'Factorial of the number is: '
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