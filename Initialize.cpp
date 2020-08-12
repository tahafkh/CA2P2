void Initialize(char Table[8][8], int *Turn, char TableFake[8][8], int *Possible) {
	int i = 0, j = 0;/*Initializing the game*/
	for (i = 0; i < 8; i++) {
		for (j = 0; j < 8; j++) {
			if (i == 3 && j == 3) {
				Table[i][j] = 'w';
				TableFake[i][j] = 'w';
			}
			else if (i == 3 && j == 4) {
				Table[i][j] = 'b';
				TableFake[i][j] = 'b';
			}
			else if (i == 4 && j == 3) {
				Table[i][j] = 'b';
				TableFake[i][j] = 'b';
			}
			else if (i == 4 && j == 4) {
				Table[i][j] = 'w';
				TableFake[i][j] = 'w';
			}
			else {
				Table[i][j] = '.';
				TableFake[i][j] = '.';
			}
		}
	}
	(*Turn) = 1;
	(*Possible) = 1;
}