// https://practice.geeksforgeeks.org/problems/reverse-first-k-elements-of-queue/1
// Reverse First K elements of Queue

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
queue<ll> modifyQueue(queue<ll> q, int k)
{   
    ll n = q.size();

    stack<ll> st;
    for(int j=0;j<k;j++)
    {   ll num=q.front();
        st.push(num);
        q.pop();
    }
    
    while(st.size()>0){
        q.push(st.top());
        st.pop();
    }


    for(int j=0;j<(n-k);j++){
        q.push(q.front());
        q.pop();
    }
    return q;
}
int main(){
    queue<ll> que;
    int n,k;
    cin>>n>>k;

    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        que.push(x);
    }
    queue<ll> anse=modifyQueue(que,k);
    while(anse.size()>0){
        cout<<anse.front()<<" ";
        anse.pop();
    }
    return 0;
}