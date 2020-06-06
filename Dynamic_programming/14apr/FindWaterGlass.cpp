// https://www.geeksforgeeks.org/find-water-in-a-glass/
// Program to find amount of water in a given glass

#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin>>t;
    while(t--){
        float k,i,j;
        cin>>k>>i>>j;
        vector<vector<float>> vec(i);
        vec[0]=vector<float>(1,k);
        for(int x=0;x<i-1;x++){
            vec[x+1]=vector<float>(x+2,0);
            for(int y=0;y<vec[x].size();y++){
                float rem=vec[x][y]-1;
                if(rem>0){
                    float halfRemain=rem/2;
                    vec[x+1][y]+=halfRemain;
                    vec[x+1][y+1]+=halfRemain;
                }
            }
        }
        float ans=vec[i-1][j-1];
        if(ans>1){
            ans=1;
        }
        printf("%0.6f\n",ans);
    }
	return 0;
}