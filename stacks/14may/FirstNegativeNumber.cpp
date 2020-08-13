// https://practice.geeksforgeeks.org/problems/first-negative-integer-in-every-window-of-size-k/0
// First negative integer in every window of size k

#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> vec(n);
        for(int i=0;i<n;i++){
            cin>>vec[i];
        }
        int k;
        cin>>k;

        int idx=-1;

        for(int i=n-1;i>=n-k;i--){
            if(vec[i]<0){
                idx=i;
            }
        }
        vector<int> ans(n-k+1);
        for(int i=n-k;i>=0;i--){
            if(vec[i]<0){
                idx=i;
                ans[i]=vec[i];
            }else{
                if(idx>=i && idx<=i+k-1){
                    ans[i]=vec[idx];
                }else{
                    ans[i]=0;
                }
            }
        }
        for(auto num: ans){
            cout<<num<<" ";
        }
        cout<<endl;
    }
    return 0;
}