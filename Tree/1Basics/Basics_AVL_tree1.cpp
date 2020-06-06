#include<iostream>
#include<vector>
using namespace std;
class Node{
    public:
    int data;
    Node *left;
    Node *right;
    int ht=1;//default value of height and balanced factor of leaf;
    int bal=0;//balanced factor;
    Node(int data, Node *left, Node *right){
        this->data=data;
        this->left=left;
        this->right=right;
    }
    Node(){

    }
};
void display(Node *root){
    if(root==NULL ){
        return;
    }
    if(root->left==NULL&&root->right==NULL){
        cout<<"."<<" -> "<<root->data<<"("<<root->ht<<","<<root->bal<<")"<<" <- "<<"."<<endl;
    }
    else if(root->right==NULL){
        cout<<root->left->data<<" -> "<<root->data<<"("<<root->ht<<","<<root->bal<<")"<<" <- "<<"."<<endl;
    }
    else if(root->left==NULL){
        cout<<"."<<" -> "<<root->data<<"("<<root->ht<<","<<root->bal<<")"<<" <- "<<root->right->data<<endl;
    }
    else{
        cout<<root->left->data<<" -> "<<root->data<<"("<<root->ht<<","<<root->bal<<")"<<" <- "<<root->right->data<<endl;
    }
    display(root->left);
    display(root->right);
}

int getht(Node *node){
    int lh=node->left!=NULL?node->left->ht:0;
    int rh=node->right!=NULL?node->right->ht:0;
    return max(lh,rh)+1;

}
int getbal(Node *node){
    int lh=node->left!=NULL?node->left->ht:0;
    int rh=node->right!=NULL?node->right->ht:0;
    return (lh-rh);

}

Node* constructAVL(vector<int> &arr,int low,int high){
    if(low>high){
        return NULL;
    }
    int mid=low+(high-low)/2;
    Node *node=new Node();
    node->data=arr[mid];
    node->left=constructAVL(arr,low,mid-1);
    node->right=constructAVL(arr,mid+1,high);
    node->ht=getht(node);
    node->bal=getbal(node);
    return node;

}
Node* rightRotation(Node *x){
    Node *y=x->left;
    Node *t3=y->right;
    y->right=x;
    x->left=t3;

    x->ht=getht(x);//order important
    x->bal=getbal(x);

    y->ht=getht(y);
     y->bal=getbal(y);
     return y;//important

}
Node* leftRotation(Node *x){
    Node *y=x->right;
    Node *t2=y->left;
    y->left=x;
    x->right=t2;

    x->ht=getht(x);//order important
    x->bal=getbal(x);
    y->ht=getht(y);
    y->bal=getbal(y);
    return y;//important

}
Node* add(Node *node,int data){
    //we assume that every added element is unique
    if(node==NULL){
        return new Node(data,NULL,NULL);
    }
    if(data<node->data){
        node->left=add(node->left,data);
    }
    else if(data>node->data){
        node->right=add(node->right,data);
    }
    node->ht=getht(node);
    node->bal=getbal(node);
    if(node->bal>1){
        //problem in the left side - left side jyada nranched hai 
        if(node->left->bal>=0){
            //ll- xyz=n,n.l,n.l.l;
           node= rightRotation(node);

        }
        else{
            //lr
            node->left=leftRotation(node->left);
            node=rightRotation(node);
        }
    }
    else if(node->bal<-1){
        //problem in the right side-right side jyada nranched hai  
        if(node->right->bal<=0){
            //RR
             node=leftRotation(node);
        }
        else{
            // RL
            
            node->right=rightRotation(node->right);
             node=leftRotation(node);
            }
        }

    return node;

}

int max(Node *node){//max is always in the right subtree in the the rightmost node
    if(node->right==NULL){
        return node->data;
    }
    else{
        return max(node->right);
    }
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
    if(node!=NULL){//important
        node->ht=getht(node);
        node->bal=getbal(node);
        if(node->bal>1){
            //problem in the left side - left side jyada nranched hai 
            if(node->left->bal>=0){
                //ll- xyz=n,n.l,n.l.l;
            node= rightRotation(node);

            }
            else{
                //lr
                node->left=leftRotation(node->left);
                node=rightRotation(node);
            }
        }
        else if(node->bal<-1){
            //problem in the right side-right side jyada nranched hai  
            if(node->right->bal<=0){
                //RR
                node=leftRotation(node);
            }
            else{
                // RL
                
                node->right=rightRotation(node->right);
                node=leftRotation(node);
                }
            }
    }
    return node;
}
int main(){
    vector<int> arr={12,25,37,50,62,75,87};
    Node *root=constructAVL(arr,0,arr.size()-1);
    // display(root);
    add(root,30);
    add(root,51);
    add(root,29);
    cout<<endl;
    display(root);  
    return 0;
}
