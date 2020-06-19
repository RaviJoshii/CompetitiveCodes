// https://leetcode.com/problems/sliding-puzzle/
// Sliding Puzzle


#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int findZeroIndex(string str){
        for(int i=0;i<str.length();i++){
            if(str[i]=='0'){
                return i;
            }
        }
        return str.length();
    }
    int slidingPuzzle(vector<vector<int>>& board) {
        string finals="123450";
        string initial="";
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[i].size();j++){
                initial+=to_string(board[i][j]);
            }
        }
        if(finals==initial){
            return 0;
        }
        unordered_set<string> visited;
        unordered_map<int,vector<int>> umap;
        umap[0]={1,3};
        umap[1]={0,2,4};
        umap[2]={1,5};
        umap[3]={0,4};
        umap[4]={1,3,5};
        umap[5]={2,4};
        queue<pair<string,int >> que;
        que.push(make_pair(initial,0));
        visited.insert(initial);

        while(que.size()>0){
            pair<string, int> rem=que.front();
            que.pop();
            if(rem.first==finals){
                return rem.second;
            }
            int idx=findZeroIndex(rem.first);
            vector<int> its=umap[idx];
            for(int sidx:its){
                string newString=rem.first;
                swap(newString[idx],newString[sidx]);
                if(visited.count(newString)==0){
                    visited.insert(newString);
                    que.push(make_pair(newString,rem.second+1));
                }
            }

        }
        return -1;

    }
};
int main(){

    Solution s;
    vector<vector<int>> board = {{3,2,4},{1,5,0}};
    cout<<s.slidingPuzzle(board);
    return 0;
}