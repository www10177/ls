#include <stdio.h>
int main(void)
{

	int i, j=6;
	char temp, temp1;
	printf("6\n");
	for(j=0;j<6;j++){
		for (i = 0; i < 1000000; i++) {
			temp = (123*i+64) % 26 + 65;
			printf("%c", temp);
		}
		printf("\n");
		printf("10000\n");
		for (i = 0; i < 10000; i++) {
			temp1 = i%26 +65;
			temp = (i +24) %26 +65;
			printf("%c %c\n", temp ,temp1);
		}
	}
	return 0;
}
