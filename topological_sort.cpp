/*

Refer to the algo in this link - https://www.youtube.com/watch?v=ddTC4Zovtbc

*/

#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int visited[1000];
stack <int> s;

void addedge(vector <int> v[], int s, int d){
    v[s].push_back(d);
}

void toposort(vector <int> v[], int i, int n){
    if(visited[i] == 0){
        for(int j=0;j<v[i].size();j++){
            if(visited[v[i][j]] == 0){
                toposort(v,v[i][j],n);
                visited[v[i][j]] = 1;
                s.push(v[i][j]);
            }
        }
    }
}

void topo(vector <int> v[], int n){
    for(int i=0;i<n;i++){
        if(visited[i] == 0){
            toposort(v,i,n);
            s.push(i);
            visited[i] = 1;
        }
    }
}

int main(){
    cout<<"enter n : ";
    int n;
    cin>>n;
    
    cout<<"enter e :";
    int e;
    cin>>e;
    
    vector <int> v[n];
    
    for(int i=0;i<e;i++){
        cout<<"enter src :";
        int s;
        cin>>s;
        cout<<"enter des :";
        int d;
        cin>>d;
        
        addedge(v,s,d);
    }
    
    for(int i=0;i<n;i++){
        visited[i] = 0;
    }
    
    cout<<"\ntopo sort :\n";
    topo(v,n);
    cout<<endl;
    while(!s.empty()){
        cout<<s.top()<<" ";
        s.pop();
    }
    cout<<endl;
    return 0;
}
