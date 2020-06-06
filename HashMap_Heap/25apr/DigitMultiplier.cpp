// https://practice.geeksforgeeks.org/problems/digit-multiplier/0
// Digit multiplier

#include <bits/stdc++.h>
using namespace std;
void process(long  n){
    if(n<10){
        cout<<n<<endl;
        return;
    }
    long long mul=1;
    long long ans=0;
    vector<int> res;
    for(int i=9;i>=2;i--){
            while(n%i==0){
                n=n/i;
                res.push_back(i);
            }
        
        
    }
    if(n>9){
        cout<<"-1"<<endl;
    } else{
        for(int i=res.size()-1;i>=0;i--){
            cout<<res[i];
        }
        cout<<endl;
    }

}
int main() {
	int t;
	cin>>t;
	while(t--){
	    long n;
	    cin>>n;
	    process(n);
	}
	return 0;
}