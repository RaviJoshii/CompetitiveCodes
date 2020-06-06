// https://www.geeksforgeeks.org/lcs-longest-common-subsequence-three-strings/
// LCS (Longest Common Subsequence) of three strings
#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--)
    {
        int a,b,c;
        cin>>a>>b>>c;
        vector<vector<vector<int>>> LCS(a+1,vector<vector<int>>(b+1,vector<int>(c+1,0)));
        string s1,s2,s3;
        cin>>s1>>s2>>s3;
        for(int i=0;i<=a;i++){
            for(int j=0;j<=b;j++){
                for(int k=0;k<=c;k++){
                    if(i==0||j==0||k==0){
                        LCS[i][j][k]=0;
                    }
                    else if(s1[i-1]==s2[j-1]&&s3[k-1]==s2[j-1]){
                            LCS[i][j][k]=1+LCS[i-1][j-1][k-1];
                        }
                    else{
                            LCS[i][j][k]=max(LCS[i-1][j][k],
                                            max(LCS[i][j-1][k],
                                            LCS[i][j][k-1]));
                        }
                    
                }
            }
        }
        cout<<LCS[a][b][c]<<endl;

    }   
    return 0;
}