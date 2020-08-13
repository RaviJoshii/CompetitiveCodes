// https://www.geeksforgeeks.org/minimum-number-of-bracket-reversals-needed-to-make-an-expression-balanced/
// Minimum number of bracket reversals needed to make an expression balanced
#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        string s;
        cin>>s;
        stack<char> st;

        st.push('#');
        for(int i=0;i<s.length();i++){
            if(s[i]=='}'){
                if(st.top()=='{'){
                    st.pop();
                }else{
                    st.push(s[i]);
                }
            }else{
                st.push(s[i]);
            }
        }

        int oc=0;
        int cc=0;

        while(st.top()!='#'){
            if(st.top()=='}'){
                cc++;
            }else{
                oc++;
            }
            st.pop();
        }
        
        if((oc+cc)%2!=0){
            cout<<-1<<endl;
        }else if(oc%2==0 && cc%2==0){
            cout<<((oc/2) + (cc/2) )<<endl;

        }else{
            cout<< ((oc-1)/2 + (cc-1)/2)+2<<endl;
        }
    }
    return 0;
}