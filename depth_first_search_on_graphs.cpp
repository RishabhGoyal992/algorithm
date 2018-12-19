#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int visited[1000]={0};

void addedges(vector <int> v[],int s, int d){
	v[s].push_back(d);
	v[d].push_back(s);
}

void print(vector <int> v[], int n){
	cout<<"\nADJACENCY LIST OF GRAPH\n";
	for(int i=0;i<n;i++){
		cout<<i<<"--";
		for(int j=0;j < v[i].size();j++){
			cout<<v[i][j]<<" ";
		}
		cout<<"\n";
	}
	cout<<"\n";
}



void dfsutil(vector <int> v[], int n, int src){
	visited[src] = 1;
	cout<<src<<" ";
	for(int i=0; i < v[src].size(); i++){
		if(visited[v[src][i]] != 1){
			dfsutil(v,n,v[src][i]);
		}
	}
}

void dfs(vector <int> v[], int n){
	cout<<"\nDFS\nenter source vertex ";
	int src;
	cin>>src;
	cout<<"\nDFS\n";
	dfsutil(v,n,src);
	cout<<"\n";
}

int main(){
	cout<<"enter the no of vertices";
	int n;
	cin>>n;
	vector <int> v[n];
	cout<<"\nenter the number of edges\n";
	int e;
	cin>>e;
	for(int i=0;i<e;i++){
		cout<<"for edge "<<i+1<<"\n";
		cout<<"enter source ";
		int src;
		cin>>src;
		cout<<"enter destination ";
		int des;
		cin>>des;
		addedges(v,src,des);
	} 
	print(v,n);
	dfs(v,n);
	return 0;
}
