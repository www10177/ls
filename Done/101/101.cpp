#include <iostream>
#include <vector>
using namespace std;
class Block{/*{{{*/
	private:
		vector<int> blockPile;
		int initValue;
	public:
		Block(){
			blockPile.reserve(25);
		}
		Block(int initValue){
			blockPile.push_back(initValue);
			this->initValue = initValue;
			blockPile.reserve(25);
		}
		void clean(){
			blockPile.clear();
		}
		void clean(int value){
			for (int i = (int) blockPile.size()-1; i > search(value); --i) {
				blockPile.pop_back();
			}

		};
		void pop(){
			blockPile.pop_back();
		}
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
		vector<int> takeOut(){
			return blockPile;
		}
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
		void addBlockPile(vector<int> iblockPile){
			for (int i = 0; i < (int)iblockPile.size(); ++i) {
				blockPile.push_back(iblockPile[i]);
			}
		};
};/*}}}*/
int findBlockPile(vector<Block>, int, int);
int main(void)
{
	int blockSize = 0;
	cin >> blockSize;
	vector<Block> blockWorld;
	string arg1, arg2;
	string clean_str;
	int sub1, sub2, i;
	int sub1Pile, sub2Pile;
	for (i = 0; i < blockSize; ++i) {
		blockWorld.push_back(Block(i));
	}
	while(cin >> arg1 >> sub1 >> arg2 >> sub2 ){
		getline(cin,clean_str);
		vector<int> transportBlockPile;
		transportBlockPile.clear();
		sub1Pile = findBlockPile(blockWorld, blockSize, sub1);	
		sub2Pile = findBlockPile(blockWorld, blockSize, sub2);	
		/*std::cout << "sub: " << sub1Pile << ", " << sub2Pile << std::endl;*/
		transportBlockPile = blockWorld[sub1Pile].takeOut(sub1);
		/*std::cout << arg1 << sub1 << arg2 << sub2 << std::endl;*/
		if ( (sub1 == sub2) || (sub1Pile == sub2Pile ) );
		else if ( arg1 == "move" ) {
			/*init*/
			for (i = (int)transportBlockPile.size()-1; i>0;i--) {
				blockWorld[transportBlockPile[i]].init();
			}
			if ( arg2 == "over") {/*{{{*/
				blockWorld[sub1Pile].clean(sub1);
				blockWorld[sub1Pile].pop();
				for (int i = 1; i < (int)transportBlockPile.size(); ++i) {
					blockWorld[transportBlockPile[i]].init();
				}
				blockWorld[sub2Pile].addBlock(sub1);
			}	/*}}}*/
			else if (arg2 == "onto" ) {/*{{{*/
				for (int i = 1; i < (int)transportBlockPile.size(); ++i) {
					blockWorld[transportBlockPile[i]].init();
				}
				blockWorld[sub1Pile].clean(sub1);
				blockWorld[sub1Pile].pop();
				transportBlockPile.clear();
		transportBlockPile = blockWorld[sub2Pile].takeOut(sub2);
				 blockWorld[sub2Pile].clean(sub2);
				for (int i = 1; i < (int)transportBlockPile.size(); ++i) {
					blockWorld[transportBlockPile[i]].init();
				}
				blockWorld[sub2Pile].addBlock(sub1);
			}/*}}}*/
		}
		else if ( arg1 == "pile" ) {
			if ( arg2 == "over") {/*{{{*/
				/*std::cout << "pile " << sub1 << " over " << sub2 << std::endl;*/
				blockWorld[sub1Pile].clean(sub1);
				blockWorld[sub1Pile].pop();
				blockWorld[sub2Pile].addBlockPile(transportBlockPile);
				/*std::cout << 119 << std::endl;*/
			}	/*}}}*/
			else if (arg2 == "onto" ) {/*{{{*/
		transportBlockPile = blockWorld[sub2Pile].takeOut(sub2);
				blockWorld[sub2Pile].clean(sub2);
				for (int i = 1; i < (int)transportBlockPile.size(); ++i) {
					blockWorld[transportBlockPile[i]].init();
				}
		transportBlockPile = blockWorld[sub1Pile].takeOut(sub1);
				blockWorld[sub2Pile].addBlockPile(transportBlockPile);
				blockWorld[sub1Pile].clean(sub1);
				blockWorld[sub1Pile].pop();
			}/*}}}*/
		}
		else if (arg1 == "quit") {
			/*std::cout << "quit" << std::endl;*/
			break;	
		}
		/*std::cout << "end" << std::endl;*/
	}
	for (i = 0; i < blockSize ; ++i) {
		blockWorld[i].print();
	}
	return 0;
}
int findBlockPile(vector<Block> base, int size, int target){/*{{{*/
	for (int i = 0; i < (int)base.size(); ++i) {
		if ( base[i].search(target) >=0 ) {
			return i;			
		}
	}
	return -1;
}/*}}}*/
