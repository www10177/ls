#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main(void)
{
	int case_num, dic_num, i, already_use[27], status, index;
	char encode[1000010], tempT, tempR, dic_array[27]={'\0'};
	for (scanf("%d\n", &case_num); case_num > 0 ; case_num--) {
		gets(encode);
		for (i = 1; i < 27; i++) {
			already_use[i] = -1;
			dic_array[i] = '\0';	
		}
		for (scanf("%d\n", &dic_num); dic_num > 0 ; dic_num --) {
			scanf("%c %c\n", &tempR, &tempT);
			status = 0;
			index = (int)tempT - 64;
			if ( dic_array[index] == '\0') {
				dic_array[index] = tempR;
				status = 1;
			}
			for (i = 1; i < 27 ; i++) {
				if ( already_use[i] != -1 ) {
					index = already_use[i];	
					if ( dic_array[index] == tempT) {
						dic_array[index] = tempR;
					}
				}
				else {
					break;
				}
			}
			if ( status == 1) {
				already_use[i] = (int)tempT - 64;	
			}
		}
		/*for (i = 1; i < 27; i++) {*/
			/*printf("%d %d\n",i,dic_array[i]);*/
		/*}*/
		/*printf("%s\n", encode);*/
		for (i = 0; i < strlen(encode); i++) {
			/*printf("%c",encode[i]);*/
			if ( isupper(encode[i]) ) {
				index = (int)encode[i] - 64;	
				if ( dic_array[index] != '\0') {
					/*printf("\n%d!%c %c\n",index,  encode[i], dic_array[index]);*/
					encode[i] = dic_array[index];
				}
			}
		}
		printf("%s\n", encode);
	}
	return 0;
}
