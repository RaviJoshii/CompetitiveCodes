// https://leetcode.com/problems/binary-tree-postorder-traversal/
// Binary Tree Postorder Traversal
/*
Note: Always use recursive for postorder
(Recommended)
*/
#include<bits/stdc++.h>
using namespace std;
class TreeNode{
    public:
    int val;
   
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(NULL), right(NULL) {}
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
class Solution {
public:
   
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> ans;
        TreeNode* curr=root;
        while(curr!=NULL){
           
            if(curr->right==NULL){
                 ans.push_back(curr->val);
                curr=curr->left;                
            }else{
                //finding predecessor
                TreeNode* currp1=curr->right;
                while(currp1->left!=NULL && currp1->left!=curr){
                    currp1=currp1->left;
                }
                if(currp1->left==NULL){
                     ans.push_back(curr->val);
                    currp1->left=curr;
                    curr=curr->right;
                }else{
                    //resetting the path
                    currp1->left=NULL;
                    curr=curr->left;//---important line
                }
                
            }
        }
        int i=0;
        int j=ans.size();

        while(i<j){
            swap(ans[i],ans[j]);
            i++;j--;
        }
        return ans;
        
    }
};


/*
class Solution {
    public List<Integer> preorderTraversal(TreeNode root) {
        List<Integer> list = new ArrayList<>();
        if(root == null) return list;
        Stack<TreeNode> stack = new Stack<>();
        while(!stack.isEmpty() || root!=null) {
            while(root!=null) {
                list.add(root.val);
                stack.push(root);
                root=root.left;
            }
            root = stack.pop();
            root = root.right;
        }
        return list;
    }
}


*/