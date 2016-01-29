#include <iostream>
#include <vector>
using namespace std;
class Block{
	private:
		vector<int> blockPile;
		int initValue;
	public:
		void init (int serial){
			blockPile.reserve(25);
			blockPile.clear();
			addBlock(serial);
			initValue = serial;
		};
		void init(){
			blockPile.clear();
			addBlock(initValue);
		}
		int search(int target){
			for (int i = 0; i < (int)blockPile.size(); ++i) {
				if ( blockPile[i] == target ) {
					return i;
				}	
			}
			return -1;
		};
		vector<int> takeOut(int target){
			int i = 0;
			vector<int>  backVector;
			i = search(target);
			for (; i <  (int)blockPile.size(); i++) {
				backVector.push_back(blockPile[i]);
			}
			return backVector;
		};
		void print(){
			cout  << initValue << ":";
			for (int i = 0; i < (int)blockPile.size(); ++i) {
				cout <<  " " << blockPile[i] 	;
			}
			cout << endl;
		};
		void addBlock(int block){
			blockPile.push_back(block);	
		};
		void addBlockPile(vector<int> blockPile){
			for (int i = 0; i < (int)blockPile.size(); ++i) {
				addBlock(blockPile[i]);
			}
		};
};
int findBlock(Block*, int, int);
int main(void)
{
	int blockSize = 0;
	cin >> blockSize;
	string arg1, arg2;
	int sub1, sub2, i;
	int sub1Pile, sub2Pile;
	Block* blockWorld = new Block[blockSize];
	for (i = 0; i < blockSize; ++i) {
		blockWorld[i].init(i);		
	}
	while(cin >> arg1 >> sub1 >> arg2 >> sub2 ){
		cout << arg1 <<endl << sub1 <<endl << arg2 <<endl << sub2 <<"\n\n" ;
		vector<int> transportBlockPile;
		if ( arg1 == "move" ) {
			if ( arg2 == "onto") {
				cout << "in\n";
				sub1Pile = findBlock(blockWorld, blockSize, sub1);	
				cout << "70\n";
				sub2Pile = findBlock(blockWorld, blockSize, sub2);	
				cout << "72\n";
				transportBlockPile = blockWorld[sub1Pile].takeOut(sub1);
				cout << "74\n";
				blockWorld[sub2Pile].addBlock(sub1);
				cout << "76\n";
				for (int  j= 0;  j< (int)transportBlockPile.size(); j++) {
					blockWorld[transportBlockPile[j]].init();
				}
				transportBlockPile.clear();
				transportBlockPile = blockWorld[sub2Pile].takeOut(sub2);
				blockWorld[sub2Pile].addBlock(sub1);
				for (int  j= 0;  j< (int)transportBlockPile.size(); j++) {
					blockWorld[transportBlockPile[j]].init();
				}
			}	
		}
	}
		for (i = 0; i < blockSize ; ++i) {
				blockWorld[i].print();
		}
	return 0;
}
int findBlock(Block* base, int size, int target){/*{{{*/
	if ( base[target].search(target) >0 ) {
		return target;			
	}
	for (int i = 0; i < size; ++i) {
		if ( base[i].search(target) >0 ) {
			return i;			
		}
	}
	return -1;
}/*}}}*/
