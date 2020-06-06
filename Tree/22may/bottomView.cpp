// https://practice.geeksforgeeks.org/problems/bottom-view-of-binary-tree/1
// Bottom View of Binary Tree
#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
      Node *left;
      Node *right;
      Node() : data(0), left(NULL), right(NULL) {}
      Node(int x) : data(x), left(NULL), right(NULL) {}
     Node(int x, Node *left, Node *right) : data(x), left(left), right(right) {}
};
class Pairs{
    public:
    Node *node;
    int vl=0;//vertical level
    Pairs(Node *node,int vl){
        this->node=node;
        this->vl=vl;
    }
    Pairs(){
        
    }
};
void bottomView(Node *root)
{   list<Pairs> que;
    vector<int> ans;
    if(root==NULL){
        return;
    }
    
    unordered_map<int, int> umap;
    que.push_back(Pairs(root,0));
    while(que.size()!=0){
        int sizes=que.size();
        bool flag=true;
        while(sizes-- >0){
            Pairs rem=que.front();
            que.pop_front();
           
            umap[rem.vl]=rem.node->data;
            

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
        cout<<(umap[i])<<" ";
    }
    
    
    
   
}
int main(){
    return 0;
}