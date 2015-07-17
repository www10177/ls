#include<stdio.h>
int main (){
int number;
	while((scanf("%d",&number)!=EOF)){
int counter;
float array[number];
for(counter=0;counter<number;counter++){
scanf("%f",&array[counter]);}
float average=0;
for(counter=0;counter<number;counter++){
	average+=array[counter];}
average=average/(float)number;
float exchange=0.00;
for(counter=0;counter<number;counter++){
	if(array[counter]>average)
	exchange+=(array[counter]-average);}
if(number!=0){printf("$%f\n",exchange);}
	}
return 0;
}
