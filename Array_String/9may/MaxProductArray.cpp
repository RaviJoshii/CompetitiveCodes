// https://leetcode.com/problems/maximum-product-subarray/submissions/
// Maximum Product Subarray
#include<bits/stdc++.h>
using namespace std;
class Solution1 {
public:
    int maxProduct(vector<int>& nums) {
        if(nums.size()==0){
            return 0;
        }
        
        
        int Pprod=nums[0];
        int Nprod=nums[0];
        int ans=nums[0];
        for(int i=1;i<nums.size();i++){
            if(nums[i]>0){
                Pprod=max(nums[i],nums[i]*Pprod);
                Nprod=min(nums[i],nums[i]*Nprod);
            }else{ //nums[i]<0
                int temp=Pprod;
                Pprod=max(nums[i],nums[i]*Nprod);
                Nprod=min(nums[i],nums[i]*temp);                
            }
            ans=max(ans,Pprod);
        }
        
        return ans;
    }
};

//solution 2

class Solution2 {
public:
    int maxProduct(vector<int>& nums) {
        if(nums.size()==0){
            return 0;
        }
        
        int Cprefix=1;
        int Csuffix=1;
        int maxPrefix=INT_MIN;
        int maxsuffix=INT_MIN;
        bool is0Present=false;
        int leftI=0;
        int rightI=nums.size()-1;
        while(leftI<nums.size() && rightI>=0){
            if(nums[leftI]==0){
                is0Present=true;
                //reseting the prefix  product
                Cprefix=1;
                
            } else{
                Cprefix=Cprefix*nums[leftI];
                maxPrefix=max(maxPrefix,Cprefix);
            }



            //calculating suffix
            if(nums[rightI]==0){
                is0Present=true;
                //reseting the suffix product
                Csuffix=1;
            } else{
                Csuffix=Csuffix*nums[rightI];
                 maxsuffix=max(maxsuffix,Csuffix);
            }

            
           
            leftI++;
            rightI--;
        }
        int ans;
        if(is0Present==true){
            ans=max(0,max(maxPrefix,maxsuffix));
        }
        else{
            ans= max(maxPrefix,maxsuffix);
        }
        return ans;
    }
};