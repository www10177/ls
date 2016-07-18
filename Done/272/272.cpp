#include <iostream>
#include <cstdio>

using namespace std;

int main(void)
{
	char in;
	int flag=0;
	while (scanf("%c", &in) != EOF) {
		if (in == '\"') {
			if (flag) {
				cout << "\'\'";	
				flag = 0;
			}
			else {
				cout << "``";	
				flag = 1;	
			}
		}	
		else
		cout << in;
	}
	return 0;
}
