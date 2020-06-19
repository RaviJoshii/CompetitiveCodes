// https://leetcode.com/problems/k-similar-strings/
//  K-Similar Strings
// https://leetcode.com/problems/k-similar-strings/discuss/140099/JAVA-BFS-32-ms-cleanconciseexplanationwhatever

#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int checkForDiffer(string A,string B){
        for(int i=0;i<A.size();i++){
            if(B[i]!=A[i]){
                return i;
            }
        }
        return A.length();
    }
    int kSimilarity(string A, string B) {
        unordered_set<string> visited;
        
        queue<pair<string,int >> que;
        que.push(make_pair(A,0));
        visited.insert(A);
        
        while(que.size()>0){

                pair<string,int> rem=que.front();
                if(rem.first==B){
                    return rem.second;
                }
                que.pop();
                int idx=checkForDiffer(rem.first,B);
                for(int k=idx+1;k<A.length();k++){
                    if(rem.first[k]==B[idx]){
                        string newA=rem.first;
                         swap(newA[k],newA[idx]);

                        if (visited.count(newA)==0){
                            visited.insert(newA);
                            que.push(make_pair(newA,rem.second+1));
                        }
                        
                        
                    }

            }
        }
            return -1;
    }
};
int main(){
    string a, b;
    a="aaaabbbbccccddddeeee";
    b="bddceeceababeccddaab";
    // cin>>a>>b;
    Solution s;
    cout<<s.kSimilarity(a,b);
    return 0;
}