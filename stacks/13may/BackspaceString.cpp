// https://leetcode.com/problems/backspace-string-compare/
// Backspace String Compare
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool backspaceCompare(string S, string T) {
        int i=S.length()-1;
        int j=T.length()-1;
        int count1=0;
         int count2=0;
        while(i>=0 || j>=0){
            // cout<<i<<j<<"&";
            // if(i<0){
            //     return false;
            // }
            while(i>=0){
                if(S[i]=='#'){
                    count1++;
                    i--;
                }else{
                    if(count1==0){
                        break;
                    }else if(count1>0){
                        count1--;
                        i--;
                    }
                }
            }

            while(j>=0){

                if(T[j]=='#'){
                    count2++;
                    j--;
                }else{
                    if(count2==0){
                       break;
                    }else if(count2>0){
                        count2--;
                        j--;
                    }
                }

            }
            // If two actual characters are different
            if(i >= 0 && j >= 0 && S[i] != T[j]){
                return false;
            }
            else if ((i >= 0) != (j >= 0)){
                // If expecting to compare char vs nothing
                return false;
            }
            else{
                // if S[i]==T[j]
                i--;
                j--;
            }
        }

        return true;
    }
    
};
int main(){
    Solution s;
    cout<<s.backspaceCompare("bxj##tw","bxj###tw");
    return 0;
}