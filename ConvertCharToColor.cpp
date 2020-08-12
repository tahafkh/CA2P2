#include"ConvertCharToColor.h"
#include"graphics.h"
int ConvertCharToColor(char Char) {/*Showing the colors for each character in table*/
	if (Char == 'w') {
		return WHITE;
	}
	else if (Char == 'b') {
		return BLACK;
	}
	return 1;
}