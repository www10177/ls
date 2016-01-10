#include <stdio.h>

int main(void)
{
	int case_num, i, j, k, l,amp, fre;
	scanf("%d\n", &case_num);
	for (i = 0; i < case_num ; i++) {
		scanf("%d\n%d\n", &amp, &fre);
		for (j = 1; j <= fre ; j++) {
			l=1;
			while ( l <= amp) {
				for (k = 1; k <= l; k++) {
					printf("%d",l);
				}
				printf("\n");
				++l;
			}
			l -= 2;
			while ( l >= 1) {
				for (k = l; k >= 1; k--) {
					printf("%d",l);
				}
				printf("\n");
				--l;
			}
			if ( (i == case_num-1) && (j == fre) ) {
			}
			else
			printf("\n");
		}
	}

	return 0;
}
