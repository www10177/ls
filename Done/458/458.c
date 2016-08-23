#include <stdio.h>
#include <string.h>
int main(void)
{
char in[1000];
int i;
	while ( gets(in) != NULL) {
		i=0;
		while (in[i] != '\0') {
			printf("%c", in[i]-7);
			i++;
		}
		printf("\n");
	}
	return 0;
}
