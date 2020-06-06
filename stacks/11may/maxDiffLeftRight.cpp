// https://www.geeksforgeeks.org/find-maximum-difference-between-nearest-left-and-right-smaller-elements/
// Find maximum difference between nearest left and right smaller elements
#include<bits/stdc++.h>
using namespace std;
int findMaxDiff(int arr[], int n)
{
    stack<int> st;
    st.push(0);
    int ans=0;
    for(int i=1;i<n;i++){
        while(st.size()>0 && arr[i]<arr[st.top()]){
            int NSR=0; //right smaller
            int NSL=0; //left smaller
            NSR=arr[i];
            int num=arr[st.top()]; st.pop();//popped

            if(st.size()>0){
                // ls=abs(num-arr[st.top()]);
                NSL=arr[st.top()];
                
                
            }
            
            ans=max(ans,abs(NSR-NSL));
            // cout<<ans<<" ";

        }
        if(st.size()>0 && arr[i]==arr[st.top()]){
            continue;//for removing duplicates
        }else{
            st.push(i);
        }
        
    }
    //rs is always 0;
    int NSR=0;
    while(st.size()>0){
        int NSL=0;
        int num=arr[st.top()]; st.pop();
        
        if(st.size()>0){
            NSL=arr[st.top()];
        }
        ans=max(ans,abs(NSR-NSL));

    }
    // cout<<ans;
    return ans;
}
int main(){
    int n;
    cin>>n;
    int arr[n];
    // int arr[] = {2, 4, 8, 7, 7, 9, 3};
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    findMaxDiff(arr,n);

}