#include"Input.h"
#include<stdio.h>
#include"graphics.h"
#include"GraphicPage.h"
void Input(int *Row, int *Column,char Table[8][8],int Turn,int *Whites,int * Blacks,int Validity) {
	char Move = 'w', Enter;
	int Wrong = 0,TrashNumber=0,Lenght=50,Width=50;
	GraphicPage(Table,Turn,Whites,Blacks,Validity);
	setcolor(RED);
	rectangle(Lenght -10, Width -10, Lenght + 10, Width + 10);
	setfillstyle(SOLID_FILL, RED);
	floodfill(50, 50, RED);
	while (Move != ' ') {
		scanf("%c%c", &Move,&Enter);/*Check the truth of input*/
		if (Move == '\n' || Enter!='\n') {
			Wrong = 1;
		}
		while (Enter != '\n'){
			scanf("%c", &Enter);
			if (Enter != '\n')
				TrashNumber++;
		}
		if (TrashNumber > 0)
			Wrong = 1;
		TrashNumber = 0;
		if (Move != 'w' && Move != 's'&& Move != 'a' && Move != 'd' && Move != ' ')
			Wrong = 1;
		if (Move == 'w' && Width == 50)
			Wrong = 1;
		if (Move == 's' && Width == 750)
			Wrong = 1;
		if (Move == 'a' && Lenght == 50)
			Wrong = 1;
		if (Move == 'd' && Lenght == 750)
			Wrong = 1;
		while (Wrong == 1) {
			Wrong = 0;
			GraphicPage(Table, Turn, Whites, Blacks,0);
			setcolor(RED);
			rectangle(Lenght - 10, Width - 10, Lenght + 10, Width + 10);
			setfillstyle(SOLID_FILL, RED);
			floodfill(Lenght,Width, RED);
			setbkcolor(RED);
			setcolor(DARKGRAY);
			outtextxy(900, 100,"INVALID INPUT!");
			outtextxy(820, 140, "Please enter a Valid movement!");
			scanf("%c%c", &Move, &Enter);/*Check the truth of input*/
			if (Move == '\n' || Enter != '\n') {
				Wrong = 1;
			}
			while (Enter != '\n') {
				scanf("%c", &Enter);
				if (Enter != '\n')
					TrashNumber++;
			}
			if (TrashNumber > 0)
				Wrong = 1;
			TrashNumber = 0;
			if (Move != 'w' && Move != 's'&& Move != 'a' && Move != 'd' && Move != ' ')
				Wrong = 1;
			if (Move == 'w' && Width == 50)
				Wrong = 1;
			if (Move == 's' && Width == 750)
				Wrong = 1;
			if (Move == 'a' && Lenght == 50)
				Wrong = 1;
			if (Move == 'd' && Lenght == 750)
				Wrong = 1;
		}
		if (Move == 'w')/*Change the square position*/
			Width -= 100;
		if (Move == 's')
			Width += 100;
		if (Move == 'a')
			Lenght -= 100;
		if (Move == 'd')
			Lenght += 100;
		GraphicPage(Table,Turn,Whites,Blacks,0);
		setcolor(RED);
		rectangle(Lenght - 10, Width - 10, Lenght + 10, Width + 10);
		setfillstyle(SOLID_FILL, RED);
		floodfill(Lenght , Width , RED);
	}
	(*Row) = (Width - 50)/100;/*returning the value of final position*/
	(*Column) = (Lenght - 50) / 100 ;
}