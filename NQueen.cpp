#include<iostream>
#include<vector>
#include<unordered_set>
using namespace std;
vector<vector<string>>result;

void solve(vector<string>& board,int row,unordered_set<int>& cols,unordered_set<int>& digs,unordered_set<int>& antidig){
	int n=board.size();
	if(n==row){
		result.push_back(board);
		return;
	}
	
	for(int col=0;col<n;col++){
		int dign=row-col;
		int adig=row+col;
		
		if(cols.count(col) || digs.count(dign) || antidig.count(adig)){
			continue;
		}
		
		board[row][col]='Q';
		cols.insert(col);
		digs.insert(dign);
		antidig.insert(adig);
		
		solve(board,row+1,cols,digs,antidig);
		
			board[row][col]='.';
		cols.erase(col);
		digs.erase(dign);
		antidig.erase(adig);
		
	}
}
int main(){
	int n=4;
	vector<string>board(n,string(n,'.'));
	unordered_set<int>cols,digs,antidig;
	
	solve(board,0,cols,digs,antidig);
	
	for(auto sol:result){
		for(auto it:sol){
			cout<<it<<endl;
		}
		cout<<endl;
	}
}
