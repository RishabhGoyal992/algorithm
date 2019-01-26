#include <iostream>

using namespace std;

int binarysearch(int a[], int s, int e, int x){
    if(s<=e){
        int m = (s+e)/2;
        if(a[m] == x){
            return m;
        }
        if(a[m]<x){
            return binarysearch(a,m+1,e,x);
        }else if(a[m]>x){
            return binarysearch(a,0,m-1,x);
        }
    }
    return -1;
}

int main()
{
    cout<<"enter n :";
    int n;
    cin>>n;
    
    cout<<"enter the elements : ";
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }

    while(1){
        cout<<"\nenter element to search : ";
        int x;
        cin>>x;
        
        int index = binarysearch(a,0,n-1,x);
        if(index == -1){
            cout<<"\nelement not present";
        }else{
            cout<<"\nelement present at "<<index<<" position\n";
        }
        cout<<"\nsearch for another element?\n1.yes\t2.no\n";
        int d;
        cin>>d;
        if(d == 2){
            cout<<"\nthanks ";
            exit(0);
        }else if(d == 1){
            continue;
        }else{
            cout<<"\nenter correct option next time ... running it one more time ...";
        }
    }
    return 0;
}
