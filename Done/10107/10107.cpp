#include <iostream>
#include <vector>

using namespace std;

int main(void)
{
	int count = 0;
	vector<int> data;
	int temp;
	while (cin >> temp){
		if (!data.size()) {
			data.push_back(temp);	
		}
		else if (temp <= data[0]) {
			data.insert(data.begin(),temp);	
		}
		else {
			int i=0;
			while(i+1<=(int)data.size()){	
			if(data[i]<=temp&&data[i+1]>=temp) {
				data.insert(data.begin()+i+1,temp);	
				goto END;
				}
			i++;
			}
			data.push_back(temp);
			
		}
END:count++;
		if (count%2) {
			std::cout << data[count/2] << std::endl;	
		}
		else {
			std::cout << (data[count/2-1]+data[count/2])/2 << std::endl;
		}
	}
	return 0;
}
