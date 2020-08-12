#include"Rotate.h"
#include"ConvertTrue.h"
void Rotate(int Row, int Column, char Table[8][8], int Turn, int Row1[2], int Column1[2], int Diameter1[4], char TableFake[8][8]) {
	int i = Row , j = Column ;
	if (Column1[0] == 1) {
		while (TableFake[i][j] != ConvertTrue(Turn) && i<8) {/*Change colour in Down move*/
			Table[i][j] = ConvertTrue(Turn);
			i++;
		}
	}
	i = Row ;
	if (Column1[1] == 1) {
		while (TableFake[i][j] != ConvertTrue(Turn) && i >= 0) {/*Change colour in Up move*/
			Table[i][j] = ConvertTrue(Turn);
			i--;
		}
	}
	i = Row ;
	j = Column;
	if (Row1[0] == 1) {
		while (TableFake[i][j] != ConvertTrue(Turn) && j<8) {/*Change colour in Right move*/
			Table[i][j] = ConvertTrue(Turn);
			j++;
		}
	}
	i = Row ;
	j = Column ;
	if (Row1[1] == 1) {
		while (TableFake[i][j] != ConvertTrue(Turn) && j >= 0) {/*Change colour in Left move*/
			Table[i][j] = ConvertTrue(Turn);
			j--;
		}
	}
	i = Row;
	j = Column ;
	if (Diameter1[0] == 1) {
		while (TableFake[i][j] != ConvertTrue(Turn) && i<8 && j<8) {/*Change colour in Right-Down move*/
			Table[i][j] = ConvertTrue(Turn);
			i++;
			j++;
		}
	}
	i = Row ;
	j = Column;
	if (Diameter1[1] == 1) {
		while (TableFake[i][j] != ConvertTrue(Turn) && i >= 0 && j >= 0) {/*Change colour in Left-Up move*/
			Table[i][j] = ConvertTrue(Turn);
			i--;
			j--;
		}
	}
	i = Row ;
	j = Column;
	if (Diameter1[2] == 1) {
		while (TableFake[i][j] != ConvertTrue(Turn) && i >= 0 && j<8) {/*Change colour in Right-Up move*/
			Table[i][j] = ConvertTrue(Turn);
			i--;
			j++;
		}
	}
	i = Row;
	j = Column ;
	if (Diameter1[3] == 1) {
		while (TableFake[i][j] != ConvertTrue(Turn) && i<8 && j<8) {/*Change colour in Left-Down move*/
			Table[i][j] = ConvertTrue(Turn);
			i++;
			j--;
		}
	}
}