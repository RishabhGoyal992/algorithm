#include <iostream>

using namespace std;

void merge(int a[], int l, int m, int r){
    int n1 = m-l+1;
    int n2 = r-m;
    
    int x[n1]; int y[n2];
    
    for(int i=0;i<n1;i++){
        x[i] = a[l+i];
    }
    for(int i=0;i<n2;i++){
        y[i] = a[m+1 + i];
    }
    int i = 0;
    int j = 0;
    int k = l;
    while(i<n1 && j<n2){
        if(x[i] < y[j]){
            a[k] = x[i];
            i++;
            k++;
        }else if(y[j] < x[i]){
            a[k] = y[j];
            j++;
            k++;
        }
    }
    while(i<n1){
        a[k] = x[i];
        k++;
        i++;
    }
    while(j<n2){
        a[k] = y[j];
        k++;
        j++;
    }
}

void mergesort(int a[], int l, int r){
    if(l<r){
        int m = (l+r) / 2;
        mergesort(a,l,m);
        mergesort(a,m+1,r);
        merge(a,l,m,r);
    }
}

int main(){
    int a[] = {10,2,1,32,3,43,5,6,57,87,55,321,98,90,85,54,66,89,74};
    int n = sizeof(a)/sizeof(a[0]);
    
    
    mergesort(a,0,n-1);
    
    cout<<endl;
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
    }
    return 0;
}
