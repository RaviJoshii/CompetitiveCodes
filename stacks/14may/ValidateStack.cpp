// https://leetcode.com/problems/validate-stack-sequences/
// Validate Stack Sequences
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int> st;
        int i=0;
        int j=0;
        int n=pushed.size();
        while(i<n || j<n){

            if(st.size()>0 && popped[j]==st.top()){
                st.pop();
                j++;
            }else if(i<n){
                st.push(pushed[i]);
                i++;
            }else{
                return false;
            }

        }
        return true;
        
    }
};

int main(){
    Solution s;
    vector<int> pushed = {1,2,3,4,5};
    vector<int>  popped = {4,5,3,2,1};
    cout<<s.validateStackSequences(pushed, popped);
    return 0;
}