// https://www.geeksforgeeks.org/length-of-the-longest-valid-substring/
// Length of the longest valid substring
#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;

    while(t--){
        string s;
        cin>>s;
        int ans=0;
        int len=0;
        stack<pair<char,int>> st;
        st.push(make_pair('#',-1));
        for(int i=0;i<s.length();i++){
            // cout<<1<<endl;
            if(s[i]=='('){
                st.push(make_pair(s[i],i));
            }else{
                if(st.top().first=='('){
                    st.pop();
                    int idx=st.top().second;
                    ans=max(ans,i-idx);
                }else{
                    st.push(make_pair(s[i],i));
                }

            }
        }
        cout<<ans<<endl;
    }
    return 0;
}