#include <iostream>
using namespace std;
int main(){
	int data1, data2;
	cin >> data1;
	while(cin >>data1 >> data2) {
		if (data1 == data2) {
			std::cout << "=" << std::endl;	
		}	
		else if (data1 >data2) {
			std::cout << ">" << std::endl;	
		}	
		else if (data1 <data2) {
			std::cout << "<" << std::endl;	
		}	
	}
return 0;
}
