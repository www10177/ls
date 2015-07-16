#include<stdio.h>
#include<string.h>

int main(){
	int line,out;
	int i,value;
	char in [100];
	scanf ( "%d\n",&line );
	for ( line ; line>0 ; line-- ) {
		value=1;
		out=0;
		fgets ( in,100,stdin );
		for ( i=0;i<strlen(in);i++ ) {
			if ( in[i]== 'O' ) {
				out+=value;
				value+=1;
			}
			else
				value=1;
		}

	printf("%d\n",out);
	}

	return 0;
}
