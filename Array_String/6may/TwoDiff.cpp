// https://www.geeksforgeeks.org/find-a-pair-with-the-given-difference/
// Find a pair with the given difference
//two pointer approach
#include <bits/stdc++.h>
using namespace std;
int process(vector<int> &arr,int tar){
    sort(arr.begin(),arr.end());
    int i=0;
    int j=1;
    while(i<arr.size()&&j<arr.size()){
        if(i==j){
            j++;
            continue;
        }
        if(arr[j]-arr[i]<tar){
            j++;
        }
        else if(arr[j]-arr[i]>tar){
            i++;
        }else {
            // gets the pair
            return 1;
            
        }
    }
    return -1;
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