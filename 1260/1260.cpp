#include <iostream>
using namespace std;

int main(){
	int loop ;
	int* data ;
	cin >> loop;
	while(loop--) {
		int size;
		cin >>size;
		 data = new int[size];
		int answer = 0;
		for (int i = 0; i < size; ++i) {
			cin>>data[i];
			for (int j = i-1;j>=0;j--)  {
				if (data[i] >= data[j]) {
					answer++;	
				}	
			}
		}
		delete data;
		cout <<answer <<endl;
	}
	return 0;
}
