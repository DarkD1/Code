INCLUDE 'emu8086.inc'
.model small
.stack 100h
.data                              
.code
main PROC
    MOV AX, @data
    MOV DS, AX
    print 'Enter a lowercase character: '
    MOV AH, 1
    INT 21h        
    printn ''
    print 'Uppercase character is: '
    MOV AH, 2
    SUB AL, 32
    MOV DL, AL
    INT 21h
    MOV AH, 4ch
    INT 21h
    main ENDP  
END main