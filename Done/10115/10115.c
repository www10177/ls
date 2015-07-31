#include <stdio.h>
#include <string.h>
#include <stdlib.h>
typedef struct _dic {
	char origin[81];
	char replace[81];
	struct _dic *nextPtr;
}dic;

typedef dic *dicPtr;
dicPtr createnode(char*, char*);
dicPtr enqueue(dicPtr, dicPtr);

int main(void)
{
	int dic_num, i, len;	
	dicPtr dictionary = NULL, Head;
	char temp_A[81], temp_B[81];
	char text[260], temp_tail[260];
	dicPtr temp_C;
	while ( scanf("%d\n", &dic_num) ) {
		if ( dic_num == 0) {
			break;	
		}
		for ( i = 0; i < dic_num; i++) {
			gets(temp_A);
			gets(temp_B);
			temp_C = createnode(temp_A, temp_B);
			dictionary = enqueue( dictionary, temp_C );
		}
		gets(text);
		Head = dictionary;
		while( dictionary != NULL){
			len = strlen(dictionary->origin);
			/*printf("strlen %d\n", strlen(text) - len + 1);*/
			int text_len = strlen(text) - len + 1;
			for ( i = 0; i < text_len; i++) {
				if ( !strncmp(dictionary->origin, &text[i], len ) ) {
					/*printf("i %d len %d\n", i ,len);*/
					/*if ( text[i+len] == '\0') {*/
						/*text[i] = '\0';*/
						/*strcat(text, dictionary->replace);*/
						/*text[i+strlen(dictionary->replace)] = '\0';*/
						/*printf("!!%s\n", text);*/
					/*}*/
					/*else{*/
						strcpy(temp_tail, &text[i+len]);
						text[i] = '\0';
						strcat(text, dictionary->replace);
						strcat(text, temp_tail);
					/*}*/
					text_len = strlen(text) - len + 1;
					i = 0;
				}
			}
			/*printf("\tori :%s re %s\n", dictionary->origin, dictionary->replace);*/
			/*printf("%s\n", text);*/
			dictionary = dictionary -> nextPtr;
		}
		/*printf("\nDinal\n");*/
		printf("%s\n", text);
		free(Head);
	}
	return 0;
}
dicPtr createnode(char* ori, char* rep){/*{{{*/
	dicPtr new = (dicPtr)malloc( sizeof(dic) );
	strcpy( new->origin, ori );
	strcpy( new->replace, rep );
	new -> nextPtr = NULL;
	return new;
}/*}}}*/

dicPtr enqueue(dicPtr ori, dicPtr new){/*{{{*/
	if ( ori == NULL) {
		return new;	
	}
	dicPtr Head = ori;
	while ( ori -> nextPtr != NULL) {
		ori = ori->nextPtr;
	}
	ori -> nextPtr = new;
	return Head;
}/*}}}*/
