INCLUDE 'emu8086.inc'
.model small
.stack 100h
.data                              
    N DB ?
    RES DB ?
.code
main PROC
    MOV AX, @data
    MOV DS, AX
    print 'Enter the value of N: '
    MOV AH, 1
    INT 21h
    SUB AL, 48
    MOV N, AL
    printn ''
    MOV RES, 0
    XOR CX, CX
    MOV CL, N
    TASK:
        ADD RES, CL
    LOOP TASK
    XOR AX, AX
    MOV AL, RES
    print 'Sum of the series: '
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