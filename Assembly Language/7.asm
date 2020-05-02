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
    printn ''
    MOV BL, AL
    print 'The number is: '
    TEST BL, 01H
    JNE ODD
    printn 'Even'
    JMP EXIT
    ODD:
        printn 'Odd'
    EXIT:
    MOV AH, 4ch
    INT 21h
    main ENDP  
END main