#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int main(void)
{
	string data;
	int SuccessorFlag = 0;
	while (cin >> data) {
		if (data == "#") {
			break;	
		}
		SuccessorFlag = 0;
		int remainedDigit = 0;
		for (int i = 0; i+1 <(int) data.size(); ++i) {
			if (data[i] <data[i+1]) {
				SuccessorFlag =1;
				break;
			}	
		}
		if (SuccessorFlag == 1) {
			for (int i = data.size()-1; i >= 0 ; i--) {
				if (data[i] > data[i-1]) {
					remainedDigit = i-1 - 1;	
					break;
				}	
			}
			string subData = data.substr(remainedDigit +1);
			char biggerThanThisChar = subData[0];
			sort(subData.begin(), subData.end() );
			/*sort end*/

			//std::cout << "substr : " << subData<<std::endl;
			for (int i = 0; i < (int)subData.length(); ++i) {
				if (subData[i] > biggerThanThisChar) {
					char subCache = subData[0];
					subData[0] = subData[i];
					subData[i] = subCache;;
					sort(subData.begin()+1, subData.end());
					break;
				}
			}
			//std::cout << "drbug " << "substr: " << subData << " digit : " << remainedDigit << std::endl;
			cout<<data.substr(0, remainedDigit+1 ) << subData << endl;

		}
		else if (SuccessorFlag == 0) {
			cout << "No Successor" << endl;	
		}

	}
	return 0;
}
