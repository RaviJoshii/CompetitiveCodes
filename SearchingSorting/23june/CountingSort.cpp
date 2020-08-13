// https://practice.geeksforgeeks.org/problems/largest-even-number/0
// Largest Even Number
#include<bits/stdc++.h>
using namespace std;

vector<int> countingSort(vector<int> num){
    // finding maximum number in given array
    int maxi=INT_MIN;
    for(int i=0;i<num.size();i++){
        if(num[i]>maxi){
            maxi=num[i];
        }
    }
    //finding the frequency of each element
    vector<int> arr(maxi+1,0);
    for(int i=0;i<num.size();i++){
        arr[num[i]]++;
    }
    //finding prefix sum
    for(int i=1;i<arr.size();i++){
        arr[i]+=arr[i-1];
    }

    //finding sorted array
    vector<int> ans(num.size());
    for(auto data:num){
       int pos=arr[data];
       arr[data]--;
       ans[pos-1]=data;
    }
    
    return ans;
}
int main(){
    int t;
    cin>>t;
    while(t--){
        
        vector<int> num;
        string s;
        cin>>s;

        
        for(int i=0;i<s.length();i++){
            int nos=s[i]-'0';
            num.push_back(nos);
        }
        vector<int> ans=countingSort(num);

        
        //reverse the number
        int lo=0;
        int hi=ans.size()-1;
        while(lo<hi){
            swap(ans[lo],ans[hi]);
            lo++;
            hi--;
        }
        
        //swaping for getting the correct answer
        if(ans.back()%2!=0){
            for(int i=ans.size()-1;i>=0;i--){
                if(ans[i]%2==0){
                    int x=ans[i];
                    ans.erase(ans.begin()+i);
                    ans.push_back(x);
                    break;
                }
            }
        }
        for(int num:ans){
            cout<<num;
        }
        cout<<endl;

    }
    return 0;
}