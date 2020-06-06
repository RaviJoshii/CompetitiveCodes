// https://leetcode.com/problems/k-closest-points-to-origin/
// K Closest Points to Origin

#include <bits/stdc++.h>
using namespace std;
class pairs{
    public:
    int idx;
    long long dis;
    pairs(int idx,int dis){
        this->idx=idx;
        this->dis=dis;
    }
    bool operator<(const pairs &p2)const{
        return this->dis<p2.dis;
    }
};
// class mycom{
//     public: 
//     int operator()(const pairs &p1,const pairs &p2){
//         return p1.dis<p2.dis;
//     }
// };
class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
        priority_queue<pairs> pq; 
        long long dist;
        for(int i=0;i<K;i++){
            dist=points[i][0]*points[i][0]+points[i][1]*points[i][1];
            pq.push(pairs(i,dist));
        }
        for(int i=K;i<points.size();i++){
            dist=points[i][0]*points[i][0]+points[i][1]*points[i][1];
            if(dist<pq.top().dis){
                pq.pop();
                pq.push(pairs(i,dist));
            }
        }
        vector<vector<int>> ans;
        while(pq.size()>0){
            int idx1=pq.top().idx;
            ans.push_back(points[idx1]);
            pq.pop();
        }
        return ans;
    }
};
int main(){
    vector<vector<int>> vec{{3,3},{5,-1},{-2,4}};
    int K = 2;
    Solution s;
    vector<vector<int >> vec2=s.kClosest(vec,K);
    for(vector<int> r:vec2){
        for(int p:r){
            cout<<p<<" ";
        }
        cout<<endl;
    }
    
}