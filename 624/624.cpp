#include <iostream>
#include <algorithm>

int _qsort(const void*a, const void*b){
	int a1 = *(int*)a;
	int a2 = *(int*)b;
	if (a1 >a2) return -1;
	else if(a1==a2) return 0;
	else  return 1;
}
using namespace std;

int main(void)
{
	int sum, count ;
	while(cin >>sum){
		std::cout << "case" << std::endl;
		cin >> count ;
		int* num = new int(count);
		for (int i = 0; i < count ; ++i) {
			cin >> num[i]; 	
		}

		qsort(num,count,sizeof(int),_qsort);
		for (int i = 0; i < count; ++i) {
			std::cout << num[i]<<" " 	;
		}
		std::cout <<  std::endl;
	}
	return 0;
}
