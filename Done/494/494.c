#include <stdio.h>
#include <ctype.h>
int main(void)
{
	char input[200];
	int word_count = 0, i, status = 0;
	while ( gets(input) != NULL) {
		status = 0;
		word_count = 0;
		for (i = 0; input[i] != '\0'; i++) {
			if ( (isalpha(input[i])) && (isalpha(input[i+1])) ){ 
				status = 1;
			}
			else if ( (isalpha(input[i])) && (!isalpha(input[i+1])) ){ 
				if ( status = 1) {
					word_count++;
				}
				status = 0;	
			}
			else if(!isalpha(input[i]) ){
				status = 0;	
			}
		}
		printf("%d\n", word_count);
	}
	return 0;
}
