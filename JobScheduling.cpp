#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class job{
	public:
		int id;
		int profit;
		int deadline;
		job(int i,int pro,int dead){
			id=i;
			profit=pro;
			deadline=dead;
		}
};

bool compare(job a,job b){
	return a.profit>b.profit;
}

class demo{
	public:
		void jobscheduling(vector<job> jobs){
			sort(jobs.begin(),jobs.end(),compare);
			
			int maxdeadline=0;
			
			for(auto job:jobs){
				maxdeadline=max(maxdeadline,job.deadline);
			}
			
			vector<int>slots(maxdeadline+1,-1);
			int profit=0;
			for(int i=0;i<jobs.size();i++){
				for(int j=jobs[i].deadline;j>0;j--){
					if(slots[j]==-1){
						slots[j]=i;
						profit=profit+jobs[i].profit;
						break;
					}
				}
			}
			
			cout<<"Selected Jobs"<<endl;
			
			for(int i=0;i<=maxdeadline;i++){
				if(slots[i]!=-1){
					cout<<jobs[slots[i]].id<<endl;
				}
			}
		}
};
int main(){
	vector<job>jobs;
	int n=0;
	cout<<"Enter number of jobs"<<endl;
	cin>>n;
	
	cout<<"Enter id,profit and deadline for each job"<<endl;
	int id,pro,dead;
	
	for(int i=0;i<n;i++){
		cin>>id>>pro>>dead;
		jobs.push_back(job(id,pro,dead));
	}
	
	demo d;
	d.jobscheduling(jobs);
}
