#include<iostream>
#include<vector>
#include<queue>
using namespace std;
vector<int> dj(int n,int source,vector<vector<pair<int,int>>>adj){
	vector<int>result(n,INT_MAX);
	
	result[source]=0;
	priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
	pq.push({0,source});
	
	while(!pq.empty()){
		int dist=pq.top().first;
		int node=pq.top().second;
		pq.pop();
		for(int i=0;i<adj[node].size();i++){
			int neigh=adj[node][i].first;
			int wt=adj[node][i].second;
			
			if(dist+wt<result[neigh]){
				result[neigh]=dist+wt;
				pq.push({dist+wt,neigh});
			}
		}
		
	}
			return result;

}
int main(){
	int n,e,u,v,w;
	cout<<"Enter number of vertices"<<endl;
	cin>>n;
	
	cout<<"Enter number of Edges"<<endl;
	cin>>e;
	
	vector<vector<pair<int,int>>>adj(n);
	
	cout<<"Enter edges (u,v,w)"<<endl;
	
	for(int i=0;i<n;i++){
		cin>>u>>v>>w;
		adj[u].push_back({v,w});
	}
	
	for(int i=0;i<n;i++){
		cout<<i<<"-->";
		for(auto it:adj[i]){
			cout<<"{"<<it.first<<","<<it.second<<"}";
		}
		cout<<endl;
	}
	
	vector<int>res=dj(n,0,adj);
	
	cout<<"Shortest Distance from Source 0 -"<<endl;
	
	for(int i=0;i<n;i++){
		cout<<0<<" to "<<i<<" "<<res[i]<<endl;
	}
}
