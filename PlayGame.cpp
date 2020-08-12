#include"PlayGame.h"
#include"Rotate.h"
#include"Input.h"
#include"ValidInput.h"
#include"GraphicPage.h"
#include"graphics.h"
#include<stdio.h>
void PlayGame(char Table[8][8], int Turn, char TableFake[8][8],int *Whites,int *Blacks) {
	char TrashInput;
	int TrashNumber = 0, Wrong = 0, i = 0, j = 0, Counter = 0, Row1[2] = { 0,0 }, Column1[2] = { 0,0 }, Diameter1[4] = { 0,0,0,0 },Row,Column;
	Input(&Row, &Column, Table,Turn,Whites,Blacks,0);
	Wrong = ValidInput(Row, Column, Table, Turn, Row1, Column1, Diameter1);
	if (Wrong == 1) {
		while (Wrong == 1) {
			Input(&Row, &Column, Table,Turn,Whites,Blacks,Wrong);
			Wrong = 0;
			Wrong = ValidInput(Row, Column, Table, Turn, Row1, Column1, Diameter1);
		}
	}
	Rotate(Row, Column, Table, Turn, Row1, Column1, Diameter1, TableFake);/*Change the colours in each move*/
	for (i = 0; i < 8; i++) {
		for (j = 0; j < 8; j++) {
			TableFake[i][j] = Table[i][j];
		}
	}
}