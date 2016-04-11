#include <stdio.h>
#include <stdlib.h>
int cmp(const void *a, const void *b){
	return *(int*)a - *(int*)b; 
}
int Find(int *marbles, int marbles_num, int Q){
	int i ;
	for (i = 0; i < marbles_num; i++) {
		if ( Q == marbles[i] ) {
			return i;	
		}
		else if ( Q < marbles[i] ) {
			return -1;	
		}
	}
	return -1;	
}	
int main(void)
{
	int marbles_num, queries_num;
	int marbles[10002], query, i, case_num = 1;
	while ( scanf("%d %d", &marbles_num, &queries_num ) ) {
		if  ( marbles_num == 0 || queries_num == 0) {
			return 0 ;
		}
		for (i = 0; i < marbles_num; i++) {
			scanf("%d", &marbles[i]);	
		}
		qsort(marbles, marbles_num, sizeof(int), cmp);
		/*for (i = 0; i < marbles_num; i++) {*/
		/*printf("%d ", marbles[i]);*/
		/*}*/
		/*printf(" \n");*/
		printf("CASE# %d:\n", case_num++);
		for (i = 0; i < queries_num; i++) {
			scanf("%d", &query);
			int location = Find(marbles, marbles_num, query);
			if ( location == -1) {
				printf("%d not found\n", query);
			}
			else{
				printf("%d found at %d\n", query, location+1);
			}
		}
	}
}
