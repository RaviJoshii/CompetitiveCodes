// https://leetcode.com/problems/car-fleet/
//  Car Fleet
#include<bits/stdc++.h>
using namespace std;
class items{
    public:
    int pos;
    double time;
    items(int pos,double time){
        this->pos=pos;
        this->time=time;
    }

};
class mycomp{
    public:
    int operator()(const items &i1, const items &i2){
        return i1.pos<i2.pos;
    }
};
class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        if(position.size()==0){
            return 0;
        }
        vector<items> myitem;
        for(int i=0;i<position.size();i++){
            int dis=target-position[i];
            double time=(dis*(1.0))/speed[i];
            myitem.push_back(items(position[i],time));
        }
        sort(myitem.begin(),myitem.end(),mycomp());

        double mintime=myitem.back().time;
        int ans=1;

        for(int i=myitem.size()-2;i>=0;i--){
            if(myitem[i].time>mintime){
                ans++;
                mintime=myitem[i].time;
            }
        }
        return ans;
        
    }
};
int main(){
    int target = 12;
    vector<int> position = {10,8,0,5,3};
    vector<int> speed = {2,4,1,1,3};
    Solution s;
    cout<<s.carFleet(target,position,speed);
    return 0;
}