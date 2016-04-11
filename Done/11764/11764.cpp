#include <iostream>
#include <cstdio>
using namespace std;


int main(){
	int Case = 0, count;
	cin >> Case;
	for (int i = 0; i < Case; ++i) {
	cin >> count;
		cout << "Case " << i+1 << ": " ;
		int last , now;
		int highCount=0, lowCount=0;
			cin >> last ;
		for (int i = 1; i < count; ++i) {
			cin  >> now;
			if (now > last) 
				highCount ++;
			if (now < last) 
				lowCount++;
			last = now;
		}
		cout << highCount << " " << lowCount <<endl;

	}

	return 0;
}
