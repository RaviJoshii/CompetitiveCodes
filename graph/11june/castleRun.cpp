// https://practice.geeksforgeeks.org/problems/castle-run/0
// Castle RUN
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
        string ans="True";
        for(int i=0;i<degree.size();i++){
            if(degree[i]==0 || degree[i]%2!=0){
                //GRAPH IS DISconnected
                ans="False";
                break;
            }
        }
        if(matrix.size()==1){
            ans="True";
        }
        cout<<ans<<endl;

    }
    return 0;
}