#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
int main(void)
{
	char data;
	int count = 0;	
	int i;

	while ( scanf("%c", &data) != EOF ) {
		if ( isdigit(data) ) {
			count += atoi(&data);
		}
		else if ( (data == '\n') || (data == '!') ) {
			printf("\n");
		}
		else if ( data == 'b') {
			for (i = 0; i < count; i++) {
				printf(" ");
			}
				count = 0;
		}
		/*else if ( data == ' ') {*/
			/*printf("\n");*/
		/*}*/
		else { 
			for (i = 0; i < count; i++) {
				printf("%c", data);
			}
				count = 0;
		}
	}
	return 0;
}
