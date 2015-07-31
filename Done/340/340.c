#include <stdio.h>

int main(void)
{
	int game_count = 1;
	int length, secret[1000], secret_ori[1000], guess[1000];
	int ans_A, ans_B, i, j;
	while ( scanf("%d\n", &length) ) {
		if ( length == 0) {
			return 0;
		}
		for (i = 0; i < length; i++) {
			scanf("%d", &secret[i]);	
			secret_ori[i] = secret[i];
		}
		printf("Game %d:\n", game_count++);
		while(1){
			for (i = 0; i < length; i++) {
				scanf("%d", &guess[i]);	
			}

			/*for (i = 0; i < length; i++) {*/
				/*printf("%d ", guess[i]);*/
			/*}*/
			/*printf(" \n");*/

			if ( guess[0] == 0 ) 
				break;
			for (i = 0; i < length; i++) {
				if ( guess[i] == secret[i]) {
				guess[i] += 20; secret[i] += 10;	
				ans_A ++;
				}
			}
			for (i = 0; i < length; i++) {
				if ( guess[i]  > 10 ) {
					continue;	
				}
				for (j = 0; j < length; j++) {
						if ( j == i || secret[j] > 10) {
						continue;	
						}
						if ( secret[j] == guess[i]) {
							secret[j] += 320;
							guess[i] += 130;
							ans_B++;
							break;
						}
				}
			}
			printf("    (%d,%d)\n", ans_A, ans_B );
			ans_A = 0; ans_B = 0;
			for (i = 0; i < length; i++) {
				secret[i] = secret_ori[i];
			}
		}
	}
}
