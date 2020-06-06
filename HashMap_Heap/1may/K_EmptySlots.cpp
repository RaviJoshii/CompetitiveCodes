// https://stackoverflow.com/questions/46393470/find-earliest-time-for-k-empty-group
// https://leetcode.com/problems/k-empty-slots/
// https://www.lintcode.com/problem/k-empty-slots/description
// K Empty Slots


#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    /**
     * @param flowers: the place where the flower will open in that day
     * @param k:  an integer
     * @return: in which day meet the requirements
     */
    int kEmptySlots(vector<int> &flowers, int k) {
        int ans=INT_MAX;
        vector<int> arr(flowers.size());
        for(int i=0;i<flowers.size();i++){
            arr[flowers[i]-1]=i;
        }
        // for(int i=0;i<arr.size();i++){
        //     cout<<arr[i]<<" ";
        // }
        // cout<<endl;
        
        int left=0;
        int right=left+k+1;
        int temp=left;
        while(right<arr.size()){
                // cout<<temp<<" / "<<right<<endl;
                
                if(arr[temp]<=arr[left] || arr[temp]<=arr[right]){
                    
                    if(temp==right){
                        //we got our subarray- collect the answer
                        // cout<<temp<<" / "<<right<<endl;
                        ans=min(ans,max(arr[left],arr[right]));
                        left=right;
                        temp=left;
                        right=left+k+1;
                    } else{
                        //invalid subarray
                        left=temp;
                        temp=left;
                        right=left+k+1;
                    }
                }
                temp++;
            
        }
        if(ans==INT_MAX){
            return -1;
        }
        return ans+1;
    }
};
int main(){
    vector<int> vec={1,3,2};
    int k=1;
    Solution s;
    cout<<s.kEmptySlots(vec,k);
    return 0;
}