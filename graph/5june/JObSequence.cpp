// https://practice.geeksforgeeks.org/problems/job-sequencing-problem/0
// Job Sequencing Problem

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
        return (J1[2]>J2[2]);
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
        int maxDeadline=INT_MIN;
        for(int i=0;i<n;i++){
            cin>>a>>b>>c;
            vec[i][0]=a;
            vec[i][1]=b;
            vec[i][2]=c;
            maxDeadline=max(maxDeadline,b);
        }
        sort(vec.begin(),vec.end(),mycomp());
        
        
        int NoOfJobs=0;
        int TotalProfit=0;
        DisjointSet ds;
        ds.makeset(maxDeadline+1);
        for(int i=0;i<n;i++){

            int JobId=vec[i][0];
            int deadline=vec[i][1];
            int profit=vec[i][2];
            int leader=ds.find(deadline);
            
            if(leader>0){
                TotalProfit+=profit;
                NoOfJobs++;
                ds.parent[leader]=leader-1;
            }

        }
        cout<<NoOfJobs<<" "<<TotalProfit<<endl;

    }
    return 0;
}