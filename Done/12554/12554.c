#include <stdio.h>

int main(void)
{
	char song[17][15]={"",": Happy", ": birthday", ": to", ": you",": Happy", ": birthday", ": to", ": you",": Happy", ": birthday", ": to", ": Rujia",": Happy", ": birthday", ": to", ": you"};
	int i,j;
	char people[101][101];

	int people_num;
	scanf("%d\n",&people_num);
	for (i = 1; i <= 100 ; i++) {
		gets(&people[i][0]);
	}
	if (people_num <= 16) {
		j = 1;
		for (i = 1; ; i++) {
			if ( i > people_num ) 
				i = 1;
			if ( j > 16 ) 
				break;	
			printf("%s%s\n",&people[i][0], &song[j++][0]);
		}
	}
	else {
			int Times = people_num / 16;
			if ( people_num % 16 ) {
				Times ++;	
			}
			i = 1;
				j = 1;
			while ( Times > 0) {
					if ( i > people_num ) 
						i = 1;
					printf("%s%s\n",&people[i][0], &song[j++][0]);
					i++;
					if ( j > 16 ) {
						Times --;
						j = 1;
					}
			}
	}
	return 0;
}
