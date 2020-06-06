// https://www.geeksforgeeks.org/next-greater-element/
// Next Greater Element

#include <iostream>
#include<vector>
#include<stack>
using namespace std;
      
    void nextgreaterelement(vector<long long>& nums){
        vector<long long> ans(nums.size(),0);
        // if(nums.size()==0){
        //     return ans;
        // }
        stack<long long> st;
        st.push(0);
        for(int i=1;i<nums.size();i++){
            long long num = nums[i];
            while(st.size()>0 && nums[st.top()]<num){
                ans[st.top()]=num;
                st.pop();
            }
            st.push(i);
        }
        while(st.size()>0){
            ans[st.top()]=-1;
            st.pop();
        }
        for(long long e: ans){
            cout<<e<<" ";
        }
    }
    
int main() {
      int t;
      cin>>t;
	    while(t-- > 0){
	        int n;
	        cin>>n;
	        vector<long long> arr(n, 0);
	        for(int j=0; j<n; j++){
	            cin>>arr[j];
	        }
	        nextgreaterelement(arr);
	        cout<<endl;
	    }
	return 0;
}