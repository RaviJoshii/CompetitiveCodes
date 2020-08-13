// https://leetcode.com/problems/minimum-add-to-make-parentheses-valid/
// Minimum Add to Make Parentheses Valid
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int minAddToMakeValid(string S) {
        stack<char> st;
        for(int i=0;i<S.length();i++){
            if(S[i]==')'){
                if(st.size()>0 && st.top()=='('){
                    st.pop();
                }else{
                    st.push(S[i]);
                }
            }else{
                st.push(S[i]);
            }
        }
        return st.size();
    }
};
int main(){
    Solution s;
    string str="())";
    cout<<s.minAddToMakeValid(str)<<endl;
    return 0;
}