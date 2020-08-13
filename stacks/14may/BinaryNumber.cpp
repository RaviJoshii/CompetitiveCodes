// https://practice.geeksforgeeks.org/problems/generate-binary-numbers/0
// Generate Binary Numbers
#include<bits/stdc++.h>
using namespace std;

int main(){
//    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;

        int counter=1;
        list<string> que;
        que.push_back("1");
        while(1){
            if(counter>n){
                break;
            }
            counter++;
            string str=que.front();
            que.pop_front();
            cout<<str<<" ";
            que.push_back(str+"0");

            que.push_back(str+"1");

        }
        cout<<endl;
        

    }
    return 0;
}