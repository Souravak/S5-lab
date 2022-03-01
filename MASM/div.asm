ASSUME CS: CODE, DS: DATA

DATA SEGMENT
	DVDH DW 2222H
	DVDL DW 2222H
	DVR DW 1111H
	QH DW 1 DUP(?)
	QL DW 1 DUP(?)
	REM DW 1 DUP(?)
	MSG DW 1 "ZERO DIVISION","$"
DATA ENDS

CODE SEGMENT
START:	MOV AX, DATA
		MOV DS, AX
		
		CMP DVR, 0000H
		JZ LABEL1
		MOV AX, DVDH
		MOV DX, 0000H
		DIV DVR
		MOV QH, AX
		MOV AX, DVDL 	
	    DIV DVR
		MOV QL, AX
		MOV REM, DX
		JMP LABEL2

LABEL1:	MOV DX, OFFSET MSG
		MOV AH, 09H
		INT 21H

LABEL2:	MOV AH, 4CH
		INT 21H
CODE ENDS
END START		
				
