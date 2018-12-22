/*

Refer to the algo in this link - https://www.youtube.com/watch?v=ddTC4Zovtbc

*/

#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int visited[1000] = {0};
stack <int> s;

void addedge(vector <int> v[], int s, int d){
    v[s].push_back(d);
}

void print(vector <int> v[], int n){
    cout <<"\nADJACENCY LIST OF GRAPH\n";
    for(int i = 0; i < n; i++){
        cout <<i<<"-->";
        for(int j = 0; j < v[i].size(); j++){
            cout <<v[i][j]<<" "; 
        }
        cout <<"\n";
    }
    cout <<"\n";
}

void topo(vector <int> v[], int i){
    if(visited[i] == 0){
        for(int j = 0; j < v[i].size(); j++){
            if(visited[v[i][j]] == 0){
                visited[v[i][j]] = 1;
                topo(v,v[i][j]);
                s.push(v[i][j]);
            }
        }
        if(visited[i] == 0){
            s.push(i);
            visited[i] = 1;
        }
    }
}

void topological_sort(vector <int> v[], int n){
    for(int i = 0; i < n; i++){
        if(visited[i] == 0){
            topo(v,i);
            visited[i] = 1;
        }
    }
}

void pf_stack(){
    cout<<"\nprinting TOPOLOGICAL ORDERING / SORTING\n";
    while(!s.empty()){
        cout<<s.top()<<" ";
        s.pop();
    }
    cout<<"\n";
}

int main()
{
    int n;
    cout <<"\nenter number of vertices : \n";
    cin>>n;
    
    vector <int> v[n];
    
    int e;
    cout <<"\nenter number of edges : \n";
    cin>>e;
    
    for(int i = 0; i < e; i++){
        int src;
        cout <<"\nenter source : \n";
        cin>>src;
        
        int des;
        cout <<"\nenter destination : \n";
        cin>>des;
        
        addedge(v,src,des);
    }

    print(v,n);
    topological_sort(v,n);
    pf_stack();
    
    return 0;
}
