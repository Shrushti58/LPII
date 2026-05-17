#include<iostream>
#include<vector>
#include<queue>
using namespace std;

void prims(int n,int source,vector<vector<pair<int,int>>>adj){
	vector<int>vis(n,0);
	priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>pq;
	pq.push({0,{source,-1}});
	int sum=0;
	while(!pq.empty()){
		int wt=pq.top().first;
		int node=pq.top().second.first;
		int parent=pq.top().second.second;
		pq.pop();
		
		if(vis[node!=0]){
			continue;
		}
		vis[node]=1;
		sum=sum+wt;
		if(parent!=-1){
			cout<<parent<<"-->"<<node<<endl;
		}
		
		for(int i=0;i<adj[node].size();i++){
			int negh=adj[node][i].first;
			int edgewt=adj[node][i].second;
			if(!vis[negh]){
				pq.push({edgewt,{negh,node}});
			}
		}
		
	}
	
	cout<<sum<<endl;
}
int main(){
	int n,e,v,u,w;
	
	cout<<"Enter number of vertices"<<endl;
	cin>>n;
	
	cout<<"Enter number of edges"<<endl;
	cin>>e;
	
	vector<vector<pair<int,int>>>adj(n);
	
	cout<<"Enter (u-v-w)"<<endl;
	for(int i=0;i<e;i++){
		cin>>u>>v>>w;
		adj[u].push_back({v,w});
		adj[v].push_back({u,w});
	}
	
	cout<<"Adj List"<<endl;
	
	for(int i=0;i<n;i++){
		cout<<i<<"-->";
		for(auto it:adj[i]){
			cout<<"{"<<it.first<<","<<it.second<<"}";
		}
		cout<<endl;
	}
	
	prims(n,0,adj);
}
