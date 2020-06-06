// https://www.geeksforgeeks.org/length-largest-subarray-contiguous-elements-set-2/
// Length of the largest subarray with contiguous elements | Set 2

#include<bits/stdc++.h>
using namespace std;

int min(int x, int y) { return (x < y)? x : y; } 
int max(int x, int y) { return (x > y)? x : y; } 

int process(vector<int> &vec){
    unordered_set<int> sets;
    int lenMax=1;
    for(int i=0;i<vec.size()-1;i++){
        int mins=vec[i];
        int maxs=vec[i];
        unordered_set<int> sets;
        sets.insert(vec[i]);
        for(int j=i+1;j<vec.size();j++){
            if(sets.find(vec[j])!=sets.end()){
                break;
            }
            sets.insert(vec[j]);
            maxs=max(maxs,vec[j]);
            mins=min(mins,vec[j]);

            if((maxs-mins)==j-i){
                lenMax=max(lenMax,maxs-mins+1);
            }
        }
    }
    return lenMax;
}
int main(){
    vector<int> vec={10, 12, 12, 10, 10, 11, 10};
    cout<<process(vec)<<endl;
}