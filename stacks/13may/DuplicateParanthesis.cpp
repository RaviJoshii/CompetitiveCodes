// https://www.geeksforgeeks.org/find-expression-duplicate-parenthesis-not/
// Find if an expression has duplicate parenthesis or not

#include<bits/stdc++.h>
using namespace std;
string duplicateParantheisis(string s){

    stack<char> st;
    for(int i=0;i<s.length();i++){
        if(s[i]==')'){
            int count=0;
            while(st.top()!='('){
                count++;
                st.pop();
            }
            st.pop();
            if(count<1){
                return "Yes";
            }
        }else{
            st.push(s[i]);
        }
    }
    return "No";

}
int main(){

    string s;
    cin>>s;
    cout<<duplicateParantheisis(s)<<endl;

}