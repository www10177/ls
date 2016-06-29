#include <stdio.h>
#include <string.h>
#include <ctype.h>
int Search(char (*table)[51], int row_now, int col_now, char* key, int row, int column, int direction){/*{{{*/
	/*1 up; 2 right; 3 down; 4 left; 9 for all; 5 for up left; 6 for up right; 7 for down left; 8 for down right*/
	int i;
	if ( direction == 9 ) {
		int status = 0;
		/*printf("row,col(%d,%d)\n", row_now+1, col_now+1);*/
		for (i = 8; i >0 ; i--) {
			status = Search(table, row_now, col_now, key, row, column, i);
			/*printf("i %d, status %d\n",i ,status);*/
			if ( status == 1 ) 
				return 1;	
		}
		return 0 ;
	}
	else if ( direction == 4 )  {
		if ( row_now + 1 < strlen(key)) {
			return 0;	
		}
		for (i = 0; i < strlen(key); i++) {
			if ( (tolower(key[i]) == table[row_now-i][col_now]) || (toupper(key[i]) == table[row_now-i][col_now]) ) {
			}
			else
				return 0;
		}
		return 1;
	}
	else if ( direction == 3 )  {
		if ( row - row_now + 1 < strlen(key)) {
			return 0;	
		}
		for (i = 0; i < strlen(key); i++) {
			if ( (tolower(key[i]) == table[row_now+i][col_now]) || (toupper(key[i]) == table[row_now+i][col_now]) ) {
			}
			else
				return 0;
		}
		return 1;
	}
	else if ( direction == 2 )  {
		if ( column - col_now + 1 < strlen(key)) {
			return 0;	
		}
		for (i = 0; i < strlen(key); i++) {
			if ( (tolower(key[i]) == table[row_now][col_now+i]) || (toupper(key[i]) == table[row_now][col_now+i]) ) {
			}
			else
				return 0;
		}
		return 1;
	}
	else if ( direction == 1 )  {
		if ( col_now + 1 < strlen(key)) {
			return 0;	}
		for (i = 0; i < strlen(key); i++) {
			if ( (tolower(key[i]) == table[row_now][col_now-i]) || (toupper(key[i]) == table[row_now][col_now-i]) ) {
			}
			else
				return 0;
		}
		return 1;
	}
	else if ( direction == 5 )  {
		if ( (row_now + 1 < strlen(key)) || (col_now + 1 < strlen(key)) ) {
			return 0;	
		}
		for (i = 0; i < strlen(key); i++) {
			if ( (tolower(key[i]) == table[row_now-i][col_now-i]) || (toupper(key[i]) == table[row_now-i][col_now-i]) ) {
			}
			else
				return 0;
		}
		return 1;
	}
	else if ( direction == 6 )  {
		if ( (row_now + 1 < strlen(key)) || (column - col_now + 1 < strlen(key)) ) {
			return 0;	
		}
		for (i = 0; i < strlen(key); i++) {
			if ( (tolower(key[i]) == table[row_now-i][col_now+i]) || (toupper(key[i]) == table[row_now-i][col_now+i]) ) {
			}
			else
				return 0;
		}
		return 1;
	}
	else if ( direction == 7 )  {
		if ( (row - row_now + 1 < strlen(key)) || (col_now + 1 < strlen(key)) ) {
			return 0;	
		}
		for (i = 0; i < strlen(key); i++) {
			if ( (tolower(key[i]) == table[row_now+i][col_now-i]) || (toupper(key[i]) == table[row_now+i][col_now-i]) ) {
			}
			else
				return 0;
		}
		return 1;
	}
	else if ( direction == 8 )  {
		/*printf("row%d col %d\n",row,column);*/
		/*printf("row%d col %d\n",row-row_now+1, column- col_now +1);*/
		/*printf("str%d\n",strlen(key));*/
		if ( (row - row_now  +1< strlen(key)) || (column- col_now + 1 < strlen(key)) ) {
			return 0;	
		}
		for (i = 0; i < strlen(key); i++) {
			if ( (tolower(key[i]) == table[row_now+i][col_now+i]) || (toupper(key[i]) == table[row_now+i][col_now+i]) ) {
			}
			else
				return 0;
		}
		return 1;
	}
}/*}}}*/
int main(void)
{
	int case_num, row, column, key_num, i, j, status;
	char table[51][51], key[51];
	scanf("%d\n", &case_num);
	for (case_num; case_num > 0 ; case_num --) {
		scanf("%d %d\n", &row, &column);
		for (i = 0; i < row; i++) {
			gets(&table[i][0]);	
		}
		scanf("%d\n", &key_num);
		for (key_num; key_num > 0 ; key_num--){
			gets(key);	
			status = 0;
			for (i = 0; i <  row; i++) {
				for (j = 0; j < column; j++) {
					/*printf("row %d, %d, key %c , table %c\n",i+1, j+1, key[0], table[i][j] );*/
					if ( (tolower(key[0]) == table[i][j]) || (toupper(key[0]) == table[i][j])) {
						status = Search(table, i, j, key, row, column, 9);
					}
					if ( status == 1) {
						printf("%d %d\n", i+1, j+1);
						break;
					}
				}
				if ( status == 1) 
					break;
			}
		}
		if (case_num != 1) 
			printf("\n");
	}
	return 0;
}
