// https://practice.geeksforgeeks.org/problems/longest-palindrome-in-a-string/0
// https://www.hackerearth.com/practice/algorithms/string-algorithm/manachars-algorithm/tutorial/

#include<bits/stdc++.h>
using namespace std;
void convertToNewString(string &s) {
    string newString = "@";

    for (int i = 0; i < s.size(); i++) {
        newString += "#" + s.substr(i, 1);
    }

    newString += "#$";
    s=newString;
}
vector<int> manchers(string s){
    convertToNewString(s);
    vector<int> p(s.length());
    int c=0;
    int r=0;
    for(int i=0;i<s.length();i++){
        int mirr=2*c-i;
        if(i<r){
            p[i]=min(p[mirr],r-i);
        }

        while(s[i-p[i]-1]==s[i+p[i]+1]){
            p[i]++; 
        }

        if(p[i]+i>r){
            r=p[i]+i;
            c=i;
        }
    }
    return p;
}
int main(){
    int t;
    cin>>t;
    while(t--){
        string s;
        cin>>s;
        vector<int> p=manchers(s);
        int maxPalindrome = 0;
        int centerIndex = 0;

        for (int i = 0; i < p.size(); i++) {
            if (p[i] > maxPalindrome) {
                maxPalindrome = p[i];
                centerIndex = i;
            }
        }
        // cout<<maxPalindrome<<" - "<<centerIndex<<endl;
        cout<<s.substr( (centerIndex - 1 - maxPalindrome) / 2, maxPalindrome)<<endl;
    }
    return 0;
}

// #b      #a#c # c#a#      d#  centre =6, max palidrome= 4
// #b     #a#c# d #c#a#      d# centre =7, max palidrome= 5