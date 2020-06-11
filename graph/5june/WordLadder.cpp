// https://leetcode.com/problems/word-ladder/
// 127. Word Ladder
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> visited(wordList.begin(),wordList.end());
        queue<pair<string,int>> que;
        que.push(make_pair(beginWord,0));
        

        while(que.size()>0){
            pair<string,int> rem=que.front();que.pop();
            string word=rem.first;
            int transform=rem.second;

            if(word==endWord){
                return transform+2;
            }

            for(int i=0;i<word.length();i++){
                string tempword=word;
                for(int j=0;j<26;j++){
                    char ch='a'+j;
                    tempword[i]=ch;
                    if(visited.find(tempword)!=visited.end()){
                        visited.erase(tempword);
                        que.push(make_pair(tempword,transform+1));
                    }
                }    
            }
        }
            return 0;
            
        }
};



int main(){
    vector<string> vec={"hot","dot","dog","lot","log","cog"};
    Solution s;
    cout<<s.ladderLength("hit","cog",vec);
    return 0;
}