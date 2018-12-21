#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int visited[1000] = {0};

void addedges(vector <int> v[],int s,int d){
    v[s].push_back(d);
    v[d].push_back(s);
}

void print(vector <int> v[], int n){
    cout<<"\nADJACENCY LIST OF GRAPH\n";
    for(int i=0;i<n;i++){
        cout<<"\n"<<i<<"-->";
        for(int j=0;j < v[i].size(); j++){
            cout<<v[i][j]<<" ";
        }
        cout<<"\n";
    }
}

void bfs(vector <int> v[], int n){
    cout<<"\nBFS\nenter source vertex\n";
    int src;
    cin>>src;
    queue <int> q;
    q.push(src);
    cout<<q.front()<<" ";
    visited[src] = 1;
    while(!q.empty()){
        for(int j=0;j < v[q.front()].size(); j++){
            if(visited[v[q.front()][j]] != 1){
                cout<<v[q.front()][j]<<" ";
                q.push(v[q.front()][j]);
                visited[v[q.front()][j]] = 1;
            }
        }
        q.pop();
    }cout<<"\n";
}

void dfs(vector <int> v[], int ele){
    cout<<ele<<" ";
    visited[ele] = 1;
    for(int j = 0; j < v[ele].size(); j++){
        if(visited[v[ele][j]] != 1){
            dfs(v,v[ele][j]);
        }
    }
}

int main()
{
    int n;
    cout<<"enter the no of vertices \n";
    cin>>n;
    vector <int> v[n];
    cout<<"\nenter the no of edges\n";
    int e;
    cin>>e;
    for(int i=0;i<e;i++){
        cout<<"\nenter source\n";
        int src;
        cin>>src;
        cout<<"\nenter destination\n";
        int des;
        cin>>des;
        addedges(v,src,des);
    }
    print(v,n);
    bfs(v,n);
    cout<<"\nDFS OF GRAPH\nenter source\n";
    int s;
    cin>>s;
    for(int i=0;i<n;i++){
        visited[i] = 0;
    }
    dfs(v,s);
    return 0;
}
