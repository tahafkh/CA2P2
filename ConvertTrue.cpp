#include"ConvertTrue.h"
char ConvertTrue(int Turn) {/*Convert turn to its character*/
	if (Turn % 2 == 1)
		return 'b';
	return 'w';
}