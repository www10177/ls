#include <stdio.h>

int main(void)
{
	int case_num, farmer, field, animal, coef, output = 0;
	scanf("%d\n", &case_num);
	for (; case_num>0; case_num--){
		scanf("%d\n", &farmer);
		output = 0;
		for (; farmer>0; farmer--){
		scanf("%d %d %d\n", &field, &animal, &coef);
		output += coef * field;
		}
		printf("%d\n", output);
	}
	return 0;
}
