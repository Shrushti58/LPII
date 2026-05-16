#include<iostream>
#include<vector>
using namespace std;
int main(){
	int n;
	cout<<"Enter no. of elements"<<endl;
	cin>>n;
	
	vector<int>arr;
	cout<<"Enter Elements!"<<endl;
	int a;
	for(int i=0;i<n;i++){
		cin>>a;
		arr.push_back(a);
	}
	
	
	int min;
	for(int i=0;i<arr.size()-1;i++){
		min=i;
		
		for(int j=i+1;j<arr.size();j++){
			if(arr[j]<arr[min]){
				min=j;
			}
			
		}
		swap(arr[i],arr[min]);
	}
	
	for(int i=0;i<arr.size();i++){
		cout<<arr[i]<<" ";
	}
}
