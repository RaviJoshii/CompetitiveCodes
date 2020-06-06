// https://leetcode.com/problems/all-nodes-distance-k-in-binary-tree/
// All Nodes Distance K in Binary Tree
// https://leetcode.com/problems/all-nodes-distance-k-in-binary-tree/discuss/651083/C%2B%2B-oror-O(N)-Space-and-Time-oror-level-order-traversal-with-hashmap


#include<bits/stdc++.h>
using namespace std;
  struct TreeNode {
     int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  };
class Solution{
public:

    unordered_map<TreeNode*,TreeNode*> parent;
    
    void parentTableFormation(TreeNode *root,TreeNode* prev){
        if(root==NULL){
            return;
        }
        
        parent[root]=prev;
        parentTableFormation(root->left,root);
        parentTableFormation(root->right,root);
    }
vector<int> distanceK(TreeNode* root, TreeNode* target, int K) {
    
    //implementing parent table
    parentTableFormation(root,NULL);
    unordered_set<TreeNode*>  uset;

    list<TreeNode*> que;
    
    
    que.push_back(target);
    uset.insert(target);

    for(int level=0;level!=K;level++){
        int sizes=que.size();
        
        while(sizes-->0){
            TreeNode* rem=que.front();
            que.pop_front();

            if(rem->left!=NULL&& uset.find(rem->left)!=uset.end()==false){
                    uset.insert(rem->left);
                    que.push_back(rem->left);
            }
            if(rem->right!=NULL&& uset.find(rem->right)!=uset.end()==false){
                    uset.insert(rem->right);
                    que.push_back(rem->right);
            }
            if(parent[rem]!=NULL && uset.find(parent[rem])!=uset.end()==false){
                    uset.insert(parent[rem]);
                    que.push_back(parent[rem]);
                    
                
            }

        }  
    }
    vector<int> ans;
    while(que.size()>0){
        ans.push_back(que.front()->val);
        que.pop_front();
    }
    return ans;
        
}
};