#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct _Number {
	char row[5][101];
	struct _Number *nextNum;
}Number; 
typedef Number *NumberPtr;

NumberPtr Generate(int,int);
NumberPtr CreateNumberList(NumberPtr in ,int data, int length){/*{{{*/
	NumberPtr new = Generate(length, data);
	if ( in == NULL ) {
		return new; 
	}
	NumberPtr origin = in;
	while ( in -> nextNum != NULL ) {
		in = in -> nextNum; 
	}
	in -> nextNum = new;
	return origin;
}/*}}}*/
void Print(NumberPtr list, int length){/*{{{*/
	char Row[1000];
	NumberPtr origin = list;
	int i,j;
	/*row 1*/
	while ( list != NULL ) {
		printf("%s", &list->row[0][0]);		
		list = list->nextNum;
		if ( list != NULL ) 
			printf(" ");
	}
	printf("\n");
	list = origin;

	/*row 2*/
	j = 0;
	while ( list != NULL ) {
		for (i = 0; list->row[1][i] != '\0'; i++) {
			Row[j++] = list->row[1][i];		
		}
		list = list->nextNum;
		if ( list != NULL ) 
			Row[j++] = ' '; 
	}
	Row[j] = '\0';
	list = origin;
	for (i = 0; i < length; i++) {
		printf("%s\n", Row);
	}

	/*row 3*/
	while ( list != NULL ) {
		printf("%s", &list->row[2][0]);		
		list = list->nextNum;
		if ( list != NULL ) 
			printf(" ");
	}
	printf("\n");
	list = origin;

	/*row 4*/
	j = 0;
	while ( list != NULL ) {
		for (i = 0; list->row[3][i] != '\0'; i++) {
			Row[j++] = list->row[3][i];		
		}
		list = list->nextNum;
		if ( list != NULL ) 
			Row[j++] = ' '; 
	}
	Row[j] = '\0';
	list = origin;
	for (i = 0; i < length; i++) {
		printf("%s\n", Row);
	}

	/*row 5*/
	while ( list != NULL ) {
		printf("%s", &list->row[4][0]);		
		list = list->nextNum;
		if ( list != NULL ) 
			printf(" ");
	}
	printf("\n\n");
	return;
}/*}}}*/
int main(void)
{
	int length, i;
	int firsttime = 1;
	char num[10];
	NumberPtr List = NULL;
	while ( scanf("%d ", &length) && length != 0 )  {
		gets(num);
		List = NULL;
		for (i = 0; i <strlen(num) ; i++) {
			List = CreateNumberList(List, num[i]-48, length);		
		}
		Print(List, length);
		free(List);
	}


	return 0;
}

NumberPtr Generate(int length,int number){
	NumberPtr new = (NumberPtr)malloc(sizeof(Number));
	new -> nextNum = NULL;
	int i,j;
	for (j = 0; j < 5; j++) {
		for ( i = 0; i <= length + 1; i++) {
			new->row[j][i] = ' ';
		}
		new->row[j][length+2] = '\0';
	}

	if ( number == 1 ) {/*{{{*/
		new->row[1][length+1] = '|';
		new->row[3][length+1] = '|';
	}/*}}}*/
	else if ( number == 2 ) {/*{{{*/
		new->row[1][length+1] = '|';
		new->row[3][0] = '|';
		for (i = 1; i < length+1; i++) {
			new->row[0][i] = '-';
			new->row[2][i] = '-';
			new->row[4][i] = '-';
		}
	}/*}}}*/
	else if ( number == 3 ) {/*{{{*/
		new->row[1][length+1] = '|';
		new->row[3][length+1] = '|';
		for (i = 1; i < length+1; i++) {
			new->row[0][i] = '-';
			new->row[2][i] = '-';
			new->row[4][i] = '-';
		}
	}/*}}}*/
	else if ( number == 4 ) {/*{{{*/
		new->row[1][0] = '|';
		new->row[1][length+1] = '|';
		new->row[3][length+1] = '|';
		for (i = 1; i < length+1; i++) {
			new->row[2][i] = '-';
		}
	}/*}}}*/
	else if ( number == 5 ) {/*{{{*/
		new->row[1][0] = '|';
		new->row[3][length+1] = '|';
		for (i = 1; i < length+1; i++) {
			new->row[0][i] = '-';
			new->row[2][i] = '-';
			new->row[4][i] = '-';
		}
	}/*}}}*/
	else if ( number == 6 ) {/*{{{*/
		new->row[1][0] = '|';
		new->row[3][0] = '|';
		new->row[3][length+1] = '|';
		for (i = 1; i < length+1; i++) {
			new->row[0][i] = '-';
			new->row[2][i] = '-';
			new->row[4][i] = '-';
		}
	}/*}}}*/
	else if ( number == 7 ) {/*{{{*/
		new->row[1][length+1] = '|';
		new->row[3][length+1] = '|';
		for (i = 1; i < length+1; i++) {
			new->row[0][i] = '-';
		}
	}/*}}}*/
	else if ( number == 8 ) {/*{{{*/
		new->row[1][0] = '|';
		new->row[1][length+1] = '|';
		new->row[3][0] = '|';
		new->row[3][length+1] = '|';
		for (i = 1; i < length+1; i++) {
			new->row[0][i] = '-';
			new->row[2][i] = '-';
			new->row[4][i] = '-';
		}
	}/*}}}*/
	else if ( number == 9 ) {/*{{{*/
		new->row[1][0] = '|';
		new->row[1][length+1] = '|';
		new->row[3][length+1] = '|';
		for (i = 1; i < length+1; i++) {
			new->row[0][i] = '-';
			new->row[2][i] = '-';
			new->row[4][i] = '-';
		}
	}/*}}}*/
	else if ( number == 0 ) {/*{{{*/
		new->row[1][0] = '|';
		new->row[1][length+1] = '|';
		new->row[3][0] = '|';
		new->row[3][length+1] = '|';
		for (i = 1; i < length+1; i++) {
			new->row[0][i] = '-';
			new->row[4][i] = '-';
		}
	}/*}}}*/

	return new;
}
