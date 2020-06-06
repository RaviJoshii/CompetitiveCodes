// https://practice.geeksforgeeks.org/problems/pairs-of-non-coinciding-points/0
// Pairs of Non Coinciding Points
#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int ans=0;
        unordered_map<int,int> X;
        unordered_map<int,int> Y;
        unordered_map<string,int> XY;
        for(int i=0;i<n;i++){
            int x,y;
            cin>>x>>y;
            string Sxy=to_string(x)+"*"+to_string(y);
            if(X.find(x)!=X.end()){
                ans+=X[x];
            }
            X[x]++;
            if(Y.find(y)!=Y.end()){
                ans+=Y[y];
            }
            Y[y]++;
            if(XY.find(Sxy)!=XY.end()){
                ans=ans-2*XY[Sxy];
            }
            XY[Sxy]++;
            
        }
        cout<<ans<<endl;
        
    }
	return 0;
}