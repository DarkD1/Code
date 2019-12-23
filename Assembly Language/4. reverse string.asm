INCLUDE 'emu8086.inc'
.model small
.stack 100h
.data                              
.code
main PROC
    MOV AX, @data
    MOV DS, AX
    print 'Enter a String: '
    XOR CX, CX
    TAKEINPUT:
        MOV AH, 1
        INT 21H
        CMP AL, 13
        JE ENDOFINPUT
        PUSH AX
        INC CX
        JMP TAKEINPUT
    ENDOFINPUT:   
        printn ''
        print 'Reverse String: '
        MOV AH, 2
        @DISPLAY:
         POP DX
         INT 21H
        LOOP @DISPLAY
        MOV AH, 4ch
        INT 21h
    main ENDP  

END main