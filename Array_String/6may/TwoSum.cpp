// https://www.geeksforgeeks.org/given-an-array-a-and-a-number-x-check-for-pair-in-a-with-sum-as-x/
// Given an array A[] and a number x, check for pair in A[] with sum as x
//two pointer approach
#include <bits/stdc++.h>
using namespace std;
string process(vector<int> &arr,int tar){
    sort(arr.begin(),arr.end());
    int i=0;
    int j=arr.size()-1;
    while(i<j){
        if(arr[i]+arr[j]<tar){
            i++;
        }
        else if(arr[i]+arr[j]>tar){
            j--;
        }else {
            // gets the pair
            return "Yes";
        }
    }
    return "No";
}
int main() {
	
    int t;
    cin>>t;
    while(t--){
        int n,tar;
        cin>>n>>tar;
        vector<int> arr(n);
        for(int i=0;i<n;i++){
            cin>> arr[i];
        } 
        cout<<process(arr,tar)<<endl;
    }
	return 0;
}