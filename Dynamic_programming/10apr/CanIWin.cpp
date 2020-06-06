// https://leetcode.com/problems/can-i-win/
// Can I Win
#include<bits/stdc++.h>
using namespace std;
// class Solution {
// public:
//     unordered_map<int,bool> umap;
//     int format(vector<bool> &state){
//         int num=0;
//         for(bool b: state){
//             num<<=1;
//             if(b){
//                 num|=1;
//             }
//         }
//         return num;
//     }
//     bool DFS(int M,int tar,vector<bool> &state){
//         if(tar<=0){
//             return false;
//         }
//         int key=format(state);
//         if(umap.find(key)!=umap.end()){
//             return umap[key];
//         }
//         else{
//             for(int i=1;i<=M;i++){
//                 if(!state[i]){
//                    int updatedTarget=tar-i;
//                     state[i]=true;
//                     if(DFS(M,updatedTarget,state)==false){
//                         umap[key]=true;
//                         state[i]=false;
//                         return true;
//                     }
//                     state[i]=false;
//                 }       
//             }
//             umap[key]=false;
            
//         }
//         return umap[key];
        
        
// }
//     bool canIWin(int maxChoosableInteger, int desiredTotal) {
//         if(maxChoosableInteger>=desiredTotal){
//             return true;
//         }
//         int sum=(maxChoosableInteger)*(maxChoosableInteger+1)/2;
//         if(desiredTotal>sum){
//             return false;
//         }
//         else if(sum==desiredTotal){
//             if(maxChoosableInteger%2==0){
//                 return false;
//             }
//             else{
//                 return true;
//             }
//         }
//         unordered_map<int,bool> umap;
//         vector<bool> state(maxChoosableInteger+1,false);
//         return DFS(maxChoosableInteger,desiredTotal,state);
//     }
// };
// int main(){
//     Solution s;
//     cout<<s.canIWin(10,11)<<endl;
//     cout<<s.canIWin(5,12)<<endl;
//     cout<<s.canIWin(8,21)<<endl;
//     return 0;
// }

class Solution {
public:
    unordered_map<int,bool> umap;

    bool DFS(int M,int tar,int key){
        if(tar<=0){
            return false;
        }
        if(umap.find(key)!=umap.end()){
            return umap[key];
        }
        else{
            for(int i=1;i<=M;i++){
                int mask=1<<i;
                if((key&mask)!=0){
                   int updatedTarget=tar-i;
                    key=key|mask;
                    if(DFS(M,updatedTarget,key)==false){
                        umap[key]=true;
                        key=key&(~mask);
                        return true;
                    }
                    key=key&(~mask);
                }       
            }
            umap[key]=false;
            
        }
        return umap[key];
}
    bool canIWin(int maxChoosableInteger, int desiredTotal) {
        if(maxChoosableInteger>=desiredTotal){
            return true;
        }
        int sum=(maxChoosableInteger)*(maxChoosableInteger+1)/2;
        if(desiredTotal>sum){
            return false;
        }
        else if(sum==desiredTotal){
            if(maxChoosableInteger%2==0){
                return false;
            }
            else{
                return true;
            }
        }
        unordered_map<int,bool> umap;
        int key=0;
        return DFS(maxChoosableInteger,desiredTotal,key);
    }
};
int main(){
    Solution s;
    cout<<s.canIWin(10,11)<<endl;
    cout<<s.canIWin(5,12)<<endl;
    cout<<s.canIWin(8,21)<<endl;
    return 0;
}