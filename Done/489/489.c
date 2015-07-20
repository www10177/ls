#include <stdio.h>

int main(void)
{
	int  keyword_array[27] = {0}; 
	/*0 is not the keyword; 1 is the keyword; 2 is the keyword and also be flip out*/
	int round, try_times, all_keyword;
	char Keyword[100], user_input[100];
	int i, temp;

	while ( 1 ) {
		scanf("%d\n", &round);
		if ( round == -1) {
			break;
		}
		printf("Round %d\n", round);
		all_keyword = 0;
		try_times = 0;

		for (i = 1; i < 27; i++) {
			keyword_array[i] = 0;	
		}

		gets(Keyword);
		gets(user_input);
		for (i = 0; Keyword[i] != '\0' ; i++) {
			temp = Keyword[i] - 96;
			if  ( keyword_array[temp] == 0) {
				all_keyword ++;	
			}
			keyword_array[temp] = 1;
		}
		for (i = 0; user_input[i] != '\0' ; i++) {
			if ( try_times >= 7 ) {
				break;	
			}
			else if ( all_keyword  == 0) {
				break;	
			}
			temp = user_input[i] - 96;
			if  ( keyword_array[temp] == 1) {
				keyword_array[temp] = 2;
				all_keyword --;
			}
			else if ( keyword_array[temp] == -1) {

			}
			else if ( keyword_array[temp] == 0) {
				try_times++;
				keyword_array[temp] = -1;
			}
		}
		if ( try_times >= 7) {
			printf("You lose.\n");
		}
		else if ( all_keyword == 0) {
			printf("You win.\n");
		}
		else if ( try_times < 7 && all_keyword >= 1) {
			printf("You chickened out.\n");

		}
	}
	return 0;
}
