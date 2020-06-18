// https://www.spoj.com/problems/CEQU/
// CEQU - Crucial Equation

#include<bits/stdc++.h>
using namespace std;
int Gcd(int a,int b){
    if(b==0){
        return a;
    }
    return Gcd(b,a%b);
}

int main(){
    int t;
    cin>>t;
    for(int i=1;i<=t;i++){
        int n,m,c;
        cin>>n>>m>>c;
        int gcd=Gcd(n,m);
        if(c%gcd==0){
            cout<<"Case "<<i<<":"<<" Yes"<<endl;
        }else{
            cout<<"Case "<<i<<":"<<" No"<<endl;
        }
    }
    return 0;
}