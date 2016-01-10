#include <stdio.h>

int main(void)
{
	int i,count;
	int a, b;
	double ansA, ansB;
	scanf("%d\n", &count);
for (i = 0; i < count; ++i) {
	scanf("%d %d\n", &a, &b);
	ansA = a/2 + b/2;
	ansB = (a - b)/2;
	if (a%2 && b%2) {
		ansA++;	
	}
	if (ansB < 0 || (a+b)%2 ) {
		printf("impossible\n");	
	}
	else {
		printf("%.0lf %.0lf\n",ansA,  ansB);
	}
}
	
	return 0;
}
