#include "stdio.h"

int main(void)
{
	int height, drop, fatigue, day;
	float distanceNow, distancePerDay, distanceDropPerDay;


	while (scanf("%d %f %d %d", &height, &distancePerDay, &drop, &fatigue) && height != 0){
		day = 1;
		distanceNow = 0;		
			distanceDropPerDay = distancePerDay*(float)fatigue/100;
		while (distanceNow <= (float)height && distanceNow >= 0) {
			if (distancePerDay > 0) {
			distanceNow += distancePerDay;
			}
			distancePerDay -= distanceDropPerDay;
			if (distanceNow > (float)height) 
				break;	
			distanceNow -= drop;
			if (distanceNow < 0 ) 
				break;	
			/*printf("Day %d, Total %d, now  %.1f per %.1f \n", day, height, distanceNow, distancePerDay);	*/
			day++;
		}
		if (distanceNow >= height) 
			printf("success on day %d\n", day);	
		else 
			printf("failure on day %d\n", day);	
	}

	return 0;
}
