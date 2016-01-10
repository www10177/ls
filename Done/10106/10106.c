#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main(void)
{
	int num1[255], num2[255], result[600]={0}, i, j;
	int len1, len2, len_result;
	char data_in[255];	
	while ( gets(data_in) != NULL) {

		/*init*//*{{{*/
		j=0;
		for (i = 0; i < 255; i++) {
			num1[i]=0;num2[i]=0;result[i]=0;
		}
		for (i = 255; i < 600; i++) {
			result[i] = 0;	
		}
		j=0;/*}}}*/

		/*special case*/
		if ( data_in[0] == '0' && data_in[1] == '\0') {
			gets(data_in);
			printf("0\n");
		continue;
		}
		/*convert num1*/
		for (i = strlen(data_in) - 1; i >= 0; i--) {
			num1[j] = (int)data_in[i] - 48; 	
			++j;
		}
		len1 = strlen(data_in);
		memset(data_in,'\0',255);

		/*convert num2*/
		j=0;
		gets(data_in);
		/*special case*/
		if ( data_in[0] == '0' && data_in[1] == '\0') {
			printf("0\n");
		continue;
		}
		for (i = strlen(data_in) - 1; i >= 0; i--) {
			num2[j] = (int)data_in[i] - 48; 	
			++j;
		}
		len2 = strlen(data_in);
		memset(data_in,'\0',255);
 
		/*multiple*/
		for (i = 0; i < len1; i++) {
			for (j = 0; j < len2; j++) {
				result[i+j] += num1[i] * num2[j];
				if ( result[i+j] / 10 > 0) {
					result[i+j+1] += result[i+j] / 10;
					result[i+j] = result[i+j] % 10;	
				}
			}
		}

		/*calculate result length*/
		len_result = len1 + len2 + 2;
		for (i = len_result; result[i] == 0 ; i--){
			len_result = i;
		}

		/*print result*/
		for (i = len_result-1; i >= 0; i--) {
			printf("%d", result[i]);
		}
		printf("\n");
	}
	return 0;
}
