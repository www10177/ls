#include <stdio.h>
#define DAY 50
void calculate(int*, const int*);
void PRINT(int*);
int main(void)
{
	int case_num, DNA[10], cell[42];
	int i;
	scanf("%d\n", &case_num) ;
	for (case_num; case_num > 0 ; case_num--) {
		for (i = 1; i <= 40; i++) {
			cell[i] = 0;	
		}
		cell[20] = 1;cell[0] = 0;cell[41] = 0;

		scanf("\n");
		for (i = 0; i < 10; i++) {
			scanf("%d", &DNA[i]);
		}

		for (i = 0; i < DAY; i++) {
			PRINT(cell);
			calculate(cell, DNA);
		}
		if ( case_num == 1) {
			
		}else
		printf("\n");
	}
	return 0;
}
void calculate( int* cell, const  int* DNA ){
	int i, index_temp, cell_temp[42];
	for (i = 1; i <= 40; i++) {
		index_temp = cell[i-1] + cell[i] + cell[i+1];
		cell_temp[i] = DNA[index_temp];
	}
	for (i = 1; i <= 40; i++) {
		cell[i]= cell_temp[i];
	}
	return;
}
void PRINT(int* cell){
	int i;
	for (i = 1; i <= 40; i++) {
		if ( cell[i] == 0) {
			printf( " ");
		}
		else if ( cell[i] == 1) {
			printf( ".");
		}
		else if ( cell[i] == 2) {
			printf( "x");
		}
		else if ( cell[i] == 3) {
			printf( "W");
		}
	}
	printf("\n");
	return;
}
