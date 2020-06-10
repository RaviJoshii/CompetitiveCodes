#include<bits/stdc++.h>
using namespace std;
class DisjointSet{
    public:
    vector<int> parent;
    vector<int> rank;
    void makeset(int totalV){
        parent.resize(totalV);
        rank.resize(totalV);

        for(int i=0;i<parent.size();i++){
            parent[i]=i;
        }
        for(int i=0;i<rank.size();i++){
            rank[i]=1;
        }
    }
    int find(int v){
        if(parent[v]==v){
            return v;
        }
        int pv=find(parent[v]);
        parent[v]=pv;
        return pv;
    }

    void Union(int x,int y){
        int lx=find(x);// leader of x= lx
        int ly=find(y);

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

};
class mycomp{
    public:
    int operator()(const vector<int> &J1,const vector<int> &J2){
        return (J1[2]<J2[2]);
    }
};
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<vector<int>> vec(n,vector<int>(3));
        int a,b,c;
        for(int i=0;i<n;i++){
            cin>>a>>b>>c;
            vec[i][0]=a;
            vec[i][1]=b;
            vec[i][2]=c;
        }
        sort(vec.begin(),vec.end(),mycomp());
        
        DisjointSet ds;
        ds.makeset(n+1);
        for(int i=0;i<n;i++){
            int JobId=vec[i][0];
            int profit=vec[i][1];
            int deadline=vec[i][2];

        }

    }
    return 0;
}