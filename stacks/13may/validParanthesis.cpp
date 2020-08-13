// https://leetcode.com/problems/valid-parentheses/
// Valid Parentheses
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool isValid(string s) {
        if(s.size()==0){
            return true;
        }
        stack<int> st;
        st.push(0);
        for(int i=1;i<s.size();i++){
            if(s[i]==')'){
                if(st.size()>0 && s[st.top()]=='('){
                    st.pop();
                }else{
                    return false;
                }

            }else if(s[i]==']'){
                if(st.size()>0 && s[st.top()]=='['){
                    st.pop();
                }else{
                    return false;
                }

            }else if(s[i]=='}'){
                if(st.size()>0 && s[st.top()]=='{'){
                    st.pop();
                }else{
                    return false;
                }

            }else{
                st.push(i);
            }
        }
        if(st.size()>0){
            return false;
        }
        return true;

        
    }
};
int main(){
    string str="((()()))";
    Solution s;
    cout<<s.isValid(str);
    return 0;
}