// https://practice.geeksforgeeks.org/problems/check-frequencies/0
// Check if frequencies can be equal
#include <bits/stdc++.h>
using namespace std;
bool process(string s){
    unordered_map<char,int> umap;
	    for(char c:s){
	        umap[c]++;
	    }
	    unordered_set<int> uset;
		if(umap.size()==1){
			return 1;
		}
		if(umap.size()==2){
			//finding both elements
			int a=0;int b=0;
			for(auto it:umap){
				if(a==0){
					a=it.second;
				} else if(b==0){
					b=it.second;
				}
			}
			if(a==1 || b==1 || abs(a-b)==1){
				return true;
			} else{
				return false;
			}

		}
		else{
			//finding any three elements frequency
			int a=0;int b=0;int c=0;
			for(auto it:umap){
				if(a==0){
					a=it.second;
				} else if(b==0){
					b=it.second;
				} else if(c==0){
					c=it.second;
					break;
				}
			}
			int same;
			if(a!=b && b!=c && a!=c){ //all are unequal
				return false;
			}
			else if(a==b && a==c){ //all are equal
				same=a;
			}
			else if(b==a || b==c){
				same =b;
			}
			else if(c==a || c==b){
				same =c;
			}
			else if(a==b || a==c){
				same=a;
			}
			bool flag=true;
			for(auto it: umap){
				if(it.second==same) continue;
				if(it.second!=same && flag==true && ((it.second==1) || (it.second-same==1))){
					flag=false;
					continue;//first mistake
				}
				else{
					return false;
				}
			}
			return true;
		}
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