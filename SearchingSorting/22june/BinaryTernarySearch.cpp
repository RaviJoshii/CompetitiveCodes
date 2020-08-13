#include<bits/stdc++.h>
using namespace std;


// binary search
int BS(vector<int> &vec,int k) 
{ 
    int lo=0;
    int hi=vec.size()-1;
    while(lo<=hi){
        int mid=lo+(hi-lo)/2;
        if(vec[mid]==k){
            return mid;
        }else if(vec[mid]<k){
            lo=mid+1;
        }else{
            hi=mid-1;
        }
    }
    return -1;
    
} 





// Ternary search
int TS(vector<int> &vec,int k) 
{ 
    int lo=0;
    int hi=vec.size()-1;
    while(lo<=hi){
        int mid1=lo+(hi-lo)/3;
        int mid2=hi-(hi-lo)/3;

        if(vec[mid1]==k){
            return mid1;
        }else if(vec[mid2]==k){
            return mid2;
        }
        else if(k<vec[mid1]){
            hi=mid1-1;
        }else if(k>vec[mid2]){
            lo=mid2+1;
        }else{
            lo=mid1+1;
            hi=mid2-1;
        }
    }
    return -1;
    
} 