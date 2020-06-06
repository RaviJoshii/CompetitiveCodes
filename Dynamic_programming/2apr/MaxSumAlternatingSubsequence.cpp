// https://www.geeksforgeeks.org/maximum-sum-alternating-subsequence-sum/
// Maximum sum alternating subsequence
#include<bits/stdc++.h>
using namespace std;
int MaxSumAlt(vector<int> &arr){
    vector<int> inc(arr.size());
    vector<int> dec(arr.size());
    for(int i=arr.size()-1;i>=0;i--){
        if(i==arr.size()-1){
            inc[i]=arr[i];
            dec[i]=arr[i];
            continue;
        }

        //inc
        int incv=0;
        for(int k=i+1;k<arr.size();k++){
            if(arr[k]<arr[i]){
                incv=max(incv,dec[k]);
            }
        }
        inc[i]=arr[i]+incv;

        //dec
        int decv=0;
        for(int k=i+1;k<arr.size();k++){
            if(arr[k]>arr[i]){
                decv=max(decv,inc[k]);
            }
        }
        dec[i]=arr[i]+decv;
    }
    return inc[0];
}
int main(){
    vector<int> arr={4, 8, 2, 5, 6, 8} ;
    cout<<MaxSumAlt(arr)<<endl;
    return 0;
}