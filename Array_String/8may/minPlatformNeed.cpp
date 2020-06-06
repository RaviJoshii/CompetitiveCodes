// https://practice.geeksforgeeks.org/problems/minimum-platforms/0
// Minimum Platforms

#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> arr(n);
        vector<int> dep(n);
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        for(int i=0;i<n;i++){
            cin>>dep[i];
        }
        sort(arr.begin(),arr.end());
        sort(dep.begin(),dep.end());
        int i=1;
        int j=0;
        int count=1;
        int ans=1;
        while(j<n && i<n){
            if(arr[i]<=dep[j]){
                i++;
                count++;
            }else if(arr[i]>dep[j]){
                j++;
                count--;
            }
            ans=max(ans,count);
        }
        cout<<ans<<endl;

    }
    return 0;
}

// Minimum Platforms