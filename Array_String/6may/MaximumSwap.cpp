// https://leetcode.com/problems/maximum-swap/
// Maximum Swap
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    
    int maximumSwap(int num) {
        string s=to_string(num);
        if(s.size()==1){
            return num;
        }
        int idx=-1;
        for(int i=1;i<s.size();i++){
            if(s[i]>s[i-1]){
                idx=i;
                break;
            }
        }
        
        if(idx==-1){return num;} //num is in decreasing order
        
        //finding max in swapping area
        int swapj=idx;
        
        for(int i=idx;i<s.size();i++){
            if(s[i]>=s[swapj]){
                swapj=i;
            }
        }
        

        //find max in starting area
        int swapi=idx-1;

        for(int i=idx-1;i>=0;i--){
            if(s[i]<s[swapj] && s[i]>=s[swapi]){
                swapi=i;
            }
        }
        swap(s[swapi],s[swapj]);
        return stoi(s);
    }
};
int main(){
    Solution s;
    cout<<s.maximumSwap(997765899);
    return 0;
}