#include <stdio.h>

int lower(int sum, int num, int count) {
	return count +( ( num - sum) * 2 );
}

int higher(int sum, int num, int count) {
	int difference = num - sum;
	if ( difference & 1) {
		if ( (count + 1 - difference) & 1) {
		return count + 2;
		}
		return count + 1;
	}
	else{
		return count;
	}
}
int main(void)
{
	int case_num, i, num, count, j, sum, previous, cache;
	scanf("%d", &case_num);
	for ( ; case_num > 0; case_num--) {
		scanf("%d", &num);
		if ( num < 0 ) {
			num *= -1;
		}
		sum = 0;count = 0;
		for (i = 1; sum < num; i++ ){
			count++;
			sum += i;
		}
		previous = sum - i +1;
		/*printf("%d %d %d\n", previous, sum, count);*/
		if ( sum == num ){
			/*printf("!pr%d nu%d cou%d\n", previous, num, count);*/
		}
		else{
			/*printf("pr%d nu%d cou%d\n", sum, num, count);*/
			cache = lower(previous, num, count-1);
			/*printf("lower%d\n\n", cache);*/
			count = higher(sum, num, count);
			/*printf("higher%d\n\n", count);*/
			if ( cache < count) {
				count = cache;	
			}
		}
		if ( num == 0 ) {
			count = 3;
		}
		if ( case_num <= 1 ) {
			printf("%d\n", count);
		}
		else{
			printf("%d\n\n", count);
		}
	}
	return 0;
}
