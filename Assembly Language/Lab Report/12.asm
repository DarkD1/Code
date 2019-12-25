INCLUDE 'emu8086.inc'
.model small
.stack 100h
.data                              
    X DB 20 dup(?)                 
    Y DB 20 dup(?)
    N DB ?
    RES DW ?
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
    print 'ENter the value of array x: '
    MOV SI, OFFSET X
    TAKEX:
        MOV AH, 1
        INT 21h
        SUB AL, 48
        MOV [SI], AL
        INC SI
    LOOP TAKEX
    printn ''
    print 'ENter the value of array y: '
    XOR CX, CX
    MOV CL, N
    MOV SI, OFFSET Y
    TAKEY:
        MOV AH, 1
        INT 21h
        SUB AL, 48
        MOV [SI], AL
        INC SI
    LOOP TAKEY
    printn ''
    MOV SI, OFFSET X
    MOV DI, OFFSET Y
    XOR CX, CX
    MOV CL, N
    TASK:
        MOV AL, [SI]
        MOV BL, [DI]
        MUL BL
        INC SI
        INC DI
        ADD RES, AX
    LOOP TASK
    MOV AX, RES
    print 'Result is: '
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