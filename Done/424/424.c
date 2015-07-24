#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main(void)
{
	char in[105];
	int num[105]={0}, i, len, j;
	while ( 1 ) {
		gets(in);
		if ( (in[0] == '0') && (in[1] == '\0') ) {
			break;	
		}
		len = strlen( in );
		for (i = 0; i < len; i++) {
			num[i] += ((int)in[len-1-i]) - 48;
			j=i;
			while( num[j] > 9 ) {
				num[j+1]++;	
				num[j] -= 10;
				j++;
			}
			/*printf("i= %d num= %d\n",i, num[i]);*/
		}
	}
	for (i = 105; num[i] == 0; i--){
		len = i;	
	}
	for (i = 0; i < len; i++) {
		printf("%d", num[len-1-i]);
	}
	printf("\n");
	return 0;
}
