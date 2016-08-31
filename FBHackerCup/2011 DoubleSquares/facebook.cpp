#include<iostream>
#include<cmath>

using namespace std;
bool isPerfect(int in){
	int sqt = (int)sqrt((double)in);
	if(sqt*sqt == in)
		return true;
	return false;
}
int main(){
	int caseNum = 0;
	cin >> caseNum ;
	int casei =1;
	while (caseNum--){
		int data; 
		int count = 0;
		cin >>data;
		int mid=(int)sqrt((double)data);
		for (int i = 0; i<=mid;i ++){
			int i2 = i*i;
			int targetValue= data-i2;
			if(isPerfect(targetValue) && targetValue != i2){
				count++;
			}
		}
		cout <<"Case #"<<casei++<<": " << count/2<<endl;
	}
	return 0;
}
