#include <iostream>
#include <vector>
using namespace std;

int visited[10000];
int weight[10000];

struct node {
    int des;
    int dist;
};

void addedge(vector < struct node > v[], int s, int d, int w){
    struct node * x = (struct node *)malloc(sizeof(struct node));
    x->des = d;
    x->dist = w;
    v[s].push_back(*x);
}

void print(vector < struct node > v[], int n){
    cout<<"\nadj list of graph\n";
    for(int i=0;i<n;i++){
        cout<<"vertex "<<i<<" is connected to ";
        for(int j = 0; j < v[i].size(); j++){
            cout<<" des : "<<v[i][j].des<<" with edge weight : "<<v[i][j].dist<<" ";
        }cout<<endl;
    }cout<<endl;
}

int vis(int n){
    for(int i=0;i<n;i++){
        if(visited[i] == 0){
            return 1;
        }
    }
    return 0;
}

int main()
{
    cout<<"enter n :";
    int n;
    cin>>n;
    cout<<"enter e :";
    int e;
    cin>>e;
    
    vector < struct node > v[n];
    
    cout<<"enter src, des, weights :\n";
    for(int i=0;i<e;i++){
        cout<<"enter src :";
        int s;
        cin>>s;
        cout<<"enter des : ";
        int d;
        cin>>d;
        cout<<"enter weight :";
        int w;
        cin>>w;
        addedge(v,s,d,w);
    }
    
    print(v,n);
    
    cout<<endl<<"enter source for dijkstra : ";
    int src;
    cin>>src;
    
    for(int i=0;i<n;i++){
        weight[i] = 100000;
    }
    weight[src] = 0;
    
    while(vis(n)){
        //apply distance formula on adj vertexof src
        for(int j=0;j<v[src].size();j++){
            if(visited[v[src][j].des] != 1){
            if(weight[src] + v[src][j].dist < weight[v[src][j].des]){
                weight[v[src][j].des] = weight[src] + v[src][j].dist;
            }}
        }
        
        
        //pick the vertex with min weight
        
        int minweight = 100000;
        for(int j=0;j<v[src].size();j++){
            if(visited[v[src][j].des] != 1){
            if(minweight > weight[v[src][j].des]){
                minweight = weight[v[src][j].des];
            }}
        }
        int destinationwithminweight;
        for(int j=0;j<v[src].size();j++){
            if(visited[v[src][j].des] != 1){
            if(minweight == weight[v[src][j].des]){
                destinationwithminweight = v[src][j].des;
            }}
        }
        
        //mark src as visited and make new src as the min weight vertex
        
        visited[src] = 1;
        src = destinationwithminweight;
        
    }
    
    cout<<"\nafter dijkstra :\n";
    for(int i=0;i<n;i++){
        cout<<weight[i]<<" ";
    }
    
    return 0;
}
