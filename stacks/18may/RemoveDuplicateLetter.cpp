// https://leetcode.com/problems/remove-duplicate-letters/
// 316. Remove Duplicate Letters
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    string removeDuplicateLetters(string s) {
        unordered_map<char, pair<int,bool>> umap;
        for(int i=0;i<s.size();i++){
            if(umap.find(s[i])!=umap.end()){
                umap[s[i]].first++;
            }else{
                umap[s[i]].first=1;
                umap[s[i]].second=false;
            }
        }

        list<char> st;
        //we are using list as STACK by PushFirst() and PopFirst();
        for(int i=0;i<s.size();i++){
            umap[s[i]].first--;
            if(umap[s[i]].second==true){
                continue;
            }
            while(st.size()>0 && st.front()>s[i] && umap[st.front()].first>0){
                umap[st.front()].second=false;
                st.pop_front();

            }
            umap[s[i]].second=true;
            st.push_front(s[i]);
        } 
        string ans="";
        for(auto ch: st){
            ans+=ch;
        }
        //reversing the answer string
        int i=0;int j=ans.size()-1;
        while(i<j){

            char temp=ans[i];
            ans[i]=ans[j];
            ans[j]=temp;
            i++;
            j--;
        }
        return ans;
        
    }
};
int main(){
    Solution s;
    string str;
    cin>>str;
    cout<<s.removeDuplicateLetters(str);
    
    return 0;
}