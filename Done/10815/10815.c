#include <stdio.h>
#include <string.h>
#include <stdlib.h>
typedef struct _dic {
	char word[202];
	struct _dic *leftptr;
	struct _dic *rightptr;
} dic;
typedef dic *dicptr;

dicptr create(dicptr tree, char* data) {/*{{{*/
	dicptr new = (dicptr)malloc( sizeof(dic) ); 
	dicptr tree_origin = tree;
	strcpy(new -> word, data);
	new -> leftptr = NULL;
	new -> rightptr = NULL;
	if ( tree == NULL) {
		return new;
	}
	else{
		dicptr tree_parent = tree;
		while ( tree != NULL) {
			int cmp = strcmp(tree->word, data);
			if ( cmp == 0 ) {
				return tree_origin;
			}
			else if (cmp > 0) {
				tree_parent  = tree;
				tree = tree -> rightptr;	
			}
			else if (cmp < 0) {
				tree_parent  = tree;
				tree = tree -> leftptr;	
			}
		}

		if ( tree == NULL) {
			int cmp = strcmp(tree_parent->word, data);
			if (cmp > 0) {
				tree_parent -> rightptr = new;	
			}
			else if (cmp < 0) {
				tree_parent -> leftptr = new;	
			}
			return tree_origin;
		}
	}
}/*}}}*/

void print(dicptr tree){/*{{{*/
	if ( tree != NULL) {
		print( tree -> rightptr );
		printf("%s\n", tree->word);
		print( tree -> leftptr );
	}
}/*}}}*/
int main(void)
{
	int i, head, j;
	char sentences[201], temp[201];
	dicptr tree = NULL;
	while ( gets(sentences) != NULL ) {
		for (i = 0; sentences[i] != '\0'  ; i++) {
			if ( isalpha(sentences[i]) ) {
				j = 0;
				memset(temp,'\0',201);
				while ( isalpha(sentences[i]) ) {
					temp[j] = tolower(sentences[i]);
					j++;i++;
				}
				temp[j] = '\0';
				i--;
				tree =  create(tree, temp);
			}
		}
	}
	print(tree);

	return 0;
}
