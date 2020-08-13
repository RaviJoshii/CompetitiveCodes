// https://leetcode.com/problems/remove-k-digits/
// Remove K Digits
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    string removeKdigits(string num, int k) {
        
        stack<int> st;
        int i=0;
        while(k>=0 && i<num.size())
        {
            if(st.empty())
            {
                st.push(num[i]);
                i++;
                continue;
            }
            while(!st.empty() && st.top()>num[i] && k)
            {
                st.pop();
                k--;
            }
            st.push(num[i]);
            i++;
        }
        
        string x;
        while(!st.empty())
        {
            char c=st.top();
            x=c+x;
            st.pop();
        }
        i=0;
        while(x[i]=='0')
            i++;
            
        x=x.substr(i);
        
        
        x=x.substr(0,x.size()-k);
        
        if(x.size()==0)
            return "0";
        
        return x;
    }
};
int main(){
    string num = "10200"; int k = 1;
    Solution s;
    cout<<s.removeKdigits(num, k );
    return 0;

}


