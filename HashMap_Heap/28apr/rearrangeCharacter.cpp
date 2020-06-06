// https://practice.geeksforgeeks.org/problems/rearrange-characters/0
// Rearrange characters

#include <bits/stdc++.h>
using namespace std;
class item{
    public:
    char ch;
    int freq;
    item(char c,int freq){
        this->ch=c;
        this->freq=freq;
    }
    item(){

    }
    bool operator<(const item &i1)const{
        return this->freq<i1.freq;
    }

};
int process(string s){
    priority_queue<item> pq;
    unordered_map<char,int> umap;
    for(char c:s){
        umap[c]++;
    }
    for(auto it:umap){
        pq.push(item(it.first,it.second));
    }

    string RearrangedString="";
    if(pq.size()<1){
        return 1;
    }

    item rem=pq.top();
    pq.pop();
    rem.freq=rem.freq-1;
    RearrangedString=RearrangedString+rem.ch;
    item prev=rem;
    while(pq.size()>0){
        rem=pq.top();
        pq.pop();
        rem.freq=rem.freq-1;
        RearrangedString=RearrangedString+rem.ch;
        if(prev.freq>0){
            pq.push(prev);
        }
        prev=rem;
    }
    // cout<<RearrangedString<<endl;
    if(prev.freq>0){
        return 0;
    }
    return 1;
}
int main() {
    int t;
    cin>>t;
    while(t--){
        string s;
        cin>>s;
        cout<<process(s)<<endl;
    }
}