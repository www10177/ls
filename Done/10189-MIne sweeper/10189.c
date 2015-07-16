#include <stdio.h>

int main(void)
{
	int row , column;
	char data[102][102];
	int out[102][102];
	int i , j ;
	int count=1;
	while ( scanf("%d %d\n", &row, &column)  ){
		if ( (row == 0) && (column == 0) ) {
			break;
		}
		else{	
			if (count ==1) {
			printf("Field #%d:\n",count);
			count++;
			}
			else{
			printf("\nField #%d:\n",count);
			count++;
			}
			for (i = 1; i <=row ; i++) {
				for (j = 1; j <= column; j++) {
					scanf("%c",&data[i][j]);
					if ( data[ i ][ j ] == '*' ) {
						out[ i ][ j ] = -99;
						out[ i-1 ][ j-1 ] += 1;
						out[ i-1 ][ j ] += 1;
						out[ i-1 ][ j+1 ] += 1;
						out[ i ][ j-1 ] += 1;
						out[ i ][ j+1 ] += 1;
						out[ i+1 ][ j-1 ] += 1;
						out[ i+1 ][ j ] += 1;
						out[ i+1 ][ j+1 ] += 1;
					}
				}
				scanf("\n");
			}
			for (i = 1; i <= row; i++) {
				for	(j = 1; j <= column; j++){
					if(out[ i ][ j ] < -50 )
						printf("*");
					else
						printf("%d",out[ i ][ j ]);
				}	
				printf("\n");
			}
			for (i = 0; i <= 101; i++) {
				for (j = 0; j <= 101; j++){
					out[ i ][ j ] = 0;
					data[ i ][ j ] = '.';
				}	
			}
		}
	}	
	return 0;
}
