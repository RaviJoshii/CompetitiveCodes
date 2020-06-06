#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int main() {
	int t;
    cin>>t;
    while(t--){
        int n,m;
        cin>>m>>n;
        int last=sqrt(n);
        vector<bool> rootN(last+1,true);
        vector<bool> Difference(n-m+1,true);
        for(int i=2;i*i<rootN.size();i++){
            if(rootN[i]){
                for(int j=i*i;j<rootN.size();j=j+i){
                    rootN[j]=false;
                }
            }
        }
        for(int i=2;i<rootN.size();i++){
            if(rootN[i]==true){
                int num=-1;
                // finding its first multiple
                for(int j=0;j<Difference.size();j++){
                    if((j+m)%i==0 && (j+m!=i)){
                        num=j;
                        break;
                    }
                }
                
                if(num==-1) {continue;}
                for(int k=num;k<Difference.size();k+=i){
                    Difference[k]=false;
                }
            }
        }

        for(int i=0;i<Difference.size();i++){
            if(Difference[i]){
                if((i+m)==1){continue;}
                cout<<i+m<<endl;
            }
        }
        cout<<endl;
    }
	return 0;
}