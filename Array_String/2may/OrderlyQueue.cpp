// https://leetcode.com/problems/orderly-queue/
// Orderly Queue
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    string orderlyQueue(string S, int K) {
        string ans=S;
        if(K>=2){
            sort(ans.begin(), ans.end()); 
        }
        else if(K==1){
            
            for(int i=1;i<S.size();i++){
                S=S.substr(1)+S[0];
                if(ans>S){
                    ans=S;
                }
            }
           
        }
        return ans;
        
    }
};