#include <stdio.h>
#include <string.h>
#include <stdlib.h>
typedef struct _node {
	char data[100];
	int length;
	struct _node *nextPtr;
} node;
typedef struct _node *NodePtr;

NodePtr createNode(char*);
NodePtr insertNode(NodePtr, char*);
int check(NodePtr, char*);
void PRINT(NodePtr in){/*{{{*/
	if (in == NULL) {
		printf( "in: NULL\n");
	}
	int i =1;
	while ( in != NULL) {
		printf("%d DATA:%s LEN:%d\n", i++, in->data, in->length);
		in = in -> nextPtr;
	}
	return ;
}/*}}}*/

int isLast(NodePtr test){/*{{{*/
	if ( test -> nextPtr == NULL) {
		return 1;	
	}
	else {
		return 0;
	}
}/*}}}*/

int main(void)
{
	NodePtr binary = NULL;
	char datain[100];
	int status, case_num = 1;;
	while ( gets(datain) != NULL) {
		if ( datain[0] == '9') {
			printf("Set %d is immediately decodable\n", case_num++);
			free(binary);		
			binary = NULL;
		}
		else{
			status = check(binary, datain);
			if ( status == 0 ) {
				binary = insertNode(binary, datain);
			}
			/*PRINT(binary);printf("\nsta %d\n", status);*/
			if ( status ) {
				printf("Set %d is not immediately decodable\n", case_num++);
				free(binary);		
				binary = NULL;
				while ( 1 ) {
					gets(datain);
					if ( datain[0] == '9' ) {
						break;	
					}
				}
			}
		}
	}
	return 0;
}

NodePtr createNode(char* Data){/*{{{*/
	NodePtr new = (NodePtr)malloc( sizeof(node) );
	new -> nextPtr = NULL;
	strcpy(new->data, Data);
	new -> length = strlen(Data);
	return new;
}/*}}}*/
NodePtr insertNode(NodePtr bin, char* Data){/*{{{*/
	NodePtr new = createNode(Data);
	NodePtr Origin = bin;
	NodePtr Last = NULL;
	int len = strlen(Data);
	if ( bin == NULL) {
		return new;	
	}
	else if ( bin -> nextPtr == NULL) {
		if ( len > (bin -> length) ) {
			bin -> nextPtr = new;
			return Origin;
		}
		else {
			new -> nextPtr = bin;
			return new;	
		}
	}
	else {
		if ( len <= bin -> length) {
			new -> nextPtr = bin;
			return new;	
		}
		while ( len > bin -> length) {
			Last = bin; 
			if ( isLast( bin ) ) {
				bin -> nextPtr = new;
				return Origin;	
			}
			bin = bin -> nextPtr;
		}
		Last -> nextPtr = new;
		new -> nextPtr = bin;
		return Origin;
	}
}/*}}}*/
int check(NodePtr bin, char* test){/*{{{*/
	/*return 1 if is not immediately decodvble*/
	int len = strlen( test );
	int i, status;
	if ( bin == NULL ) {
		return 0;	
	}
	while ( bin != NULL ) {
len = strlen( test );
		if ( bin -> length == len ) {
			if ( strcmp(bin->data, test) == 0) {
				return 1;	
			}
		}
		if ( len > bin -> length ) {
			len = bin -> length;
		}
		/*printf("length test data %d %s %s\n",len, test, bin->data);*/
		status =1;
		for (i = 0; i < len; i++) {
			/*printf("F %c U %c\n", test[i], bin->data[i]);*/
			if ( test[i] != bin->data[i] ) {
				status = 0;
				break;
			}
		}
		/*printf("    status %d\n", status);*/
		if ( status ) 
			return 1;	
		bin = bin -> nextPtr;
		if ( bin == NULL ) {
			return 0;	
		}
	}
	return 0;
}/*}}}*/
