// https://www.codechef.com/submit/FLOW016
// GCD and LCM
#include <iostream>
using namespace std;
typedef long long ll;
ll gcd(ll a ,ll b){
    if(b==0){
        return a;
    }
    return gcd(b,a%b); 
}
int main() {
	int t;
	cin>>t;
    while(t--){
        ll a;
        ll b;
        cin>>a>>b;
        ll gcds=gcd(a,b);
        ll lcm=(a*b)/gcds;
        cout<<gcds<<" "<<lcm<<endl;
    }
	
	return 0;
}
