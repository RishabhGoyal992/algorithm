/*

https://www.geeksforgeeks.org/huffman-coding-greedy-algo-3/

*/


#include <bits/stdc++.h>

using namespace std;

struct minheapnode{
    char data;
    int freq;
    struct minheapnode * left, * right;
};

struct minheapnode * newnode(char d, int f){
    struct minheapnode * nn = (struct minheapnode *)malloc(sizeof(struct minheapnode));
    nn->data = d;
    nn->freq = f;
    nn->left = nn->right = NULL;
    return nn;
} 

void print(struct minheapnode * r, string str){
    if(!r){
        return ;
    }
    if(r->data != '$'){
        cout<< (r->data) <<" : "<<str<<" \n";
    }
    print(r->left,str+"0");
    print(r->right,str+"1");
}

struct compare{
    bool operator()(minheapnode* l, minheapnode* r){
        {
            return (l->freq > r->freq);
        }
    }
};

void huffman(char d[], int f[], int s){
    struct minheapnode *leftt, *rightt, *top;
    
    priority_queue < minheapnode* , vector < minheapnode* > , compare > minheap;
    
    for(int i=0;i<s;++i){
        minheap.push(newnode(d[i],f[i]));
    }
    
    while(minheap.size() != 1){
        leftt = minheap.top();
        minheap.pop();
        rightt = minheap.top();
        minheap.pop();
        
        top = newnode('$',leftt->freq + rightt->freq);
        top->left = leftt;
        top->right = rightt;
        minheap.push(top);
    }
    
    print(minheap.top(),"");
    
}


int main()
{
    char a[] = {'a','b','c','d','e','f'};
    int f[] = {5,9,12,13,16,45};
    
    int size = sizeof(a) / sizeof(a[0]);
    
    huffman(a,f,size);

    return 0;
}
