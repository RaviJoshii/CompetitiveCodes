
// https://www.geeksforgeeks.org/minimum-number-swaps-required-sort-array/
// Minimum number of swaps required to sort an array
#include<bits/stdc++.h>
using namespace std;
int minSwaps(int a[], int n){
    vector<vector<int>> v(n,vector<int>(2));
    for(int i=0;i<n;i++){
        //pair<int,int> pairs={a[i],i};
        v[i][0]=a[i];
        v[i][1]=i;
    }
    sort(v.begin(),v.end());
    vector<bool> visited(n,false);
    int sum=0;
    for(int i=0;i<n;i++){
        int cycle=0;
        if (visited[i] || v[i][1] == i) 
        {   
            cycle=1;// cycle length=1;
        }else{
            int j=i;
            while(visited[j]==false){
                visited[j]=true;
                j=v[j][1];
                cycle++;
            }

        }
        
        if(cycle>0){
            sum+=cycle-1;
        }
    }
    return sum;
}
int main(){
    int a[]={10,50,40,60,20,30};
    int n=6;
    cout<<minSwaps(a,n);
    return 0;
}