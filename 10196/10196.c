#include <stdio.h>
int checkp (char**);
int main(void)
{
	int status = 0;//1 for the black win, 2 for the white
	char chess[9][9];
	int i, j;
	while ( scanf("%d",&i)!= EOF) {
		for (i = 1; i <= 8; i++) {
			for (j = 1; j <= 8; j++) {
				scanf("%c",&chess[i][j]);
			}
			scanf("\n");
		}
		scanf("\n");
		for (i = 1; i <= 8; i++) {
			for (j = 1; j <= 8; j++) {
				if (chess[i][j] == 'p') {
					status = checkp(chess);

				}

			}
		}

	}
	return 0;
}//main
int checkp(char** input){
}
