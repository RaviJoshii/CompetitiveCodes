// https://practice.geeksforgeeks.org/problems/a-simple-fraction/0
// A Simple Fraction
#include <bits/stdc++.h>
using namespace std;
string process(int n,int d){
    string s1="";string s2="";string ans="";
    int quotient=n/d;
    s1=to_string(quotient);
    int rem=n%d;

    if(rem==0){
        return s1;
    }
    s1+=".";
    unordered_map<int,int> umap;
    int idx=-1;
    bool flag=true;
    int startI=-1;
    while(flag){
        if(rem==0){
            flag=false;
            break;
        }
        if(umap.find(rem)!=umap.end()){
            startI=umap[rem];
            flag=false;
            break;
        }
        // cout<<rem<<endl;
        umap[rem]=(++idx);
        rem=rem*10;
        quotient=rem/d;
        s2+=to_string(rem/d);
        rem=rem%d;
        
        
    }
    if(startI==-1){
        return s1+s2;
    }
    ans=s1+s2.substr(0,startI)+"("+s2.substr(startI)+")";
    return ans;
}
int main() {
	int t;
    cin>>t;
    while(t--){
        int n,d;
        cin>>n>>d;
        cout<<process(n,d)<<endl;

    }
	return 0;
}