// https://leetcode.com/problems/multiply-strings/
// Multiply Strings
// https://leetcode.com/problems/multiply-strings/discuss/17605/Easiest-JAVA-Solution-with-Graph-Explanation

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string multiply(string num1, string num2) {
        
        vector<int> ans(num1.size()+num2.size(),0);
        string str="";
        for(int j=num2.size()-1;j>=0;j--){
            for(int i=num1.size()-1;i>=0;i--){
                int idx1=i+j;
                int idx2=i+j+1;
                int prod=(num1[i]-'0')*(num2[j]-'0')  + ans[idx2];
                int carry=prod/10;
                int rem=prod%10;

                ans[idx1]+=carry;
                ans[idx2]=rem; //imp
            }
        }
        int k=0;
        while(k<ans.size() && ans[k]==0){
            k++;
        }
        for(int i=k;i<ans.size();i++){
            str+=to_string(ans[i]);
        }
        if(str.size()==0){
            return "0";
        }
        return str;
int main(){
    Solution s;
    cout<<s.multiply("0","0");

    return 0;
}