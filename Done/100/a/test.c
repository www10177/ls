#include<stdio.h>

int call(int,int);

int main(){
	int input1;
	int input2;
	int max;
	int n;
	int i;
	int j;
	int count=1;
	int k;
	int a[1000001];

    while(scanf("%d %d",&input1,&input2)!=EOF){
		printf("%d %d",input1,input2);
        j=input2;
		
		for(i=input1;i<=j;i++){	
			a[i]=call(i,count);
		}
		max=0;

		for(i=input1;i<=j;i++){
			if(a[i]>max){
				max=a[i];
			}
		}

		printf(" %d\n",max);
	
	
	}







	return 0;
}


int call(int i,int count){
    

    if(i==1){
		return count;
	}
	if((i%2)!=0){
		i=3*i+1;
		count=count+1;
		return call(i,count);
	}
	else{
		i=i/2;
		count=count+1;
		return call(i,count);
	}







}

