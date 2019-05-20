/*
algo used - 
1 take input for s, d, w in array of structure
2 sort it
3 while(all vertex are not covered){
    3.1 take the edge with min weight and that is not visited yet
    3.2 check for cycle after adding the edge
    3.3 add it if it does not form any cycle after adding
        3.3.1 if added mark s and d as visited vertices 

}
*/

#include <bits/stdc++.h>

using namespace std;

struct node{
    int s;
    int d;
    int w;
};

bool compare(struct node a, struct node b){
    return (a.w < b.w);
}

int find(int a[], int i){
    while(a[i] != i){
        i = a[i];
    }
    return i;
}

void unionn(int a[], int x, int y){
    a[y] = x;
}

int main(){
    
    int n;
    int e;
    cout<<"enter e :";
    cin>>e;
    cout<<"enter v :";
    cin>>n;
    
    struct node a[e];
    for(int i=0;i<e;i++){
        cout<<"s : ";
        cin>>a[i].s;
        cout<<"d : ";
        cin>>a[i].d;
        cout<<"w : ";
        cin>>a[i].w;
    }
    
    sort(a,a+e,compare);
    
    int visited[n];
    for(int i=0;i<n;i++){
        visited[i] = 0;
    }
    
    int parent[n];
    for(int i=0;i<n;i++){
        parent[i] = i;
    }
    
    cout<<"mst using kruskal\n";
    for(int i=0;i<e-1;i++){
        if( ( find(parent,a[i].s) != find(parent,a[i].d) )  ){
            cout<<"s : "<<a[i].s<<"d : "<<a[i].d<<"w : "<<a[i].w<<endl;
            unionn(parent,(a[i].s),(a[i].d));
            visited[a[i].s] = 1;
            visited[a[i].d] = 1;
        }
    }
    
    return 0;
}
