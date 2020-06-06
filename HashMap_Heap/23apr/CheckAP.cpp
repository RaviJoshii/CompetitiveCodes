// https://www.geeksforgeeks.org/check-whether-arithmetic-progression-can-formed-given-array/
// Check Arithmetic Progression
#include <bits/stdc++.h>
using namespace std;

bool checkAP(vector<int> &vec,int a,int b,unordered_map<int,int> &umap){
        int n=vec.size();
        int cd=b-a;
        if(cd==0){
            //all elements of array should be equal;
            for(int i=0;i<n;i++){
                if(vec[i]!=a){
                    return false;
                }
            }
            return true;
        }
        else{
            umap.erase(a);
            umap.erase(b);
            int nextNum=b+cd;
            while(true){
                if(umap.find(nextNum)!=umap.end()){
                    umap.erase(nextNum);
                    nextNum=nextNum+cd;
                }
                else{
                    break;
                }

            }
            if(umap.size()>0){
                return false;
            }
            else{
                return true;
            }
        }
        
}

int main() {
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> vec(n);
        int a=INT_MAX;
        int b=INT_MAX;

        unordered_map<int,int> umap;
        for(int i=0;i<n;i++){
            cin>>vec[i];
            if(vec[i]<a){
                b=a;
                a=vec[i];
            }
            else if(vec[i]<b){
                b=vec[i];
            }

            umap[vec[i]]=1;
        }

        if(checkAP(vec,a,b,umap)){
            cout<<"YES"<<endl;
        }
        else{
            cout<<"NO"<<endl;
        }
        
        
    }
	return 0;
}