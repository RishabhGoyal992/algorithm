//         https://www.geeksforgeeks.org/fractional-knapsack-problem/



#include<bits/stdc++.h>

using namespace std;

struct node{
    double w;
    double v;
    double r;
};

bool compare(struct node a, struct node b){
    return a.r > b.r;
}

int main()
{
	//code
	
	int t;
	cin>>t;
	std::cout << std::setprecision(2) << std::fixed;

	for(int i=0;i<t;i++){
	    
	    int N;
	    double W;
	    cin>>N>>W;
	    
	    struct node a[N];
	    
	    for(int j=0;j<N;j++){
	        double x;
	        cin>>x;
	        double y;
	        cin>>y;
	        
	        a[j].v = x;
	        a[j].w = y;
	        a[j].r = (double)(x/y);
	        
	    }
	    
	    sort(a,a+N,compare);
	    
	    double Weight = 0;
	    double Value = 0.0;
	    
	    for(int j=0;j<N;j++){
	        
	        if(Weight + a[j].w <= W){
	            Weight += a[j].w;
	            Value += a[j].v;
	        }else{
	            double remain = W - Weight;
	            Value += ((double)(a[j].v))*((double)remain/(double)a[j].w);
	            break;
	        }
	        
	    }
	    
	    cout<<(double)Value<<endl;
	}
	
	return 0;
}
