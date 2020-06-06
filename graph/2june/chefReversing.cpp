// https://www.codechef.com/problems/REVERSE
// Chef and Reversing
#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,m;
    cin>>n>>m;
    vector<bool> vis(n+1,false);
    vector<vector<pair<int,int>>> graph(n+1);
    for(int i=0;i<m;i++){
        int x;int y;
        cin>>x>>y;
        graph[x].push_back(make_pair(y,0));
        graph[y].push_back(make_pair(x,1));
    }

    list<pair<int,int> > lis;
    int src=1;
    int dest=n;
    int ans=0;
    lis.push_front(make_pair(src,0));
    while(lis.size()>0){
        pair<int,int> rem=lis.front();
        lis.pop_front();
        if(rem.first==dest){
            cout<<rem.second<<endl;
            // break;
            return 0;
        }
        vis[rem.first]=true;

        
        for(auto pairs:graph[rem.first]){
            
            if(vis[pairs.first]==false){
                int newCost=pairs.second+rem.second;
                pair<int,int> temp;
                temp.second=newCost;
                temp.first=pairs.first;
                if(temp.second==rem.second){
                    
                    lis.push_front(temp);
                }else{
                    // pairs.second+=rem.second;
                    lis.push_back(temp);
                }
            }
        }
    }
    cout<<"-1"<<endl;
    return 0;
}