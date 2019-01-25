#include <iostream>

using namespace std;

int partition(int a[], int low, int high){
    int pivot = a[high];
    int i = low-1;
    
    for(int j = low;j<=high-1;j++){
        if(a[j] <= pivot){
            i++;
            
            int temp = a[i];
            a[i] = a[j];
            a[j] = temp;
            
        }
    }
    
    int temp = a[i+1];
    a[i+1] = a[high];
    a[high] = temp;
    
    return (i+1);
}

void quicksort(int a[], int low, int high){
    if(low < high){
        int pi = partition(a,low,high);
        quicksort(a,low,pi-1);
        quicksort(a,pi+1,high);
    }
}

int main(){
    cout<<"enter n : ";
    int n;
    cin>>n;
    cout<<"\nenter the elements : \n";
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    
    quicksort(a,0,n-1);
    
    cout<<"\nsorted elements : ";
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
    }
    return 0;
}
