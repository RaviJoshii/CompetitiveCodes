// https://www.spoj.com/problems/RMQSQ/
// RMQSQ - Range Minimum Query
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fastIO() ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

void preprocessing(vector<int> &arr2,vector<int> &arr){
    int sizes=arr2.size();
    int mins=INT_MAX;
    int j=0;
    for(int i=0;i<arr.size();i++){
        mins=min(mins,arr[i]);
        if((i+1)%sizes==0){
            arr2[j]=mins;
            mins=INT_MAX;
            j++;
        }
    }
}
int main(){
    int n;
    cin>>n;
    fastIO();
    vector<int> arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int q;
    cin>>q;

    //preprocessing;
    int sizes=ceil(sqrt(n));
    vector<int> arr2(sizes,0);
    preprocessing(arr2,arr);
    ///////////////////////////////////////////


    for(int i=0;i<q;i++){
        int l,r;
        cin>>l>>r;
        int ans=INT_MAX;
        while(l%sizes!=0&& l<=r){
            ans=min(ans,arr[l]);
            l++;
        }

        while(l+sizes-1<=r){
            ans=min(ans,arr2[ceil(l/sizes)]);
            l=l+sizes;
        }
        while(l<=r){
            ans=min(ans,arr[l]);
            l++;
        }
        cout<<ans<<endl;

    }

    return 0;
}
