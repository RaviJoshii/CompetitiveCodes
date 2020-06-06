// https://practice.geeksforgeeks.org/problems/image-multiplication/0
// Image Multiplication
#include<bits/stdc++.h>
using namespace std;
// #define long long int;
int m=10e8+7;
class TreeNode{
    public:
    int val;
      TreeNode *left=NULL;
      TreeNode *right=NULL;
      TreeNode(int val){
          this->val=val;
      }
};
int ImageMultiplication(TreeNode* root1,TreeNode* root2){
    if(root1==NULL || root2==NULL){
        return 0;
    }
    int ans=root1->val*root2->val;
    ans+=ImageMultiplication(root1->left,root2->right);
    ans+=ImageMultiplication(root1->right,root2->left);
    return ans%m;
}
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        unordered_map<int,TreeNode*> umap;
        TreeNode* root=NULL;
        for(int i=0;i<n;i++){
            int a;int b;char c;
            cin>>a>>b>>c;
            TreeNode *node1;
            TreeNode* node2;
            if(umap.find(a)!=umap.end()){
                node1=umap[a];
            }else{
                node1=new TreeNode(a);
                umap[a]=node1;
            }

            if(umap.find(b)!=umap.end()){
                node2=umap[b];
            }else{
                node2=new TreeNode(b);
                umap[b]=node2;
            }
            if(root==NULL){
                root=node1;
            }


            if(c=='L'){
                node1->left=node2;
            }else if(c=='R'){
                node1->right=node2;
            }
        }

        if(root==NULL){
            continue;
        }

        int ans=((root->val*root->val)%m+ImageMultiplication(root->left,root->right))%m;
        cout<<ans%m<<endl;
    }
    return 0;
}