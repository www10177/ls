#include <stdio.h>

int collatz(long int, long int, int);

int main(void){
	long int data, limit;
	int case_num = 0;
	while ( scanf("%ld %ld\n", &data, &limit) != EOF) {
		if ( data < 0 ) {
			return 0;
		}
		printf( "Case %d: A = %ld, limit = %ld, number of terms = %d\n", ++case_num, data, limit, collatz(data, limit, 0) );
	}
}
int collatz(long int data, long int limit, int count){
	if ( data == 1) {
		return count + 1;
	}
	if ( data > limit ) {
		return count;
	}
	if ( !(data & (data-1)) ) {
		while ( !(data & 1)) {
			data = data >> 1;
			++count;
		}
		return count + 1;
	}
	if ( data & 1 ) {
		collatz(3*data+1, limit, count+1);
	}
	else{
		collatz(data>>1, limit, count+1);
	}
}
