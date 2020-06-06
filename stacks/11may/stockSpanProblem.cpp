// https://www.geeksforgeeks.org/the-stock-span-problem/
// The Stock Span Problem

#include <iostream>
#include<vector>
#include<stack>
using namespace std;
      
    void nextgreaterelement(vector<int>& nums){
        vector<int> ans(nums.size(),0);
        // if(nums.size()==0){
        //     return ans;
        // }
        stack<int> st;
        st.push(nums.size()-1);
        for(int i=nums.size()-2;i>=0;i--){
            int num = nums[i];
            while(st.size()>0 && nums[st.top()]<num){
                ans[st.top()]=st.top()-i;
                st.pop();
            }
            st.push(i);
        }
        while(st.size()>0){
            ans[st.top()]=st.top()+1;
            st.pop();
        }
        for(int e: ans){
            cout<<e<<" ";
        }
    }
    
int main() {
      int t;
      cin>>t;
	    while(t--){
	        int n;
	        cin>>n;
	        vector<int> arr(n);
	        for(int j=0; j<n; j++){
	            cin>>arr[j];
	        }
	        nextgreaterelement(arr);
	        cout<<endl;
	    }
	return 0;
}