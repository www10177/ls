#include<stdio.h>

long int calculate(int in,long int count){
	if(in==1){
		return count;
	}
	else{
		if(in%2){
			in=3*in+1;
			count++;
		}
		else{
			in=in/2;
			count++;
		}
		return calculate(in,count);
	}
}
int main(){
	int a,b;
	int max=0;
	int cache;
	long int count=1;
	while((scanf("%d %d",&a,&b))!=EOF){
		printf("%d %d ",a,b);
		int i;
		if(a>b){
			i=a;
			a=b;
			b=i;
		}
		for(a;a<=b;a++){
			cache=calculate(a,count);
			if (max<cache)
				max=cache;
		}
		printf("%d\n",max);
		max=0;

	}
	return 0;
}
