#include <bits/stdc++.h>
# define inf 100000
using namespace std;
int n ;
void addedge(vector < pair<int , int> > v[], int s, int d, int w){
    v[s].push_back(make_pair(d,w));
    v[d].push_back(make_pair(s,w));
}

void dijkstra(vector< pair<int , int> > v[], int src){
    priority_queue< pair<int , int> , vector< pair<int , int> > , greater < pair <int , int> > > pq;
    vector <int> dist(n,inf);
    pq.push(make_pair(0,src));
    dist[src] = 0;
    while(!pq.empty()){
        int u = pq.top().second;
        pq.pop();
        for(auto i = v[u].begin();i != v[u].end(); i++){
            int vertex = (*i).first;
            int weight = (*i).second;
            if(dist[vertex] > dist[u] + weight){
                dist[vertex] = dist[u] + weight;
                pq.push(make_pair(dist[vertex],vertex));
            }
        }
    }
    
    cout<<"\nvertex distance from source \n";
    for(int i=0;i<n;i++){
        cout<<" [ "<<i<<" , "<<dist[i]<<" ] \n";
    }
}

int main(){
    cout<<"enter n : ";
    
    cin>>n;
    
    cout<<"enter e :";
    int e;
    cin>>e;
    
    vector < pair<int,int> > v[n];
    
    cout<<"\nenter the src, des & weight info\n";
    for(int i=0;i<e;i++){
        cout<<"enter src :";
        int s;
        cin>>s;
        cout<<"enter des :";
        int d;
        cin>>d;
        cout<<"enter weight :";
        int w;
        cin>>w;
        
        addedge(v,s,d,w);
    }
    
    cout<<"\nenter source vertex for dijkstra : \n";
    int src;
    cin>>src;
    
    dijkstra(v,src);
    
    return 0;
}
