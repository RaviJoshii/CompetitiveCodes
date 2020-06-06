// https://www.geeksforgeeks.org/substring-equal-number-0-1-2/
// Count Substrings with equal number of 0s, 1s and 2s

#include <bits/stdc++.h>
using namespace std;
int main() {
    int t;
    cin>>t;
    while(t--){
        string s;
        cin>>s;
        int n=s.length();
        vector<int> count0(n);
        vector<int> count1(n);
        vector<int> count2(n);
        if(s[0]=='0'){
            count0[0]=1;
            count1[0]=0;
            count2[0]=0;
        }
        else if(s[0]=='1'){
            count0[0]=0;
            count1[0]=1;
            count2[0]=0;
        }
        else if(s[0]=='2'){
            count0[0]=0;
            count1[0]=0;
            count2[0]=1;
        }
        

        for(int i=1;i<n;i++){
            if(s[i]=='0'){
                count0[i]=count0[i-1]+1;
                count1[i]=count1[i-1];
                count2[i]=count2[i-1];
            }
            else if(s[i]=='1'){
                count0[i]=count0[i-1];
                count1[i]=count1[i-1]+1;
                count2[i]=count2[i-1];
            }
            else if(s[i]=='2'){
                count0[i]=count0[i-1];
                count1[i]=count1[i-1];
                count2[i]=count2[i-1]+1;
            }
        }

        unordered_map<string,int> umap;
        umap["0&0"]=1;
        int diff1,diff2;
        int ans=0;
        for(int i=0;i<n;i++){
            diff1=count0[i]-count1[i];
            diff2=count0[i]-count2[i];
            string key=to_string(diff1)+"&"+to_string(diff2);
            if(umap.find(key)!=umap.end()){
                ans+=umap[key];
                umap[key]++;
            }
            else{
                umap[key]=1;
            }
        }
        cout<<ans<<endl;
    }
	return 0;
}