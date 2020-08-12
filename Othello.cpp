#include"graphics.h"
#include"GameOver.h"
#include<stdio.h>
#include "Possibility.h"
#include "PlayGame.h"
#include "GraphicPage.h"
#include "Initialize.h"
int main() {/*Initializing variables*/
	char Table[8][8], TableFake[8][8], EndGame = 'c', TrashInput;
	int Turn = 1, Possible = 1, Blacks = 0, Whites = 0;
	while (EndGame != 'e') {
		initwindow(1200, 800, "Othello");
		Initialize(Table, &Turn, TableFake, &Possible);/*Initializing the game*/
		GraphicPage(Table, Turn, &Whites, &Blacks, 0);/*Printing the first board*/
		while (Possible) {
			PlayGame(Table, Turn, TableFake, &Whites, &Blacks);/*Play the game in each turn*/
			GraphicPage(Table, Turn, &Whites, &Blacks, 0);/*Update the board and printting it*/
			Turn++;/*Change the turn*/
			Possible = Possibility(Table, Turn);/*Check whether there is a possible cell for next player*/
		}
		GraphicPage(Table, Turn, &Whites, &Blacks, 0);/*Final page*/
		GameOver(Whites, Blacks, &EndGame);/*Show the winner and check if user wants to play again or not*/
	}
	return 0;
}