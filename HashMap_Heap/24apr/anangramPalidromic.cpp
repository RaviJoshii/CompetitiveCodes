// https://practice.geeksforgeeks.org/problems/anagram-palindrome/0
// Anagram Palindrome
#include <bits/stdc++.h>
using namespace std;
string process(string s){
    unordered_map<char,int> umap;
	    for(int i=0;i<s.size();i++){
	        umap[s[i]]++;
	    }
	    bool flag=true;
	    for(auto it:umap){
	        if(it.second%2!=0){
	            if(flag){
	                flag=false;
	            }
	            else{
	                return "No";
	            }
	        }
	    }
	    return "Yes";
}
int main() {
    int t;
    cin>>t;
    
	while(t--){
	    string s;
	    cin>>s;
	    cout<<process(s)<<endl;
	}
	return 0;
}