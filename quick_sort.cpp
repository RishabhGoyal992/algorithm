//   https://www.youtube.com/watch?v=COk73cpQbFQ


#include <iostream>

using namespace std;

int partition(int a[], int s, int e){
    int pivot = a[e];
    int pindex = s;
    for(int i=s;i<e;i++){
        if(a[i] <= pivot){
            swap(a[i],a[pindex]);
            pindex++;
        }
    }
    swap(a[pindex],a[e]);
    return pindex;
}

void quicksort(int a[], int s, int e){
    if(s<e){
        int index = partition(a,s,e);
        quicksort(a,s,index-1);
        quicksort(a,index+1,e);
    }
}

int main(){
    int n;
    cout<<"size : ? ";
    cin>>n;
    int a[n];
    cout<<"enter the elements : \n";
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    quicksort(a,0,n-1);
    cout<<endl<<"sorted : ";
    cout<<endl;
    
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
    }
    return 0;
}
