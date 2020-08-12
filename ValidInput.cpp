#include"ValidInput.h"
#include"ConvertTrue.h"
int ValidInput(int Row, int Column, char Table[8][8], int Turn, int Row1[2], int Column1[2], int Diameter1[4]) {
	int i = 0, j = 0, k = 0, l = 0, Counter = 0;
	for (i = 0; i < 2; i++) {
		Row1[i] = 0;
		Column1[i] = 0;
		Diameter1[i] = 0;
		Diameter1[i + 2] = 0;
	}
	if (Row > 7 || Row< 0 || Column> 7 || Column < 0) {
		return 1;
	}
	for (i = 0; i < 8; i++) {
		for (j = 0; j < 8; j++) {
			if (i == (Row ) && j == (Column) && Table[i][j] == '.') {
				Counter = 0;
				k = i + 1;
				while (Table[k][j] == ConvertTrue(Turn + 1) && k<8) {/*Check Input in Down-Column move */
					Counter++;
					k++;
				}
				if (Counter > 0 && Table[k][j] == ConvertTrue(Turn) && k<8)
					Column1[0] = 1;
				Counter = 0;
				k = i - 1;
				while (Table[k][j] == ConvertTrue(Turn + 1) && k >= 0) {/*Check Input in Up-Column Move*/
					Counter++;
					k--;
				}
				if (Counter > 0 && Table[k][j] == ConvertTrue(Turn) && k >= 0)
					Column1[1] = 1;
				Counter = 0;
				k = j + 1;
				while (Table[i][k] == ConvertTrue(Turn + 1) && k<8) {/*Check Input in Right-Row Move*/
					Counter++;
					k++;
				}
				if (Counter > 0 && Table[i][k] == ConvertTrue(Turn) && k<8)
					Row1[0] = 1;
				Counter = 0;
				k = j - 1;
				while (Table[i][k] == ConvertTrue(Turn + 1) && k >= 0) {/*Check Input in Left-Row Move*/
					Counter++;
					k--;
				}
				if (Counter > 0 && Table[i][k] == ConvertTrue(Turn) && k >= 0)
					Row1[1] = 1;
				Counter = 0;
				k = i + 1;
				l = j + 1;
				while (Table[k][l] == ConvertTrue(Turn + 1) && k<8 && l<8) {/*Check Input in Right-Down Move*/
					Counter++;
					k++;
					l++;
				}
				if (Counter > 0 && Table[k][l] == ConvertTrue(Turn) && k<8 && l<8)
					Diameter1[0] = 1;
				Counter = 0;
				k = i - 1;
				l = j - 1;
				while (Table[k][l] == ConvertTrue(Turn + 1) && k >= 0 && l >= 0) {/*Check Input in Left-Up Move*/
					Counter++;
					k--;
					l--;
				}
				if (Counter > 0 && Table[k][l] == ConvertTrue(Turn) && k >= 0 && l >= 0)
					Diameter1[1] = 1;
				Counter = 0;
				k = i - 1;
				l = j + 1;
				while (Table[k][l] == ConvertTrue(Turn + 1) && k >= 0 && l<8) {/*Check Input in Right-Up Move*/
					Counter++;
					k--;
					l++;
				}
				if (Counter > 0 && Table[k][l] == ConvertTrue(Turn) && k >= 0 && l<8)
					Diameter1[2] = 1;
				Counter = 0;
				k = i + 1;
				l = j - 1;
				while (Table[k][l] == ConvertTrue(Turn + 1) && k<8 && l >= 0) {/*Check Input in Left-Down Move*/
					Counter++;
					k++;
					l--;
				}
				if (Counter > 0 && Table[k][l] == ConvertTrue(Turn) && k<8 && l >= 0)
					Diameter1[3] = 1;
			}
		}
	}
	if (Row1[0] == 1 || Row1[1] == 1 || Column1[0] == 1 || Column1[1] == 1 || Diameter1[0] == 1 || Diameter1[1] == 1 || Diameter1[2] == 1 || Diameter1[3] == 1) {/*Check the Validity*/
		return 0;
	}
	return 1;
}