#include<iostream>
#include<vector>
#include<queue>
using namespace std;
void bfs(int start,vector<int>& vis,vector<vector<int>>& adj){
	vis[start]=1;
	queue<int>q;
	q.push(start);
	
	while(!q.empty()){
		int v=q.front();
		q.pop();
		
		cout<<v<<" ";
		
		for(int i=0;i<adj[v].size();i++){
			int u=adj[v][i];
			if(!vis[u]){
				vis[u]=1;
				q.push(u);
			}
		}
	}
}

void dfs(int start,vector<int>& vis,vector<vector<int>>& adj){
	vis[start]=1;
	
	cout<<start<<" ";
	
	for(int i=0;i<adj[start].size();i++){
		int u=adj[start][i];
		if(!vis[u]){
			vis[u]=1;
			dfs(u,vis,adj);
		}
	}
}
int main(){
	int n,e,u,v;
	cout<<"Enter Number of Vertices"<<endl;
	cin>>n;
	
	cout<<"Enter Number of Edges"<<endl;
	cin>>e;
	
	vector<vector<int>>adj(n);
	cout<<"Enter Edges(u<-->v)"<<endl;
	for(int i=0;i<e;i++){
		cin>>u>>v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	
	for(int i=0;i<n;i++){
		cout<<i<<"-->";
		for(int j=0;j<adj[i].size();j++){
			cout<<adj[i][j]<<" ";
		}
		cout<<endl;
	}
	
int ch;
	
	do{
		cout<<"Enter Choice 1.BFS 2.DFS 3.Exit"<<endl;
			vector<int>vis(n,0);
		
		cin>>ch;
		
		switch(ch){
			case 1:
				int start;
				
				cout<<"Enter Start Node"<<endl;
				cin>>start;
				bfs(start,vis,adj);
				break;
			case 2:
				int start1;
				
				cout<<"Enter Start Node"<<endl;
				cin>>start1;
				dfs(start1,vis,adj);
				break;
				
			case 3:
				cout<<"Thank you!!"<<endl;
				break;
		}
	}while(ch!=3);
	
	

}
