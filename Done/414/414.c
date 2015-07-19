#include <stdio.h>
int main(void)
{
	char surface[13][26];
	while ( 1 ) {
		int line, i, j;
		int blank_total = 0, blank_per_line,  less_blank= 25, X_count;
		scanf("%d\n", &line);
		if ( line == 0) {
			break;	
		}
		for (i = 0; i < line; i++) {
			gets(&surface[i][0]);
				X_count = 0;
			for (j = 0; j < 25; j++) {
				if ( surface[i][j] == 'X') {
					X_count++;	
				}
			} 
			blank_per_line = 25-X_count;
			if (blank_per_line < less_blank ) {
				less_blank= blank_per_line;	
			}
			blank_total += blank_per_line; 
		}
		printf("%d\n", blank_total - line*less_blank);
	}
	return 0;
}
