// https://practice.geeksforgeeks.org/problems/longest-prefix-suffix/0
// Longest Prefix Suffix

#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin>>t;
	while(t--){
	    string str;
	    cin>>str;
	    vector<int> lps(str.length(),0);
        lps[0]=0;
        int len=0;
        ///implenting lps array
        for(int i=1;i<str.length();i++){
            int len=lps[i-1];
    
            while(len > 0 && str[i]!=str[len] ){
                len=lps[len-1];
            }
    
            // len can be 0 or str[len]==str[i]
            
            if(len==0){
                if(str[len]==str[i]){
                    lps[i]=1;
                }else{
                    lps[i]=0;
                }
            }else{
                 lps[i]=len+1;
            }
            
         
        }
        cout<<lps.back()<<endl;
	    
	}
	return 0;
}