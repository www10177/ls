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
		weight= 0;
	}
	void clean(){
		weight = 0;
	}
};

bool sortFunction(Data A, Data B){
	if (A.weight == B.weight) 
		return A.id > B.id;
	return A.weight < B.weight;
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
		while(data.size() > 1){ 
			for (int i = 0; i < (int)data.size(); ++i) 
				data[i].clean();
			for (int i = 0; i < (int)data.size(); ++i) {
				for (int j = 0; j < (int)data.size(); ++j) {
					if (data[i].id != data[j].id ) 
						data[i].weight += data[i].fine * data[j].time; 
				}
			}
			sort(data.begin(), data.end(),sortFunction);
			//for (int i = 0; i < (int)data.size(); ++i) 
				//cout << "t " << data[i].id << " " << data[i].time << " " << data[i].fine << " " << data[i].weight<<endl;
			cout <<data.back().id << " " ;
			data.pop_back();
		}
		cout << data.back().id << endl<<endl;
		data.pop_back();
	}
	return 0;
}
