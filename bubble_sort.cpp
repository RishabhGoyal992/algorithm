#include <iostream>

using namespace std;

int main(){
    cout<<"enter n:\n";
    int n;
    cin>>n;
    int a[n];
    cout<<"enter elements of array:\n";
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    cout<<"sorted elements:\n";
    int swapped = 1;
    for(int pass = n;pass>=0 && swapped == 1 ;pass--){
        swapped = 0;
        for(int i = 0;i<=pass;i++){
            if(a[i]>a[i+1]){
                int temp = a[i];
                a[i] = a[i+1];
                a[i+1] = temp;
                swapped = 1;
            }
        }
    }
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
    }
    return 0;
}
