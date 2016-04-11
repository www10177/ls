#include <stdio.h>

int main(void)
{
	int in;
		int count = 0;;
	while (scanf("%d\n", &in) != EOF) {
		while (1) {
		if (in == 1) {
			printf("%d,", count+1);	
		count = 0;
		break;
		}
		else if (in % 2) {
			in  = 3* in + 1;
		}
		else {
			in /= 2;	
		}
		count += 1;
		}
	}	
	return 0;
}
