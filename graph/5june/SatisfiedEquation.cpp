// https://leetcode.com/problems/satisfiability-of-equality-equations/
//  Satisfiability of Equality Equations
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
class Solution {
public:
    bool equationsPossible(vector<string>& equations) {
        DisjointSet ds;
        ds.makeset(26);

        //making set of == equations
        for(string s: equations){
            if(s[1]=='='){
                int var1=s[0]-'a';
                int var2=s[3]-'a';
                int l1=ds.find(var1);
                int l2=ds.find(var2);
                if(l1!=l2){
                    ds.Union(var1,var2);
                }
            }
        }

        //checking for != equations
        for(int i=0;i<ds.parent.size();i++){
            cout<<i<<"-"<<ds.parent[i]<<endl;
        }
        for(string s: equations){
            if(s[1]=='!'){
                int var1=s[0]-'a';
                int var2=s[3]-'a';
                int l1=ds.find(var1);
                int l2=ds.find(var2);

                if(l1==l2){
                    return false;
                }
            }
        }



        return true;
    }
};

int main(){
    vector<string > vec={"a!=b" , "b==a"};
    Solution s;
    cout<<s.equationsPossible(vec);
    return 0;
}
