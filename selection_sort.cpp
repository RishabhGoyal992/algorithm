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
    
    for(int i=0;i<n-1;i++){
        int minindex = i;
        for(int j=i+1;j<n;j++){
            if(a[minindex] > a[j]){
                minindex = j;
            }
        }
        int temp = a[i];
        a[i] = a[minindex];
        a[minindex] = temp;
    }
    
    cout<<"\nafter sorting\n";
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
    }
    return 0;
}
