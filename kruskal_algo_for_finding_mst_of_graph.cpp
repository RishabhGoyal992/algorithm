#include <iostream>

using namespace std;

struct node {
    int s;
    int d;
    int w;
    int visited;
};

int ver_vis(int v[],int n){
    for(int i=0;i<n;i++){
        if(v[i] == 0){
            return 1;
        }
    }
    return 0;
}

int n;

int parent[1000];

int find(int i){
    while(i != parent[i]){
        i = parent[i];
    }
    return i;
}

int main()
{
    cout<<"enter number of vertices : ";
    int v;
    cin>>v;
    n=v;
    cout<<"enter number of edges : ";
    int e;
    cin>>e;
    
    struct node edges[e];
    
    for(int i=0;i<e;i++){
        cout<<"enter src : ";
        cin>>edges[i].s;
        cout<<"enter des : ";
        cin>>edges[i].d;
        cout<<"enter weight :";
        cin>>edges[i].w;
        edges[i].visited = 0;
    }
    
    struct node newedges[e];
    //creating a new array of structure with sorted edges according to their weights 
    for(int i=0;i<e;i++){
        int min_index; int min_weight = 100000;
        
        for(int j=0;j<e;j++){
            if(min_weight > edges[j].w && edges[j].visited == 0){
                min_weight = edges[j].w;
            }
        }
        
        for(int j=0;j<e;j++){
            if(min_weight == edges[j].w && edges[j].visited == 0){
                min_index = j;
                edges[j].visited = 1;
            }
        }
        
        newedges[i].s = edges[min_index].s;
        newedges[i].d = edges[min_index].d;
        newedges[i].w = edges[min_index].w;
        newedges[i].visited = 0;
    }
    
    cout<<endl<<"sorted list of edges"<<endl;
    for(int i=0;i<e;i++){
        cout<<newedges[i].s<<" "<<newedges[i].d<<" "<<newedges[i].w<<endl;
    }
    cout<<endl;
    
    int vertex_visited[n];
    for(int i=0;i<n;i++){
        vertex_visited[i] = 0;
    }
    
    for(int i=0;i<n;i++){
        parent[i] = i;
    }
    
    cout<<"\nMST USING KRUSHKAL ALGO"<<endl;
    
    while(ver_vis(vertex_visited,n)){
        for(int i=0;i<e;i++){
            if(newedges[i].visited == 0){
                if(find(newedges[i].s) != find(newedges[i].d)){ 
                    vertex_visited[newedges[i].s] = 1;
                    vertex_visited[newedges[i].d] = 1;
                    
                    cout<<endl<<newedges[i].s<<" to "<<newedges[i].d<<" with weight "<<newedges[i].w<<" is in mst";
                    newedges[i].visited = 1;
                    parent[newedges[i].d] = newedges[i].s; 
                }
            }
        }
    }
    
    return 0;
}
