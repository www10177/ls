#include <stdio.h> 
#include <stdlib.h>
#include <ctype.h>
typedef struct _contestant {
	int problem[10];
	/*0 for not solve; control error times*/
	int problem_total;
	/*-1 for not use; 0 for solve zero problem*/
	int time;
}contestant; 

int isbigger(contestant,contestant, int);
int main(void)
{
	int case_num, i, count_part;
	for (scanf("%d\n\n",&case_num); case_num >0; case_num-- ) {
		contestant data[101];
		char data_cache[20];
		int participate_array[101];

		/*init*//*{{{*/
		for (i = 0; i <= 100; i++) {
			int j;
			for (j = 0; j < 10; j++) {
				data[i].problem[j] = 0;
			}
			data[i].problem_total= -1;
			data[i].time = 0;
			participate_array[i] = -1; 
		}
		count_part = 0;/*}}}*/

		while( gets(data_cache) != NULL ){
			if ( data_cache[0] == 0 ){
				break;	
			}
			int cont_num, problem_num, min ,count = 0;
			char status;

			/*get data*//*{{{*/
			cont_num = atoi(data_cache);
			for (; isdigit(data_cache[count]) ; count++) ;
			count++;
			problem_num = atoi(&data_cache[count]);
			for (; isdigit(data_cache[count]) ; count++) ;
			count++;
			min = atoi(&data_cache[count]);
			for (; isdigit(data_cache[count]) ; count++) ;
			count++;
			status = data_cache[count];/*}}}*/

			if ( status == 'R' || status == 'U' || status == 'E' ) {/*{{{*/
				if ( data[cont_num].problem_total== -1 ) {
					data[cont_num].problem_total= 0;
				}
			}/*}}}*/
			else if ( status == 'C' ) {/*{{{*/
				if ( data[cont_num].problem[problem_num] != 1 ) {
					if ( data[cont_num].problem[problem_num] < 0) 
						data[cont_num].time += 20 * ( 0 - data[cont_num].problem[problem_num]);	
					data[cont_num].problem[problem_num] = 1;
					if ( data[cont_num].problem_total== -1 ) 
						data[cont_num].problem_total= 1;
					else
						data[cont_num].problem_total++;
					data[cont_num].time += min;
				}
				/*printf("end %d %d %d\n", cont_num, data[cont_num].problem_total, data[cont_num].time);*/
			}/*}}}*/
			else if ( status == 'I' ) {/*{{{*/
				if ( data[cont_num].problem_total== -1 ) {
					data[cont_num].problem_total= 0;
					data[cont_num].problem[problem_num] -= 1;
				}
				else if ( data[cont_num].problem[problem_num] == 1) {
				}
				else if ( data[cont_num].problem[problem_num] <= 0 ){
					data[cont_num].problem[problem_num] --;
				}
			}/*}}}*/
		}

		for (i = 0; i <= 100; i++) {
			if ( data[i].problem_total != -1) {
				participate_array[count_part++] = i;

			}
		}
		int array_end = count_part;
		int j;
		/*for (i = 0; i < array_end; i++) {*/
			/*int index = participate_array[i];*/
			/*printf("%d %d %d %d\n",i , index, data[index].problem_total, data[index].time);*/
		/*}*/

		/*sort*/
		int index1, index2, index_level ;
		for (j = 0; j < array_end-1; j++) {
			for (i = 0; i < array_end-1-j; i++) {
				index1 = participate_array[i];
				index2 = participate_array[i+1];
				index_level= 0;
				if ( index1 > index2 ) {
					index_level= 1;	
				}
				if ( isbigger(data[index1], data[index2], index_level) == 1 ) {
					participate_array[i+1] = index1;
					participate_array[i] = index2;
				}
			}
		}
		for (i = array_end-1; i >= 0; i--) {
			int index = participate_array[i];
			printf("%d %d %d\n", index, data[index].problem_total, data[index].time);
		}
		if ( case_num != 1) {
			printf("\n");
		}
	}
	return 0;
}
int isbigger(contestant A,contestant B, int index_bigger){/*{{{*/
	if ( A.problem_total > B.problem_total ) 
		return 1;
	else if ( A.problem_total < B.problem_total ) 
		return -1;
	else if ( A.problem_total == B.problem_total ) {
		if ( A.time < B.time ){
			return 1;
		}
		else if ( A.time > B.time )
			return -1;
		else {
			if(index_bigger)
				return -1;
			else
				return 1;
		}
	}
}/*}}}*/
