/*
For Dijkstra’s algorithm, it is always recommended to use heap (or priority queue) as the required operations (extract minimum and decrease key) match with speciality of heap (or priority queue). However, the problem is, priority_queue doesn’t support decrease key. To resolve this problem, do not update a key, but insert one more copy of it. So we allow multiple instances of same vertex in priority queue. This approach doesn’t require decrease key operation and has below important properties.

Whenever distance of a vertex is reduced, we add one more instance of vertex in priority_queue. Even if there are multiple instances, we only consider the instance with minimum distance and ignore other instances.
The time complexity remains O(ELogV)) as there will be at most O(E) vertices in priority queue and O(Log E) is same as O(Log V)
Below is algorithm based on above idea.

1) Initialize distances of all vertices as infinite.

2) Create an empty priority_queue pq.  Every item
   of pq is a pair (weight, vertex). Weight (or 
   distance) is used used as first item  of pair
   as first item is by default used to compare
   two pairs

3) Insert source vertex into pq and make its
   distance as 0.

4) While either pq doesn't become empty
    a) Extract minimum distance vertex from pq. 
       Let the extracted vertex be u.
    b) Loop through all adjacent of u and do 
       following for every vertex v.

           // If there is a shorter path to v
           // through u. 
           If dist[v] > dist[u] + weight(u, v)

               (i) Update distance of v, i.e., do
                     dist[v] = dist[u] + weight(u, v)
               (ii) Insert v into the pq (Even if v is
                    already there)
               
5) Print distance array dist[] to print all shortest
   paths. 
*/

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
