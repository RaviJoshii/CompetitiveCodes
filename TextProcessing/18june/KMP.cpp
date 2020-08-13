// https://www.geeksforgeeks.org/kmp-algorithm-for-pattern-searching/
// KMP Algorithm for Pattern Searching
// https://cp-algorithms.com/string/prefix-function.html
#include<bits/stdc++.h>
using namespace std;

int main(){
    string str,pat;
    cin>>str>>pat;
    str=pat+"#"+str;
    vector<int> lps(str.length(),0);
    lps[0]=0;
    int len=0;
    ///implenting lps array
    for(int i=1;i<str.length();i++){
        int len=lps[i-1];

        while(len > 0 && str[i]!=str[len] ){
            len=lps[len-1];
        }

        // len can be 0 or str[len]==str[i]
        if(len==0){
            if(str[len]==str[i]){
                lps[i]=1;
            }else{
                lps[i]=0;
            }
        }else{
             lps[i]=len+1;
        }



        //can also try this after the while loop -alternative 
        
        // if (str[i] == str[len])
        //     len++;
        // lps[i] = len;
    }
   for(int i=0;i<lps.size();i++){
       cout<<lps[i]<<" ";
   }
   cout<<endl;


    int count=0;// count of number of times pattern occured in the given string 
    for(int i=0;i<lps.size();i++){
        if(lps[i]==pat.length()){
            count++;
        }
    }

    cout<<count;


    return 0;

}