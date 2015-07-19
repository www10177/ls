#include <stdio.h>
#include <string.h>

int main(void)
{
	char data[100][101];
	int line = 0;
	int i, j = 0;;
	int status;
	int end[100] = {0};
	for (i = 0; i <100 ; i++) {
		memset(&data[i][0], ' ' , 101);
	}
	while ( gets(&data[line][0]) != NULL) {
		line++;
	}
	for (status = line; status > 0 ;){ 
		for (i = line-1; i>=0 ; i--) {
			if ( end[i] == 1) {
				printf(" ");
			}
			else if ( data[i][j+1] == '\0') {
				printf("%c", data[i][j]);
				end[i]=1;
				status --;
			}
			else{
				printf("%c", data[i][j]);
			}
		}
		/*if ( status != 0) {*/
			printf("\n");
		/*}*/
		++j; 
	}
	return 0;
}
