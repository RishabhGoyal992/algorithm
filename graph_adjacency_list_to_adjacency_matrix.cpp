#include <iostream>
#include <vector>

using namespace std;

int n;

void addedge(vector <int> v[], int s, int d){
    v[s].push_back(d);
}

int main(){
    cout<<"enter n : ";
    
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
    
    int w[n][n];
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            w[i][j] = 0;
        }
    }
    
    for(int i=0;i<n;i++){
        for(int j=0;j<v[i].size();j++){
            w[i][v[i][j]] = 1;
        }
    }
    
    for(int i=0;i<n;i++){
        cout<<endl;
        for(int j=0;j<n;j++){
            cout<<w[i][j]<<" ";
        }
    }
    return 0;
}
