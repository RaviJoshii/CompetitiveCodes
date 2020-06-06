// https://www.geeksforgeeks.org/length-largest-subarray-contiguous-elements-set-1/
// Length of the largest subarray with contiguous elements | Set 1

#include<bits/stdc++.h>
using namespace std;

int min(int x, int y) { return (x < y)? x : y; } 
int max(int x, int y) { return (x > y)? x : y; } 

int process(vector<int> &vec){
    int lenMax=1;
    for(int i=0;i<vec.size()-1;i++){
        int mins=vec[i];
        int maxs=vec[i];
        for(int j=i+1;j<vec.size();j++){
            maxs=max(maxs,vec[j]);
            mins=min(mins,vec[j]);

            if((maxs-mins)==(j-i)){
                lenMax=max(lenMax,maxs-mins+1);
            }
        }
    }
    return lenMax;
}
int main(){
    vector<int> vec={1, 56, 58, 57, 90, 92, 94, 93, 91, 45};
    cout<<process(vec)<<endl;
}