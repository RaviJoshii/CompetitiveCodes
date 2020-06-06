// https://leetcode.com/problems/vertical-order-traversal-of-a-binary-tree/
// Vertical Order Traversal of a Binary Tree
// https://leetcode.com/problems/vertical-order-traversal-of-a-binary-tree/discuss/254966/C%2B%2B-beat-100-8ms-easy-to-understand
// https://leetcode.com/problems/vertical-order-traversal-of-a-binary-tree/discuss/231140/Add-clarification-for-the-output-order


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
class Pairs2{
    public:
    int val;
    int hl;//horizontal level
    Pairs2(int val,int hl){
        this->val=val;
        this->hl=hl;
    }
};
class Solution {

public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        list<Pairs> que;
        vector<vector<int>> ans;
        if(root==NULL){
            return ans;
        }
        unordered_map<int, vector<int>> umap;
        que.push_back(Pairs(root,0));
        int HorizontalLevel=-1;
        while(que.size()!=0){
            int sizes=que.size();
            bool flag=true;
            HorizontalLevel++;
             map<int,vector<int>> ordmap;
            while(sizes-- >0){
                Pairs rem=que.front();
                que.pop_front();
                ordmap[rem.vl].push_back(rem.node->val);
                if(rem.node->left!=NULL){
                    que.push_back(Pairs(rem.node->left,rem.vl-1));
                }
                if(rem.node->right!=NULL){
                    que.push_back(Pairs(rem.node->right,rem.vl+1));
                }

            }
            for(auto it=ordmap.begin();it!=ordmap.end();it++){
                vector<int> temp=it->second;
                sort(temp.begin(),temp.end());
                for(int num:temp){
                    umap[it->first].push_back(num);
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
            ans.push_back({});
            for(auto num:umap[i]){
                ans[ans.size()-1].push_back(num);
            }
        }

        return ans;
    }
};