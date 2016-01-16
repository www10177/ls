#include<stdio.h>
int calculate(int in){
	int count = 1;
	while( in!=1 ){
		if( in&1 ){
			in = 3 * in + 1;
			count++;
		}
		else{
			in=in >> 1;
			count++;
		}
	}
	return count;
}
int main(){
	int a,b,c;
	int value=0;
	int cache;
	while((scanf("%d %d",&a,&b))!=EOF){
		printf("%d %d ",a,b);
		if ( a > b ) {
			c = a; a = b; b = c;	
		}
		for (; a <=b  ; a++) {
			cache=calculate(a);
			value = (cache > value ? cache : value);
		}
		printf("%d\n",value);
		value = 0;
	}
	return 0;
}
