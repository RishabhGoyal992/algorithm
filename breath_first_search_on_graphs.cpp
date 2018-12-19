#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int visited[1000]={0};

void addedges(vector <int> v[], int src, int des){
    v[src].push_back(des);
    v[des].push_back(src);
}

void print(vector <int> v[],int n){
    cout<<"\nADJACENCY LIST OF GRAPH\n";
    for(int i=0;i<n;i++){
        cout<<i<<"--";
        for(int j=0;j<v[i].size();j++){
            cout<<v[i][j]<<" ";
        }
        cout<<"\n";
    }
    cout<<"\n";
}

void bfs(vector <int> v[], int n){
    queue <int> q;
    cout<<"\nBFS\nenter source vertex\n";
    int src;
    cin>>src;
    q.push(src);
	cout<<q.front()<<" ";
	visited[q.front()] = 1;
    while(!q.empty()){
        for(int i=0; i < v[q.front()].size(); i++){
		  	
            if(visited[v[q.front()][i]] == 1){
			continue;
            }else{
                cout<<v[q.front()][i]<<" ";
                q.push(v[q.front()][i]);
                visited[v[q.front()][i]] = 1;
            }

        }
	q.pop();
    }
    cout<<"\n";
}

int main(){
	
    cout <<"enter the no of vertices : \n";
    int n;
    cin>>n;
    vector <int> v[n];
    int edges;
    cout<<"\n"<<"enter the no of edges : ";
    cin>>edges;
    for(int i=0;i<edges;i++){
        cout<<"for edge no "<< i+1;
        cout<<"\nenter src\n";
        int src;
        cin>>src;
        cout<<"\nenter des\n";
        int des;
        cin>>des;
        addedges(v,src,des);
    }
    print(v,n);
    bfs(v,n);
    return 0;
}
