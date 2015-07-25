#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
	int case_num, i, j, case_counter;
	double P, I, U;
	char data[100];
	scanf("%d\n", &case_num);	
	for (case_counter = 1; case_counter <= case_num; case_counter++){
		gets(data);
		P = 0; U = 0; I = 0;
		for ( i = 0; i < strlen(data); i++) {
			if ( data[i] == '=') {
				if ( data[i-1] == 'P') {/*{{{*/
					P = atof( &data[i+1] );
					j=i;
					while ( data[j] != 'W' ) {
						j++;
					}
					j--;
					if ( data[j] == 'm') {
						P /= 1000;
					}
					else if ( data[j] == 'k') {
						P *= 1000;
					}
					else if ( data[j] == 'M') {
						P *= 1000000;
					}
				}		/*}}}*/
				else if ( data[i-1] == 'U') {/*{{{*/
					U = atof( &data[i+1] );
					j=i;
					while ( data[j] != 'V' ) {
						j++;
					}
					j--;
					if ( data[j] == 'm') {
						U /= 1000;
					}
					else if ( data[j] == 'k') {
						U *= 1000;
					}
					else if ( data[j] == 'M') {
						U *= 1000000;
					}
				}		/*}}}*/
				else if ( data[i-1] = 'I') {/*{{{*/
					I = atof( &data[i+1] );
					j=i;
					while ( data[j] != 'A' ) {
						j++;
					}
					j--;
					if ( data[j] == 'm') {
						I /= 1000;
					}
					else if ( data[j] == 'k') {
						I *= 1000;
					}
					else if ( data[j] == 'M') {
						I *= 1000000;
					}
				}		/*}}}*/
			}
		}
		printf("Problem #%d\n", case_counter);
		if ( P == 0) {
		P = U * I;
		printf("P=%.2lfW\n", P);
		}
		else if ( U == 0) {
		U = P / I;
		printf("U=%.2lfV\n", U);
		}
		else if ( I == 0) {
		I = P / U;
		printf("I=%.2lfA\n", I);
		}
		printf("\n");
	}
	return 0;
}
