#include<bits/stdc++.h>
using namespace std;
class Node{
    public:
    int data;
    Node *left;
    Node *right;
    Node(int data,Node *left,Node *right){
        this->data=data;
        this->left=left;
        this->right=right;
    }
    Node(){

    }
};
int idx=0;
Node* constructTree(vector<int> &arr){
    if(arr[idx]==-1 || idx>=arr.size()){
        idx++;
        return NULL;
    }
    idx++;
    Node *node=new Node(arr[idx],NULL,NULL);
    node->left=constructTree(arr);
    node->right=constructTree(arr);
    return node;

    }
void display(Node *root){
    if(root==NULL ){
        return;
    }
    if(root->left==NULL&&root->right==NULL){
        cout<<"."<<" -> "<<root->data<<" <- "<<"."<<endl;
    }
    else if(root->right==NULL){
        cout<<root->left->data<<" -> "<<root->data<<" <- "<<"."<<endl;
    }
    else if(root->left==NULL){
        cout<<"."<<" -> "<<root->data<<" <- "<<root->right->data<<endl;
    }
    else{
        cout<<root->left->data<<" -> "<<root->data<<" <- "<<root->right->data<<endl;
    }
    display(root->left);
    display(root->right);
    

}
int main(){
    vector<int> arr={0,2,1,3,-1,5,22,9,4,12,25,-1,-1,13,14,8,6,-1,-1,-1,
                    -1,-1,27,24,26,-1,17,7,-1,28,-1,-1,-1,-1,-1,19,
                    -1,11,10,-1,-1,-1,23,16,15,20,18,-1,-1,-1,-1,-1,21,-1,-1,29};

    Node *root=constructTree(arr);
    display(root);


    return 0;
}