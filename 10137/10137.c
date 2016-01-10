#include <stdio.h>
#include <math.h>

int main(void)
{
	int num, number[1000], i;
	while ( 1 ) {
		scanf("%d\n ", &num) ;
		if ( num == 0 ){
			break;
		}
		int avg = 0;
		float temp;
		for (i = 0; i < num; i++) {
			scanf("%f\n", &temp);
			temp *= 100;
			number[i] = (int)temp;
			avg += number[i];
		}
			int exchange =0;
		if ( avg % num != 0) {
		avg = avg / num;
			for (i = 0; i < num; i++) {
				exchange += abs(number[i] - avg);
			}
			avg += 1;
			int exchange2 =0;
			for (i = 0; i < num; i++) {
				exchange2 += abs(number[i] - avg);
			}
			if ( exchange2 < exchange) {
			exchange = exchange2;	
			}
		}
		else{
		avg = avg / num;
			for (i = 0; i < num; i++) {
				exchange += abs(number[i] - avg);
			}
		}
			exchange /= 2;
			float temp2 = (float)exchange / 100;
			printf("$%.2f\n", temp2);
	}
	return 0;
}
