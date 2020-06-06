// https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-search-tree/
// Lowest Common Ancestor of a Binary Search Tree
#include<bits/stdc++.h>
using namespace std;
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
    
    Node(int x){
        data = x;
        left = right = NULL;
    }
};
class Solution{
    public:
    unordered_map<int,Node*> parentmap;
    unordered_map<int,int> levelmap;
    void BuiltParentLevelMap(Node* root ,int level,Node *parent){
        if(root==NULL){
            return;
        }
        levelmap[root->data]=level;
        parentmap[root->data]=parent;
        BuiltParentLevelMap(root->left,level+1,root);
        BuiltParentLevelMap(root->right,level+1,root);

    }
    Node* lca(Node* root ,int n1 ,int n2 ){
        BuiltParentLevelMap(root,0,NULL);

        int level1=levelmap[n1];
        int level2=levelmap[n2];
        if(level1-level2!=0){
            //they are a diiferent level
            if(level1>level2){
                //shift n1;
                int diff=level1-level2;
                while(diff-->0){
                    n1=parentmap[n1]->data;
                }
            }else{
                int diff=level2-level1;
                while(diff-->0){
                    n2=parentmap[n2]->data;
                }
            }
        }
        while(parentmap[n1]!=parentmap[n2]){
            n1=parentmap[n1]->data;
            n2=parentmap[n2]->data;
        }
        return parentmap[n1];
    }
    
};

int main(){
    return 0;
}