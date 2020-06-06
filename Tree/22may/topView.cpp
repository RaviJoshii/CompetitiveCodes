// https://www.geeksforgeeks.org/print-nodes-in-the-top-view-of-binary-tree-set-3/
// Print nodes in the Top View of Binary Tree
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
class Pairs{
    public:
    TreeNode *node;
    int vl;//vertical level
    Pairs(TreeNode *node,int vl){
        this->node=node;
        this->vl=vl;
    }
};
vector<int> levelOrder(TreeNode* root) {
    list<Pairs> que;
    vector<int> ans;
    if(root==NULL){
        return ans;
    }
    unordered_map<int, int> umap;
    que.push_back(Pairs(root,0));
    while(que.size()!=0){
        int sizes=que.size();
        bool flag=true;
        while(sizes-- >0){
            Pairs rem=que.front();
            que.pop_front();
            if(umap.find(rem.vl)==umap.end()){
                umap[rem.vl]=rem.node->val;
            }

            if(rem.node->left!=NULL){
                que.push_back(Pairs(rem.node->left,rem.vl-1));
            }
            if(rem.node->right!=NULL){
                que.push_back(Pairs(rem.node->right,rem.vl+1));
            }

        }
    }
    int mins=INT_MAX;
    int maxs=INT_MIN;
    for(auto it=umap.begin();it!=umap.end();it++){
        mins=min(it->first,mins);
        maxs=max(it->first,maxs);

    }
    for(int i=mins;i<=maxs;i++){
        ans.push_back(umap[i]);
    }

    return ans;
    
}
int main(){

    return 0;
}