// https://leetcode.com/problems/asteroid-collision/
// Asteroid Collision
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroid) {
        list<int> st;
        for(int i=0;i<asteroid.size();i++){
            if(st.size()==0 ||asteroid[i]>=0 ){
                st.push_back(asteroid[i]);
            }
            else{
                //-ve
                int stackTop=st.back();
                bool flag1=true;
                while(st.size()>0 && st.back()>0){

                    if(st.back()==abs(asteroid[i])){
                        flag1=false;
                        st.pop_back();
                        break;
                    }else if(st.back()>abs(asteroid[i])){
                        flag1=false;
                        break;

                    }else if(st.back()<abs(asteroid[i])){
                        st.pop_back();
                    }
                }
                if(flag1){
                    st.push_back(asteroid[i]);
                }


            }
        }
        vector<int> ans;
        for(auto num: st){
            // cout<<num<<" ";
            ans.push_back(num);
        }
        return ans;
    }
};

int main(){
    vector<int> nums={5, 10, -5};
    Solution s;
    s.asteroidCollision(nums);


    // return 0;
}