// https://www.geeksforgeeks.org/find-the-number-of-jumps-to-reach-x-in-the-number-line-from-zero/
// Find the number of jumps to reach X in the number line from zero
#include<bits/stdc++.h>
using namespace std;
int getSum(int x){
    return (x*(x+1))/2;
}
int process(int x){
    // First make number positive 
    // Answer will be same either it is 
    // Positive or negative 
    x=abs(x);
    int jumps=0;
    int distance_so_far=0;
    while(distance_so_far<x){
        jumps++;
        distance_so_far+=jumps;
    }
    if(distance_so_far==x){
        return jumps;
    }
    int diff=distance_so_far-x;
    if(diff%2==0){
        //even 
        return jumps;
    }else{
        //first jump required
        jumps++;
        distance_so_far+=jumps;
        diff=distance_so_far-x;
        if(diff%2==0){
            return jumps;
        }else{
            //last jump 
            //diff always becomes even
            jumps++;
            return jumps;
        }
        
    }
}
int main(){
    int x;
    cin>>x;
    cout<<process(x);
    return 0;
}