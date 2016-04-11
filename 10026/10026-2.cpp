#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
struct Data{
	int id;
	int time;
	int fine;
	int weight;
	Data(int iid, int itime, int ifine):id(iid), time(itime), fine(ifine){
	}
};

bool sortFunction(Data A, Data B){
	if (A.time * B.fine ==  B.time * A.fine) 
		return A.id > B.id;
	return A.time * B.fine> B.time * A.fine;
}

int main(void)
{
	int caseNum = 0, lineNum;
	cin  >> caseNum;

	for (int iC = 0; iC < caseNum; ++iC) {
		cin  >> lineNum;
		std::vector<Data> data;
		for (int i = 0; i < lineNum; ++i) {
			int time, fine;
			cin >> time >> fine;
			data.push_back(Data(i+1,time,fine) );
		}
		sort(data.begin(), data.end(),sortFunction);
		while(data.size() > 1){ 
			//for (int i = 0; i < (int)data.size(); ++i) 
			//cout << "t " << data[i].id << " " << data[i].time << " " << data[i].fine << " " << data[i].weight<<endl;
			cout <<data.back().id << " " ;
			data.pop_back();
		}
		if(iC == caseNum -1 )
			cout << data.back().id << endl ;
		else
			cout << data.back().id << endl << endl;
		data.pop_back();
	}
	return 0;
}
