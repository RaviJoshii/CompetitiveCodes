// https://www.geeksforgeeks.org/sort-an-array-of-0s-1s-and-2s/
// Sort an array of 0s, 1s and 2s


#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> arr(n);
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        int i=0;
        int j=0;
        int k=arr.size()-1;
        while(j<=k){
            if(arr[j]==0){
                swap(arr[j],arr[i]);
                i++;
                j++;
            } else if(arr[j]==2){
                swap(arr[j],arr[k]);
                k--;
            } else{
                j++;
            }
        }
        for(int i=0;i<arr.size();i++){
            cout<<arr[i]<<" ";
        }
        cout<<endl;
    }
    return 0;
}