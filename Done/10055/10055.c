#include <stdio.h>

int main(void)
{
	double a, b, c;
	while ( scanf("%lf %lf\n", &a, &b) != EOF) {
		c = a - b;
		if ( c < 0 ) {
			c *= -1;
		}
		printf("%.0lf\n", c);
	}
	return 0;
}
