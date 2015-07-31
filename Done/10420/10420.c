#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
typedef struct _dic {
	char word[76];
	int count;
	struct _dic *leftptr;
	struct _dic *rightptr;
} dic;
typedef dic *dicptr;

dicptr create(dicptr tree, char* data) {/*{{{*/
	dicptr new = (dicptr)malloc( sizeof(dic) ); 
	dicptr tree_origin = tree;
	strcpy(new -> word, data);
	new -> count = 1;
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
				tree->count++;
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
		printf("%s %d\n", tree->word, tree->count);
		print( tree -> leftptr );
	}
}/*}}}*/


int main(void)
{
	int lines, i, j =0;
	char data[76], country[76];
	dicptr tree;
	scanf("%d\n", &lines);		
	for (; lines > 0; lines--){
		gets(data);
		for (i = 0; !isalpha(data[i]) ; i++) ;
		j=0;
		for (i ; isalpha(data[i]) ; i++) {
			country[j++] = data[i];
		}
		country[j] = '\0';
		tree = create(tree, country);
	}
	print(tree);
	return 0;
}
