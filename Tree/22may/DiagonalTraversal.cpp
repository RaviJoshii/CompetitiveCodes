// https://www.geeksforgeeks.org/diagonal-traversal-of-binary-tree/
// https://www.interviewbit.com/problems/diagonal-traversal/#
// Diagonal Traversal
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
        // this->hl=hl;
    }
};
vector<vector<int>> solve(TreeNode* root) {

    list<Pairs> que;
        vector<vector<int>> ans;
        if(root==NULL){
            return ans;
        }
        unordered_map<int, vector<int>> umap;
        que.push_back(Pairs(root,0));
        int mins=INT_MAX;
        int maxs=0;

        while(que.size()!=0){
            int sizes=que.size();
            bool flag=true;
            while(sizes-- >0){
                Pairs rem=que.front();
                que.pop_front();

                // kept track in sorting while inserting in unorderd map 
                
                int val1=rem.node->val;
                umap[rem.vl].push_back(val1);
                
                if(rem.node->left!=NULL){
                    que.push_back(Pairs(rem.node->left,rem.vl-1));
                }
                if(rem.node->right!=NULL){
                    que.push_back(Pairs(rem.node->right,rem.vl));
                }
                mins=min(mins,rem.vl-1);

            }
        }

        for(int i=maxs;i>=mins;i--){
            ans.push_back({});
            for(int num:umap[i]){
                ans[ans.size()-1].push_back(num);
            }
        }

        return ans;
}