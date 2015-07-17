#include<stdio.h>
#include<math.h>
int main (){
	int number;//student number
	while((scanf("%d",&number)!=EOF)){
		int counter;
		float array[number];///to store expense of every student
		for(counter=0;counter<number;counter++){
			scanf("%f",&array[counter]);}
		float average=0;//the average of the costs
		for(counter=0;counter<number;counter++){
			average+=array[counter];}
		average=average/(float)number;
		float exchange=0.00;//the minimum money they need to chage
		for(counter=0;counter<number;counter++){
			if(array[counter]>average)
				exchange+=(array[counter]-average);}
			int cache=(int)(average*1000);
			int cache2=(int)(average*100)*10;
			if(cache-cache2>0)
			exchange-=0.01;

		if(number!=0){printf("$%.2f\n",exchange);
		}
		}//end while
	}//end main
