ASSUME CS: CODE, DS: DATA
DATA SEGEMENT
STR DB 100 DUP('$')
LEN DW $-STR
MSG1 DB 0DH, 0AH, "PALINDROME","$"
MSG2 DB 0DH, OAH, "NOT PALINDROME","$"
DATA ENDS

CODE SEGMENT
START:  MOV AX, DATA
        MOV DX, AX

        LEA SI, STR
INPUT:  MOV AH, 1H
        INT 21H
        CMP AL, 13
        JE L1
        MOV [SI], AL
        INC SI
        JMP INPUT







STARTING ADDRESS
AH<-1H FROM 21H
CHECK IF END CMP AL,13 RETURN 1 IF EQUAL
IF EQUAL THE END OF THE INPUT IS REACHED
ELSE STORE IT IN ARR SI -[SI]
INC SI
JMP INPUT
MOV DI OFFSET STR WILL STORE STARTING ADDRESS
CMP SI