// https://leetcode.com/problems/line-reflection/
// https://www.lintcode.com/problem/line-reflection/description
// Line Reflection
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    /**
     * @param points: n points on a 2D plane
     * @return: if there is such a line parallel to y-axis that reflect the given points
     */
    bool isReflected(vector<vector<int>> &points) {
        // Write your code here
        int leftX=INT_MAX;
        int RightX=INT_MIN;
        unordered_map<string,int> umap;
        for(int i=0;i<points.size();i++){
            string s=to_string(points[i][0])+"#"+to_string(points[i][1]);
            umap[s]++;
            if(points[i][0]<leftX){
                leftX=points[i][0];
            }
            if(points[i][0]>RightX){
                RightX=points[i][0];
            }
            
        }
        double mid=((RightX+leftX)*(1.0))/2;
        // cout<<mid<<endl;
        for(int i=0;i<points.size();i++){
            string s=to_string(points[i][0])+"#"+to_string(points[i][1]);
            if(umap.find(s)!=umap.end()){
                int x1=points[i][0];
                int x2=2*mid-x1;
                int y=points[i][1];
                string check=to_string(x2)+"#"+to_string(y);
                if(umap.find(check)!=umap.end()){
                    umap.erase(s);
                    umap.erase(check);
                }
                else{
                    return false;
                }
            }
        }
        return true;
    }
};
int main(){
    vector<vector<int> > points={{0,0},{1,0}};
    Solution s;
    cout<<s.isReflected(points);
    return 0;
}