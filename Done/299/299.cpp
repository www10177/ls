#include <iostream>
using namespace std;
int findIt(int* data, int key, int count){
	int location=0;;
	for (int i = key - 1; i < count  ; ++i) {
		if (data[i] == key ) {
			location = i;
			break;	
		}	
	}
	int temp = data[location];
	for (int i = location;i > key-1; i-- ) {
		data[i] = data[i-1];	
	}
	data[key-1] = temp;
	return location >key-1? location-key+1 : 0;
};
int main(void)
{
	int caseNum;
	cin >> caseNum;
	int count ;
	for (int i = 0; i < caseNum; ++i) {
		cin >> count;
		int* data = new int[count]; 	
		for (int j = 0; j< count; ++j) 
			cin >>data[j];	
		int back = 0;
		for (int counter = 0; counter < count ; counter++) {
			if (data[counter] != counter+1) {
				back += findIt(data,counter+1,count);	
			}
		}
		cout << "Optimal train swapping takes " << back << " swaps.\n";
	}
	return 0;
}
