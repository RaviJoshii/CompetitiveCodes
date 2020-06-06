// https://leetcode.com/problems/largest-rectangle-in-histogram/
// Largest Rectangle in Histogram
// https://abhinandandubey.github.io/posts/2019/12/15/Largest-Rectangle-In-Histogram.html
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        if(heights.size()==0){
            return 0;
        }
        stack<int> st;
        st.push(0);
        int ans=0;
        for(int i=1;i<heights.size();i++){
            while(st.size()>0 && heights[i]<heights[st.top()]){
                int NSR=i; //right smaller index
                int NSL=-1; //left smaller default value

                int num=heights[st.top()]; st.pop();//popped
                if(st.size()>0){
                    NSL=st.top();
                    
                }
                ans=max(ans,(NSR-NSL-1)*num);

            }
            
        }
        //rs is always 0;
        int NSR=heights.size();//default values
        while(st.size()>0){
            int NSL=-1;
            
            int num=heights[st.top()]; st.pop();
            if(st.size()>0){
                NSL=st.top();
            }
            // cout<<num<<" "<<NSL<<" "<<NSR<<endl;
            
            ans=max(ans,(NSR-NSL-1)*num);

        }
        // cout<<ans;
        return ans;
    }
};

int main(){
    Solution s;
    vector<int> arr={0,1,0,1};
    cout<<s.largestRectangleArea(arr);

    return 0;
}