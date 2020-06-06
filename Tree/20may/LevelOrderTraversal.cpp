// https://leetcode.com/problems/binary-tree-level-order-traversal/
// Binary Tree Level Order Traversal
#include<bits/stdc++.h>
using namespace std;

struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  };
 
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        list<TreeNode*> que;
        vector<vector<int>> ans;
        if(root==nullptr){
            return ans;
        }
        que.push_back(root);
        
        while(que.size()!=0){
            int sizes=que.size();
            bool flag=true;
            while(sizes-- >0){
                TreeNode* rem=que.front();
                que.pop_front();
                if(flag){
                    ans.push_back({rem->val});
                    flag=false;
                }else{
                    ans[ans.size()-1].push_back(rem->val);
                }
                if(rem->left!=nullptr){
                    que.push_back(rem->left);
                }
                if(rem->right!=nullptr){
                    que.push_back(rem->right);
                }

            }
        }

        return ans;
        
    }
};
int main(){

    return 0;
}