#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define WC 12.01//the weight of Carbon
#define WH 1.008//the weight of Hygrogen
#define WO 16.00//the weight of Oxygen
#define WN 14.01//the weight of Nitrogen

float Calculate (char*,int);
int main(){
	int line;
	char input[100];
	float weight = 0.0;
	size_t i ;
	char *Ptr;
	int status = 0; // 1 for Carbon; 2 for Hydrogen; 3 for Oxygen; 4 for Nitrogen; 5 for numbers
	scanf ("%d\n",&line);
	for (line ; line>0 ; line--) {
		fgets (input,100,stdin);
		weight = 0.0;
		for (i=0 ; i<strlen(input)-1 ; i++ ) {
			Ptr  = &input[i];
			if ( input[i] == 'C' )
				status = 1;
			if ( input[i] == 'H' )
				status = 2;
			if ( input[i] == 'O' )
				status = 3;
			if ( input[i] == 'N' )
				status = 4;
			if ( isdigit(input[i]) )
				status = 5;
			if ( status != 5 )
				weight += Calculate (Ptr,status);
		}
		printf("%.3f\n",weight);
	}


	return 0;
}

#include <ctype.h>
float Calculate (char* in,int status){
	int number;
	number = atoi (in+1);

	if ( number == 0 )
		number = 1;
	if ( status == 1 )
		return number * WC;
	if ( status == 2 )
		return number * WH;
	if ( status == 3 )
		return number * WO;
	if ( status == 4 )
		return number * WN;
}
