//bellmanford
// refer to - https://www.youtube.com/watch?v=FtN3BYH2Zes
// refer to -  https://www.geeksforgeeks.org/bellman-ford-algorithm-dp-23/
#include <iostream>

using namespace std;

struct node{
    int source;
    int destination;
    int weight;
};

int main()
{
    cout<<"enter number of vertices : ";
    int n;
    cin>>n;
    
    cout<<"enter number of edges : ";
    int e;
    cin>>e;
    
    struct node infoforedges[e];
    
    int weight[n][n];
    
    for(int i=0;i<e;i++){
        cout<<"enter src : ";
        int s;
        cin>>s;
        
        cout<<"enter des : ";
        int d;
        cin>>d;
        
        cout<<"enter weight from "<<s<<" to "<<d<<" :";
        int w;
        cin>>w;
        weight[s][d] = w;
        
        infoforedges[i].source = s;
        infoforedges[i].destination = d;
        infoforedges[i].weight = w;
    }
    
    int dist[n];
    for(int i=0;i<n;i++){
        dist[i] = 100000;
    }
    
    cout<<"enter source vertex for bellman ford algorithm : ";
    int src;
    cin>>src;
    
    dist[src] = 0;
    
    for(int i=0;i<(n-1);i++){
        for(int j=0;j<e;j++){
            int s = infoforedges[j].source;
            int d = infoforedges[j].destination;
            int w = infoforedges[j].weight;
            
            if(dist[s] + w < dist[d]){
                dist[d] = dist[s] + w;
            }
        }
    }
    
    for(int j=0;j<e;j++){
            int s = infoforedges[j].source;
            int d = infoforedges[j].destination;
            int w = infoforedges[j].weight;
            
            if(dist[s] + w < dist[d]){
                cout<<"graph has a negative weight cycle ! Bellman ford cant work !\n";
                dist[d] = dist[s] + w;
            }
    }
    
    cout<<"shortest path distances \n";    
    for(int i=0;i<n;i++){
        cout<<dist[i]<<" ";
    }    
    return 0;
}
