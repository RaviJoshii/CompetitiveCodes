    // https://leetcode.com/problems/count-different-palindromic-subsequences/
    // Count Different Palindromic 
    #include<bits/stdc++.h>
    using namespace std;
    
    class Solution {
    public:
    long long mod=1000000000+7;
        int countPalindromicSubsequences(string S) {
            vector<vector<long long>> dp(S.size(),vector<long long>(S.size()));
            vector<long long> Low(S.size());
            vector<long long> High(S.size());
            unordered_map<char,long long> umap;
            for(int i=0;i<S.size();i++){
                if(umap.find(S[i])!=umap.end()){
                    High[i]=umap[S[i]];
                    umap[S[i]]=i;
                }
                else{
                    High[i]=-1;
                    umap[S[i]]=i;
                }
            }
            umap.clear();
            for(long long i=S.size()-1;i>=0;i--){
                if(umap.find(S[i])!=umap.end()){
                    Low[i]=umap[S[i]];
                    umap[S[i]]=i;
                }
                else{
                    Low[i]=-1;
                    umap[S[i]]=i;
                }
            }
            for(long long g=0;g<S.size();g++){
                for(long long i=0;i<S.size()-g;i++){
                    long long j=i+g;
                    if(g==0){
                        dp[i][j]=1;
                        continue;
                    }
                    else if(g==1){
                        dp[i][j]=2;
                        continue;
                    }
                    if(S[i]!=S[j]){
                        //case 1"
                        dp[i][j]=(dp[i][j-1]+dp[i+1][j]-dp[i+1][j-1])%mod;

                    }
                    else{
                        //case 2
                        long long lo=Low[i];
                        long long hi=High[j];
                        long long m=(dp[i+1][j-1])%mod;
                        if(lo>hi){
                            //no char
                            dp[i][j]=((2*m)+2)%mod;
                        }
                        else if(lo==hi){
                            //single char
                            dp[i][j]=((2*m)+1)%mod;
                        }
                        else{
                            //many char;
                            dp[i][j]=((2*m)-dp[lo+1][hi-1])%mod;
                        }
                    }
                    dp[i][j] = dp[i][j] < 0 ? dp[i][j] + 1000000007 : dp[i][j] % 1000000007;
                    //This is important since dp[i][j] can be negative and modulus should be positive.
                    

                }
            }
            for(int i=0;i<dp.size();i++){
                for(int j=0;j<dp.size();j++){
                    cout<<dp[i][j]<<" ";
                }
                cout<<endl;
            }
            return (dp[0][S.size()-1])%mod;
        }
    };
    int main(){
        Solution s;
        cout<<s.countPalindromicSubsequences("ababcbaba");
        return 0;
    }
