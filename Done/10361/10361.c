#include <stdio.h>
#include <string.h>

int main(void)
{
	int case_num;
	char in[110], s1[110], s2[110], s3[110], s4[110];
	int i, j ;

	scanf("%d\n", &case_num);
	for (case_num; case_num >0 ; case_num--) {
		memset(s1,'\0',110);
		memset(s2,'\0',110);
		memset(s3,'\0',110);
		memset(s4,'\0',110);
		gets(in);
		/*line 1*/
		for (i = 0; in[i] != '\0'  ; i++) {
			if( in[i] == '<' ){
				++i;
				j=0;
				/*get s1*//*{{{*/
				while ( in[i] != '>') {
					printf("%c", in[i]);
					s1[j] = in[i];
					i++;j++;
				}
				i++;j=0;

				/*get s2*/
				while ( in[i] != '<') {
					printf("%c", in[i]);
					s2[j] = in[i];
					i++;j++;
				}
				i++;j=0;

				/*get s3*/
				while ( in[i] != '>') {
					printf("%c", in[i]);
					s3[j] = in[i];
					i++;j++;
				}
				i++;j=0;

				/*get s4*/
				while ( in[i] != '\0') {
					printf("%c", in[i]);
					s4[j] = in[i];
					i++;j++;
				}
				printf("\n");
				break;/*}}}*/
			}
			else{
				printf("%c", in[i]);
			}
		}

		/*line 2*/
		gets(in);
		for (i = 0; in[i] != '.'  ; i++) {
				printf("%c", in[i]);
		}
		printf("%s%s%s%s\n", s3, s2, s1, s4);
	}
	return 0;
}
