#include<iostream>
#include<vector>
#include<limits.h>
#include<stack>
using namespace std;
class Node{
    public:
    int data;
    Node *left;
    Node *right;
};
Node* constructBST(vector<int> &arr,int low,int high){
    if(low>high){
        return NULL;
    }
    int mid=low+(high-low)/2;
    Node *node=new Node();
    node->data=arr[mid];
    node->left=constructBST(arr,low,mid-1);
    node->right=constructBST(arr,mid+1,high);
    return node;

}

void display2(Node *root){
    if(root==NULL){
        return;
    }
    cout<<root->data<<endl;
    display2(root->left);
    display2(root->right);

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
    /*
     string s1,s2,s3;
    s1=(root->left==NULL) ? "." : to_string(root->left->data);
    s2=" -> "+to_string(root->data)+" <- ";
    s3=(root->right==NULL) ? to_string(root->right->data):".";
    cout<<s1+s2+s3<<endl;
    display(root->left);
    display(root->right);

    */

}
int min(Node *node){//min is always in the left subtree in the the leftmost node
    if(node->left==NULL){
        return node->data;
    }
    else{
        return min(node->left);
    }
}

int max(Node *node){//max is always in the right subtree in the the rightmost node
    if(node->right==NULL){
        return node->data;
    }
    else{
        return max(node->right);
    }
}
bool find(Node *node,int data){
    if(node==NULL){
        return false;
    }
    else if(data<node->data){
        return find(node->left,data);
    }
    else if(data>node->data){
        return find(node->right,data);
    }
    else {//data==node->data
        return true;
    }
    
}
Node* add(Node *node,int data){
    //we assume that every added element is unique
    if(node==NULL){
        Node *base=new Node();
        base->data=data;
        base->left=NULL;base->right=NULL;
        return base;
    }
    if(data<node->data){
        node->left=add(node->left,data);
    }
    else if(data>node->data){
        node->right=add(node->right,data);
    }
    return node;
}
Node* remove(Node *node,int data){
    if(node==NULL){
        cout<<"Node doesn't exist"<<endl;
        return node;
    }
    if(node->data>data){
        node->left= remove(node->left,data);
    }
    else if(data>node->data){
        node->right=remove(node->right,data);
    }
    else{
        //node is finded, puting the three cases
        if(node->left==NULL&&node->right==NULL){
            //case 1: 0 childs
            node =NULL;
        }
        else if(node->left==NULL){
            //case 2: node have 1 childs
            node= node->left;
        }
        else if(node->right==NULL){
            //case 2: node have 1 childs
            node=node->right;
        }
        else{
            //case 3: node have 2 childs
            int lmax=max(node->left);
            node->data=lmax;
            node->left=remove(node->left,lmax);
            
        }
        
    }
    return node;
}
int sum=0;//in java use static variable
void TransformToSOG(Node *node){
    if(node==NULL){
        return;
    }
    TransformToSOG(node->right);
    int onv=node->data;//onv=original node value
    node->data=sum;
    sum+=onv;
    TransformToSOG(node->left);

}
void tspair1(Node *node,int target,Node *root){
    if(node==NULL){
        return ;
    }
    int comp=target-node->data;
    if(comp>node->data&&find(root,comp)){
        cout<<"("<<node->data<<","<<comp<<")"<<endl;
    }
    tspair1(node->left,target,root);
    tspair1(node->right,target,root);
}
void tspair2(Node *node, vector<int> &arr){
    if(node==NULL){
        return;
    }
    tspair2(node->left,arr);
    arr.push_back(node->data);
    tspair2(node->right,arr);
}
void tspair2Driver(Node *node,int target){
    vector<int> arr;
    tspair2(node,arr);
    
    int i=0;int j=arr.size()-1;
    while(i<j){
        if(arr[i]+arr[j]==target){
            cout<<arr[i]<<" "<<arr[j]<<endl;
            i++;j--;
        }
        else if((arr[i]+arr[j])<target){
            i++;
        }
        else{
            j--;
        }
    }
}
class Pair{
    public:
    int state=0;
    Node *node;
     Pair() {
        }
    Pair(Node *node,int state){
        this->node=node;
        this->state=state;
    }
};
void tspair3(Node *root, int tar) {
        // code here
        stack<Pair *> ls;
        Pair *rtp1 = new Pair(root, 0);
        ls.push(rtp1);

        stack<Pair *> rs;
        Pair *rtp2 = new Pair(root, 0);
        rs.push(rtp2);

        int lv = 0;
        int rv = 0;
        bool ml = true;
        bool mr = true;

        while(true){
            while (ml == true && ls.size() > 0) {
                Pair *top = ls.top();
                if (top->node == NULL) {
                    ls.pop();
                    continue;
                }

                if (top->state == 0) {
                    top->state++;
                    ls.push(new Pair(top->node->left, 0));
                } else if (top->state == 1) {
                    top->state++;
                    ls.push(new Pair(top->node->right, 0));
                    lv = top->node->data;
                    break;
                } else if (top->state == 2) {
                    ls.pop();
                }
            }           

            while (mr == true && rs.size() > 0) {
                Pair *top = rs.top();
                if (top->node == NULL) {
                    rs.pop();
                    continue;
                }

                if (top->state == 0) {
                    top->state++;
                    rs.push(new Pair(top->node->right, 0));
                } else if (top->state == 1) {
                    top->state++;
                    rs.push(new Pair(top->node->left, 0));
                    rv = top->node->data;
                    break;
                } else if (top->state == 2) {
                    rs.pop();
                }
            }      

            if(lv >= rv){
                break;
            }
            else if(lv + rv < tar){
                ml = true;
                mr = false;
            } else if(lv + rv > tar){
                ml = false;
                mr = true;
            } else {
                cout<<lv <<" "<<rv<<endl;
                ml = true;
                mr = true;
            }
        }
    }

int main(){
    vector<int> arr={10,20,30,50,60,70,80};
    Node *root=constructBST(arr,0,arr.size()-1);
    // display(root);
    // add(root, 27);

    add(root,25);
    add(root,35);
    add(root,55);
    add(root,65);

    // remove(root, 101);
    // TransformToSOG(root);

    // cout<<endl;
    // display(root);
    // tspair1(root,105,root);
    // tspair2Driver(root,105);
    // cout<<endl<<endl;
    tspair3(root, 105);

}