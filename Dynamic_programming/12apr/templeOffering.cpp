// https://www.geeksforgeeks.org/temple-offerings/
// Temple Offerings
#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> height(n);
        for(int i=0;i<n;i++){
            cin>>height[i];
        }
        vector<int> left(n);
        vector<int> right(n);
        left[0]=1;
        right[n-1]=1;
        int ans=0;
        for(int i=1;i<n;i++){
            if(height[i]>height[i-1]){
                left[i]=left[i-1]+1;
            }
            else{
                 left[i]=1;
            }
        }
        for(int i=n-2;i>=0;i--){
            if(height[i]>height[i+1]){
                right[i]=right[i+1]+1;
            }
            else{
                 right[i]=1;
            }
        }
        for(int i=0;i<n;i++){
            ans=ans+max(left[i],right[i]);
        }
        
        cout<<ans<<endl;
    }
    return 0;
}
