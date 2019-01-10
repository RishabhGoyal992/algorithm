//DIJKSTRA'S ALGORITHM
//refer to - https://www.codingame.com/playgrounds/1608/shortest-paths-with-dijkstras-algorithm/dijkstras-algorithm

#include <iostream>

using namespace std;

int n;
int visited[1000];
int dist[1000];

int visit(){
    for(int i=0;i<n;i++){
        if(visited[i] == 0){
            return 1;
        }
    }
    return 0;
}

int vwmw(){
    int min = 100000;
    for(int i=0;i<n;i++){
        if(min > dist[i] && visited[i] != 1){
            min = dist[i];
        }
    }
    for(int i=0;i<n;i++){
        if(min == dist[i] && visited[i] != 1){
            return i;
        }
    }
}

int main()
{
    cout<<"enter number of vertices : ";
    cin>>n;
    
    int weight[n][n];
    
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            weight[i][j] = 10000;
        }
    }
    
    cout<<"enter number of edges";
    int e;
    cin>>e;
    
    for(int i=0;i<e;i++){
        cout<<"enter src : ";
        int s;
        cin>>s;
        cout<<"enter des : ";
        int d;
        cin>>d;
        cout<<"enter the weight from "<<s<<" to "<<d<<" :";
        int w;
        cin>>w;
        weight[s][d] = weight[d][s] = w;
    }
    
    
    for(int i=0;i<n;i++){
        dist[i] = 10000;
    }
    
    cout<<"enter source to perform dijkstra : ";
    int src;
    cin>>src;
    
    dist[src] = 0;
    
    while(visit()){
        for(int i=0;i<n;i++){
            if(weight[src][i] == 10000){
                
            }else{
                if(visited[i] != 1){
                    if(dist[src] + weight[src][i] < dist[i]){
                        dist[i] = dist[src] + weight[src][i];
                    }
                }
            }
        }
        
        int vertex_index_with_min_weight = vwmw();
        visited[src] = 1;
        src = vertex_index_with_min_weight;
    }
    
    cout<<endl;
    for(int i=0;i<n;i++){
        cout<<dist[i]<<" ";
    }
    cout<<endl;
    
    return 0;
}
