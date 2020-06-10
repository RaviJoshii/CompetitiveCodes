// https://practice.geeksforgeeks.org/problems/implementing-floyd-warshall/0
// Floyd Warshall


#include <bits/stdc++.h>
using namespace std;
#define endl "\n";
#define fast_io() ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define infs 1e7
int main() {
    fast_io();
	int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<vector<int>> vec(n,vector<int>(n));
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                cin>>vec[i][j];
            }
        }

        for(int k=0;k<n;k++){
            for(int u=0;u<n;u++){
                for(int v=0;v<n;v++){
                    if((vec[u][k] >=infs) || vec[k][v]>=infs){
                        continue;
                    }else{
                        vec[u][v]=min(vec[u][v],vec[u][k]+vec[k][v]);
                    }  
                    }
                    
                }
            }
            for(int i=0;i<vec.size();i++){
                for(int j=0;j<vec[0].size();j++){
                    cout<<vec[i][j]<<" ";
                }
                cout<<endl;
            }
        }

        
	return 0;
}