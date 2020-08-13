// https://practice.geeksforgeeks.org/problems/inversion-of-array/0
// Inversion of array
#include<bits/stdc++.h>
using namespace std;
void mergeSort(vector<int> &arr, int lo, int hi){

    

}

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
        mergeSort(arr,0,arr.size()-1);
    }

    return 0;
}