#include <stdio.h>
#include <string.h>
#include <strings.h>
#include <ctype.h>

int main(void)
{
	int excuse_num, keyword_num, i, j=0, count =1;
	char key[20][21], excuse[20][71];
	int excuse_count[20], highest = 0;;
	while ( scanf("%d %d\n", &keyword_num, &excuse_num) != EOF ) {
		printf("Excuse Set #%d\n",count++);

		/*init*/
		highest=0;

		/*get data*/
		for (i = 0; i < keyword_num; i++) {
			gets(&key[i][0]);
		}
		for (i = 0; i < excuse_num; i++) {
			gets(&excuse[i][0]);
			/*for (j = 0; excuse[i][j] != '\0'  ; j++) {*/
				/*if ( isupper(excuse[i][j]) ) {*/
					/*excuse[i][j] = tolower(excuse[i][j]);*/
				/*}*/
			/*}*/
		}

		for (i = 0; i < excuse_num; i++) {
			int head = 0,  value = 0 ;
			while(excuse[i][head] != '\0' ){
				while ( !isalpha(excuse[i][head]) ) {
					if(excuse[i][head] == '\0' ){
						break;
					}
					head++;	
				}
					if(excuse[i][head] == '\0' ){
						break;
					}
				/*printf("head: %d\n", head);*/
				for (j = 0; j < keyword_num; j++) {
					char* temp = &key[j][0];
					if ( !strncasecmp( temp , &excuse[i][head], strlen(temp) ) ){
						value++;	
					}
				}
				while ( isalpha(excuse[i][head]) ) {
					if(excuse[i][head] == '\0' ){
						break;
					}
					head++;	
				}
			}
			excuse_count[i] = value;

			if ( excuse_count[i] >= highest) {
				highest = excuse_count[i];	
			}
		}
		for (i = 0; i < excuse_num; i++) {
				/*printf("%d\t%s\n", excuse_count[i], excuse[i]);*/
			if ( excuse_count[i] == highest) {
				printf("%s\n", excuse[i]);
			}
		}
			printf("\n");
	}
	return 0;
}
