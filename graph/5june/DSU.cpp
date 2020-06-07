// https://cp-algorithms.com/data_structures/disjoint_set_union.html#:~:text=A%20DSU%20will%20have%20an,set%20from%20a%20new%20element.&text=This%20representative%20can%20be%20used,the%20same%20set%20of%20not.
// https://www.geeksforgeeks.org/disjoint-set-data-structures/

#include<bits/stdc++.h>
using namespace std;


void makeset(int totalV,vector<int> &parent,vector<int> &rank){
    for(int i=0;i<parent.size();i++){
        parent[i]=i;
    }
    for(int i=0;i<rank.size();i++){
        rank[i]=i;
    }
}
int find(int v,vector<int> &parent){
    if(parent[v]==v){
        return v;
    }
    int pv=find(parent[v],parent);
    parent[v]=pv;
    return pv;
}

void Union(int x,int y,vector<int> &parent, vector<int> &rank){
    int lx=find(x,parent);// leader of x= lx
    int ly=find(y,parent);

    if(lx==ly){
        return;
    }

    if(rank[lx]>rank[ly]){
        parent[ly]=lx;
    }else if(rank[lx]<rank[ly]){
        parent[lx]=ly;
    }else{
        parent[lx]=ly;
        rank[ly]++;
    }
}

int main(){
    

    return 0;
}