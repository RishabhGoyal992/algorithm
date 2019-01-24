#include <iostream>

using namespace std;

int main()
{
    int n;
    cout<<"enter n:";
    cin>>n;
    
    int a[n];
    
    cout<<"enter elements of the array :";
    
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    
    int key,i,j;
    for(i=1;i<n;i++){
        key = a[i];
        for(j=i-1;j>=0 && key < a[j];j--){
            
                a[j+1] = a[j];
            
        }
        a[j+1] = key;
    }
    
    cout<<"\nafter sorting\n";
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
    }
    return 0;
}
