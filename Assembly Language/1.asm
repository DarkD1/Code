INCLUDE "emu8086.inc"
.model small
.stack 100h
.data
.code
main PROC
    printn "Alphabet A to Z:"
    MOV AH, 2
    MOV CX, 26
    MOV DL, 65
    @LOOP:
        INT 21h
        INC DL
        DEC CX
    JNZ @LOOP
    MOV AH, 4ch
    INT 21h
    main ENDP
END main