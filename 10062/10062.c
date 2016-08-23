#include "stdio.h"
#include "string.h"
#include "stdlib.h"
typedef struct _frequencydata{
	int character;
	int frequency;
}frequencyData;
int compare(const void *a, const void *b ){
	frequencyData *c = (frequencyData*)a;
	frequencyData *d = (frequencyData*)b;
	if (c->frequency !=  d->frequency) 
		return c->frequency > d->frequency ? 1:-1;	
	else
		return c->character < d->character ? 1:-1;

};

int main(void)
{
	frequencyData data[129];
	char temp[1001];
	int i;
	int flag  = 1;
	for (i = 0; i < 129; ++i) {
		data[i].frequency = 0;	
	}
	while(gets(temp) != NULL) {
		if (!flag ) 
			printf("\n");
		else
			flag = 0;		
		int i;
		for (i = 0; i < (int)strlen(temp); ++i) {
			data[(int)temp[i]].character = (int)temp[i];
			data[(int)temp[i]].frequency++;
		}
		qsort(data,129,sizeof(frequencyData),compare);
		for (i = 0; i < 129; ++i) {
			if (data[i].frequency != 0) {
				printf("%d %d\n", data[i].character, data[i].frequency);
				data[i].frequency = 0;
			}

		}

	}

	return 0;
}
