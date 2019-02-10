//do not implement rabin karp(only read) as it is never asked in placements

// only KMP IS ASKED IN INTERVIEWS FOR PATTERN MATCHING 

// https://www.youtube.com/watch?v=GTJr8OvyEVQ
// & geeksforgeeks

#include <bits/stdc++.h>

using namespace std;

void calculatelpsarray(int lps[], char pattern[], int m){
    int len = 0;
    lps[0] = 0;
    int i=1;
    while(i<m){
        if(pattern[i] == pattern[len]){
            len++;
            lps[i] = len;
            i++;
        }else{
            if(len != 0){
                len = lps[len-1];
            }else{
                lps[i] = 0;
                i++;
            }
        }
    }
}

void kmp(char text[], char pattern[]){
    int n = strlen(text);
    int m = strlen(pattern);
    int lps[m];
    
    calculatelpsarray(lps,pattern,m);
    
    int i=0;
    int j=0;
    
    while(i<n){
        if(text[i] == pattern[j]){
            j++;
            i++;
        }
        if(j==m){
            cout<<"pattern found at "<<i-j<<endl;
            j = lps[j-1];
        }else if(i<n && pattern[j] != text[i]){
            if(j!=0){
                j = lps[j-1];
            }else{
                i = i+1;
            }
        }
    }
}

int main()
{
    char text[] = "hello whats up? how are you doing ? hello pal. i am good."; 
    char pattern[] = "hello";
    kmp(text,pattern);
    return 0;
}
