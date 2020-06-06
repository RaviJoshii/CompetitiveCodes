// https://leetcode.com/problems/employee-free-time/
// Employee Free Time
// https://www.codertrain.co/employee-free-time
// https://aaronice.gitbooks.io/lintcode/high_frequency/employee-free-time.html
#include<bits/stdc++.h>
using namespace std;
class emp{
    public:
    int start,end;
    int r,c;
    emp(int s,int e,int i,int j){
        this->start=s;
        this->end=e;
        this->r=i;
        this->c=j;
    }
    bool operator<(const emp &p1){
        return this->start<p1.start;
    }
};
void process(vector<vector<vector<int>>> &matrix){
    vector<vector<int>> res;
    priority_queue<emp> pq;
    for(int i=0;i<matrix.size();i++){
        for(int j=0;j<matrix[i].size();j++){
            if(matrix[i][j].size()<1) continue;
            pq.push(emp(matrix[i][j][0],matrix[i][j][1],i,j));
        }
    }
}
int main(){
    vector<vector<vector<int>>> matrix={{{1,3},{6,7}},{{2,4}},{{2,5},{9,12}}};
    process(matrix);
    return 0;

}