// https://leetcode.com/problems/similar-string-groups/
// Similar String Groups

#include<bits/stdc++.h>
using namespace std;


class DisjointSet{
    public:
    vector<int> parent;
    vector<int> rank;
    int sets=0;
    void makeset(int totalV){
        parent.resize(totalV);
        rank.resize(totalV);

        for(int i=0;i<parent.size();i++){
            parent[i]=i;
        }
        for(int i=0;i<rank.size();i++){
            rank[i]=1;
        }
        sets=totalV;
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
        sets--;
    }

    int CountSets(){
        return sets;
    }

};



class Solution {
public:
    bool checkSimilarity(string &s1,string &s2){
        int c=0;
        for (int i = 0; i < s1.size(); i++)
            if (s1[i] != s2[i]){
                c++;
                if(c>2){
                    return false;
                }
            }
        return true;
    }
    int numSimilarGroups(vector<string>& A) {
        
        if(A.size()<2){
            return A.size();
        }
        DisjointSet ds;
        ds.makeset(A.size());
        for(int i=0;i<A.size();i++){
            for(int j=i+1;j<A.size();j++){
                if(checkSimilarity(A[i],A[j])){
                    ds.Union(i,j);
                }
            }
        }
        return ds.CountSets();
        
    }
};