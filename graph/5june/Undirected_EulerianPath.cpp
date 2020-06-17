// https://practice.geeksforgeeks.org/problems/eulerian-path-in-an-undirected-graph/0
// Eulerian Path in an Undirected Graph
#include<bits/stdc++.h>
using namespace std;


int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<vector<int>> matrix(n,vector<int>(n));

        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                cin>>matrix[i][j];
            }
        }

        //implement degree array
        vector<int> degree(n,0);
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(matrix[i][j]==1){
                    degree[j]++;
                }
            }
        }
        int countsOdd=0;
        for(int i=0;i<degree.size();i++){
            if(degree[i]%2!=0){
                countsOdd++;
                if(countsOdd>2){
                    break;
                }
            }
        }
        if(countsOdd==0 || countsOdd==2){
            cout<<1<<endl;
        }else{
            cout<<0<<endl;
        }

    }
    return 0;
}