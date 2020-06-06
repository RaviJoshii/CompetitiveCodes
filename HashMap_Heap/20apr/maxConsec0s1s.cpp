// https://www.geeksforgeeks.org/maximum-consecutive-ones-or-zeros-in-a-binary-array/
// Maximum consecutive one’s (or zeros) in a binary array

#include <bits/stdc++.h>
using namespace std;


int main(){
    // int n;
    // cin>>n;
    vector<int> vec={1,0,0,1,1, 1,0, 0,0,0,0,0, 1, 0,1,1,1,1,1,1,1, 0, 1, 1, 1, 1};
    for(int i=0;i<vec.size();i++){
        cin>>vec[i];
    }
    int maxC0=0;
    int maxC1;
    int c0=0;
    int c1=0;
    for(int i=0;i<vec.size();i++){
        if(vec[i]==1){
            c0=0;
            c1++;
            maxC1=max(maxC1,c1);
        }
        else{
            //0;
            c1=0;
            c0++;
            maxC0=max(maxC0,c0);
        }
    }
    cout<<"max 0 sequence: "<<maxC0<<endl;
    cout<<"max 1 sequence: "<<maxC1<<endl;
    
}