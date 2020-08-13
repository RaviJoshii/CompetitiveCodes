#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> kthSmallestPrimeFraction(vector<int>& A, int K) {
        double lo=0;
        double hi=1;
        
        while(true){
            int p=0;
            int q=1;
            int count=0;
            double mid=(hi+lo)/(2.0);
            int j=1;
            int temp=A.size()-j;
            for(int i=0;i<A.size();i++){
                while(j<A.size() && A[i]*(1.0)>A[j]*mid){
                    j++;
                    temp--;
                }   
                count+=temp;
                if(j<A.size() && (p*A[j]<q*A[i])){
                    // cout<<"h: "<<A[i]<<" - "<<A[j]<<endl;
                    p=A[i];
                    q=A[j];
                }
            }
            // cout<<mid<<"  count:"<<count<<endl;
            
            if(count>K){
                hi=mid;
            }else if(count<K){
                lo=mid;
            }else if(count==K){
                // cout<<p<<" - "<<q<<endl;
                vector<int> ans={p,q};
                return ans;

            }

            //now here if count!=k then we will find new mid, which can be gives count==k
            
        }
        
    }
};
int main(){
    vector<int> vec={1,2,3,5};
    int c=3;
    Solution s;
    s.kthSmallestPrimeFraction(vec,c);

    return 0;
}