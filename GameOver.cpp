#include "GameOver.h"
#include"graphics.h"
void GameOver(int Whites, int Blacks, char *EndGame) {/*Show the result of match*/
	char TrashInput[80];
	initwindow(650, 200, "Game Is Over!");
	setcolor(DARKGRAY);
	setbkcolor(BLACK);
	settextstyle(8, 0, 2);
	outtextxy(20,20,"There is no more choice in the game!");
	if (Blacks > Whites) /*Winning or draw states*/
		outtextxy(20,40,"BLACK has won the game!");
	else if (Whites > Blacks)
		outtextxy(20,40,"WHITE has won the game!");
	else
		outtextxy(20,40,"There is a draw in the game");
	sprintf(TrashInput, "WHITES = %d BLACKS = %d", Whites, Blacks);
	outtextxy(20,100,TrashInput);
	outtextxy(10,150,"If You Want To Start A New Game,Press c.Else,Press e");/*Continue or end the game*/
	scanf("%c%c", EndGame, TrashInput);
	closegraph();
}