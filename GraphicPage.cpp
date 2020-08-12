#include"GraphicPage.h"
#include"graphics.h"
#include"ConvertCharToColor.h"
void GraphicPage(char Table[8][8], int Turn, int *Whites, int *Blacks,int Validity) {/*Showing the map of the game*/
	*Whites = 0;
	*Blacks = 0;
	clearviewport();
	setcolor(GREEN);
	rectangle(0, 0, 800, 800);
	setfillstyle(SOLID_FILL, GREEN);
	floodfill(50, 50, GREEN);
	setcolor(DARKGRAY);
	line(800, 0, 800, 800);
	rectangle(0, 800, 800, 1200);
	setfillstyle(SOLID_FILL, DARKGRAY);
	floodfill(1000, 400, DARKGRAY);
	setbkcolor(DARKGRAY);
	if (Turn % 2 == 1) {
		setcolor(BLACK);
		settextstyle(8, 0, 2);
		outtextxy(870, 50, "BLACK Player's Turn");
	}
	else {
		setcolor(WHITE);
		settextstyle(8, 0, 2);
		outtextxy(870, 50, "WHITE Player's Turn");
	}
	setcolor(DARKGRAY);
	for (int i = 100; i < 800; i += 100) {
		line(0, i, 800, i);
		line(i, 0, i, 800);
	}
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			if (Table[i][j] == 'w')
				(*Whites)++;
			if (Table[i][j] == 'b')
				(*Blacks)++;
			if (ConvertCharToColor(Table[i][j]) != 1) {/*Show the marbles*/
				setcolor(ConvertCharToColor(Table[i][j]));
				circle(j * 100 + 50, i * 100 + 50, 45);
				setfillstyle(SOLID_FILL, ConvertCharToColor(Table[i][j]));
				floodfill(j * 100 + 50, i * 100 + 50, ConvertCharToColor(Table[i][j]));
			}
		}
	}
	char Score[128];
	setbkcolor(DARKGRAY);
	setcolor(WHITE);
	settextstyle(8, 0, 4);
	sprintf(Score, "%d", *Whites);
	circle(950, 350, 30);
	setfillstyle(SOLID_FILL,WHITE);
	floodfill(950,350,WHITE);
	outtextxy(990, 335, Score);
	setcolor(BLACK);
	sprintf(Score, "%d", *Blacks);
	circle(950, 450, 30);
	setfillstyle(SOLID_FILL, BLACK);
	floodfill(950, 450, BLACK);
	outtextxy(990, 435, Score);
	settextstyle(8, 0, 2);
	if (Validity == 1) {
		setbkcolor(RED);
		setcolor(DARKGRAY);
		outtextxy(870, 200 , "Can't put marble here!");
		outtextxy(840, 240 , "Please choose a valid place!");
	}
}