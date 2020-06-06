#include<iostream>
#include<vector>
#include<limits.h>
#include<list>
#include<stack>
using namespace std;
class Node{
    public:
    int data;
    Node *left;
    Node *right;
    Node(){

    }
    Node(int data, Node *left, Node *right){
        this->data=data;
        this->left=left;
        this->right=right;
    }
};
int idx=0;
Node* ConstructTree(vector<int> &arr){
    if(idx>=arr.size()||arr[idx]==-1) {idx++;return NULL;}
    Node *node=new Node(arr[idx],NULL,NULL);
    idx++;
    node->left=ConstructTree(arr);
    node->right=ConstructTree(arr);
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
int size(Node *root){
    if(root==NULL){
        return 0;
    }
    int sz=0;
    sz+=size(root->left);
    sz+=size(root->right);
    return sz+1;
}
    void style1(Node *node) {
        if (node == NULL) {
            return;
        }

        // work
        style1(node->left);
        style1(node->right);
    }

     void style2(Node *node) {
        // work
        if (node->left != NULL) {
            style2(node->left);
        }
        if (node->right != NULL) {
            style2(node->right);
        }
    }

    void style3(Node *node) {
        if (node->left != NULL && node->right != NULL) {
            style3(node->left);
            style3(node->right);
        } else if (node->left != NULL) {
            style3(node->left);
        } else if (node->right != NULL) {
            style3(node->right);
        } else {
            // no calls
        }
    }
int height(Node *root){
    if(root==NULL){
        return -1;
    }
    int hl=height(root->left);
    int hr=height(root->right);
    return max(hl,hr)+1;
}
void preOrder(Node *root){
    if(root==NULL){
        return;
    }
    cout<<root->data<<" ";
    preOrder(root->left);
    preOrder(root->right);
}
void inOrder(Node *root){
    if(root==NULL){
        return;
    }
    inOrder(root->left);
    cout<<root->data<<" ";
    
    inOrder(root->right);
}
void PostOrder(Node *root){
    if(root==NULL){
        return;
    }
   
    PostOrder(root->left);
    PostOrder(root->right);
    cout<<root->data<<" ";
}
int maxInTree(Node *root){
    if(root==NULL){
        return INT_MIN;
    }
    int maxL=maxInTree(root->left);
    int maxR=maxInTree(root->right);
    return max(root->data,max(maxL,maxR));
}
bool find(Node *root,int data){
    if(root==NULL){     
        return false;
    }
    if(root->data==data) return true;
    bool res=false;
     res=res||find(root->left,data);
    res=res||find(root->right,data);
    return res;
}
vector<Node*> rootToNodePath(Node *root,int data){
    //like find method
    if(root==NULL){
       return vector<Node*>();
    }
    if(root->data==data){
        vector<Node*> vec;
        vec.push_back(root); 
        return vec;
    }
    vector<Node*> vecL=rootToNodePath(root->left,data);
    if(vecL.size()>0){
        vecL.push_back(root);
        return vecL;
    }
    vector<Node*> vecR=rootToNodePath(root->right,data);
    if(vecR.size()>0){
        vecR.push_back(root);
        return vecR;
    }
    return vector<Node*>();
}
int LCA_01(Node *root, int data1,int data2){
    // if(find(root,data1)==false||find(root,data2)==false){
    //     return -1;
    // }--fulfilled
    //tree is also a graph--all algo applied here
    //kdown- 
    // if(data1==data2){
    //     return data1;
    // }
    vector<Node*> vec1=rootToNodePath(root,data1);
    vector<Node*> vec2=rootToNodePath(root,data2);
    int i=vec1.size()-1;
    int j=vec2.size()-1;
    int ans = -1;
        while(vec1[i]==vec2[j]&&i>=0&&j>=0){
            ans=vec1[i]->data;
            i--;
            j--;
        }
        return ans;
}
void kdown(Node *node, Node *pnode,int level){
    if(node==pnode||node==NULL){
        return ;
    }
    if(level==0){
        cout<<node->data<<" ";
        return;
    }
    kdown(node->left,pnode,level-1);
    kdown(node->right,pnode,level-1);
}
void kaway_01(Node *root, int data,int k){
    vector<Node*> vec=rootToNodePath(root,data);//---o(n);
    Node* pnode=NULL;
    for(Node *i:vec){
        kdown(i,pnode,k);
        cout<<endl;
        pnode=i;
        k--;
    }
}
int kaway_02(Node *root,int data,int k){
    if(root==NULL){
        return -1;
    }
    if(root->data==data){
        kdown(root,NULL,k);
        return 1;
    }
    int ld=kaway_02(root->left,data,k);
    if(ld!=-1){
        kdown(root,root->left,k-ld);
        return ld+1;
    }
    int rd=kaway_02(root->right,data,k);
    if(rd!=-1){
        kdown(root,root->right,k-rd);
        return rd+1;
    }
    return -1;
}
template <class T> 
void printvector(vector<T> vec){
    for(T i:vec){
        cout<<i->data<<" ";
    }
    cout<<endl;
}
int diameter01(Node *root){
    if(root==NULL){
        return 0;
    }
    int ld=diameter01(root->left);
    int rd=diameter01(root->right);
    int lh=height(root->left);
    int rh=height(root->right);
    return max(max(ld,rd),lh+rh+2);
}
int* diameter02(Node *root){
    if(root==NULL){
        int *base =new int[2];
        base[0]=0;//diameter
        base[1]=-1;//height
        return base;
    }
    int *myans=new int[2];
    int *leftAns=diameter02(root->left);
    int *rightAns=diameter02(root->right);

    myans[0]=max(max(leftAns[0],rightAns[0]),leftAns[1]+rightAns[1]+2);
    myans[1]=max(leftAns[1],rightAns[1])+1;
    return myans;
}
int maxdia=0;
int diameter03(Node* root){
    if(root==NULL){
        return -1;
    }
    int lh=diameter03(root->left);
    int rh=diameter03(root->right);
    
    maxdia=max(maxdia,lh+rh+2);
    return max(lh,rh)+1;
}
int maxLtoLsum=INT_MIN;
int leafToleafSum(Node* root){
    if(root==NULL){
        return INT_MIN;;
    }
    if(root->left==NULL&&root->right==NULL){
        return root->data;//leaf
    }   
    int ls=leafToleafSum(root->left);
    int rs=leafToleafSum(root->right);
    
    if(root->left!=NULL&&root->right!=NULL){
        maxLtoLsum=max(maxLtoLsum,ls+rs+root->data);
    }
    return max(ls,rs)+root->data; 
}
int maxNtoNsum=INT_MIN;
int NodeToNodeSum(Node* root){
    if(root==NULL){
        return INT_MIN;;
    }  
    int ls=NodeToNodeSum(root->left);
    int rs=NodeToNodeSum(root->right);
    int maxBranch=max(ls,rs);

    maxNtoNsum=max(max(maxNtoNsum,root->data),max(ls+rs+root->data,maxBranch+root->data));
    return max(maxBranch+root->data,root->data); 
}
int Cameras=0;
int minCameras_(Node* node) {
        if (node == NULL)
            return 0;

        int left = minCameras_(node->left);
        int right = minCameras_(node->right);

        if (left == -1 || right == -1) {
            Cameras++;
            return 1;
        }

        if (left == 1 || right == 1) {
            return 0;
        }

        return -1;
    }

    int minCameras(Node* node) {
        int val = minCameras_(node);
        if (val == -1)
            Cameras++;
        return Cameras;
    }
class BaiPair{
    public:
    int ht;
    bool isBal;//check whether tree is balanced or not
};
BaiPair _isBalanced(Node* node){
    if(node==NULL){
        BaiPair bp;
        bp.ht=0;
        bp.isBal=true;
        return bp;
    }
 BaiPair lp=_isBalanced(node->left);
 BaiPair rp=_isBalanced(node->right);
 BaiPair mp;//mypair;
 mp.ht=(lp.ht)+(rp.ht)+1;
 mp.isBal= lp.isBal&&rp.isBal&&
            (abs(lp.ht-rp.ht)<=1);
 return mp;

}
void isBalanced(Node *node){
    if(_isBalanced(node).isBal){
        cout<<"Yes Binary tree is balanced";
    }
    else{
        cout<<"NO Binary tree is Unbalanced";
    }

}
//returnImapct Method to find Isbalanced
bool isBal=true;
int heightForIsBal(Node* node){
    if(node ==NULL){
        return 0;
    }
    int lh=heightForIsBal(node->left);
    int rh=heightForIsBal(node->right);

    if(abs(lh-rh)>1){
        isBal=false;
    }
    return lh+rh+1;
}

// check whether tre eis bst ot not
class BSTPair {
    public:
		int min;
		int max;
		bool bst;
	};
BSTPair _IsBST(Node *node) {
		if (node == NULL) {
			BSTPair bp;
			bp.min = INT_MAX;
			bp.max = INT_MIN;
			bp.bst = true;
			return bp;
		}

		BSTPair lp = _IsBST(node->left);
		BSTPair rp = _IsBST(node->right);

		BSTPair mp;
		mp.max = max(node->data, max(lp.max, rp.max));
		mp.min = min(node->data, min(lp.min, rp.min));
		mp.bst = node->data > lp.max && node->data < rp.min && lp.bst && rp.bst;
		return mp;
};
void IsBST(Node *root) {
    BSTPair bp = _IsBST(root);
    if(bp.bst){
        cout<<"Yes";
    }
    else{
        cout<<"No";
    }
}

//Larget Bst : few changes happens on above program 
class LBSTPair {
    public:
		int min;
		int max;
		bool bst;
		int lbstroot;
		int lbstsize;
	};
LBSTPair _LargestBST(Node *node) {
		if (node == NULL) {
			LBSTPair bp;
			bp.min = INT_MAX;
			bp.max = INT_MIN;
			bp.bst = true;
			return bp;
		}

		LBSTPair lp = _LargestBST(node->left);
		LBSTPair rp = _LargestBST(node->right);

		LBSTPair mp;
		mp.max = max(node->data, max(lp.max, rp.max));
		mp.min = min(node->data, min(lp.min, rp.min));
		mp.bst = node->data > lp.max && node->data < rp.min && lp.bst && rp.bst;

		if (mp.bst) {
			mp.lbstroot = node->data;
			mp.lbstsize = lp.lbstsize + rp.lbstsize + 1;
		} else {
			if (lp.lbstsize > rp.lbstsize) {
				mp.lbstroot = lp.lbstroot;
				mp.lbstsize = lp.lbstsize;
			} else {
				mp.lbstroot = rp.lbstroot;
				mp.lbstsize = rp.lbstsize;
			}
		}

		return mp;
};
void LargestBST(Node *node) {
    LBSTPair bp = _LargestBST(node);
    cout<<(bp.lbstroot + "@" + bp.lbstsize);
}

//iterative traversals of binary tree
class pairs{
    public:
    int n;
    string bin;
    pairs(int n,string bin){
        this->n=n;
        this->bin=bin;
    }
};
void printBinary(int n){
    list<pairs> queue;
    queue.push_back(pairs(1,"1"));

    while(queue.size()>0){
        pairs rem=queue.front();queue.pop_front();
        cout<<rem.n<<"->"<<rem.bin<<endl;
        if(2*rem.n<=n){
            queue.push_back(pairs(2*rem.n,rem.bin+"0"));
        }
        if(2*rem.n+1<=n){
            queue.push_back(pairs(2*rem.n+1,rem.bin+"1"));
        }
    }
}
class Ipair{
    public:
    Node *node;
    bool print=false;
    bool lcall=false;
    bool rcall=false;
    Ipair(Node *node){
        this->node=node;
    }
};
void preOrderIterative1(Node *root){
    list<Ipair*> stack;
    stack.push_back(new Ipair(root));
    while(stack.size()>0){
        Ipair *tp=stack.back(); 
        if(tp->node==NULL){
            stack.pop_back();
            continue;
        }
        if(tp->print==false){
            cout<<tp->node->data<<" ";
            tp->print=true;
        }
        else if(tp->lcall==false){
            tp->lcall=true;
            stack.push_back(new Ipair(tp->node->left));
        }
        else if(tp->rcall==false){
            tp->rcall=true;
            stack.push_back(new Ipair(tp->node->right));
        }
        else{
            stack.pop_back();
        }
    }
}
class IPair2 {
        public:
		Node *node;
		int counter = 0;
};
void preOrderIterative2(Node *root) {
		stack<IPair2*> st;

		IPair2 *rootp = new IPair2();
		rootp->node = root;
		st.push(rootp);

		while (st.size() > 0) {
			IPair2 *top = st.top();

			if (top->counter == 0) {
				cout<<(top->node->data + " ");
			} else if (top->counter == 1) {
				if (top->node->left != NULL) {
					IPair2 *leftp = new IPair2();
					leftp->node = top->node->left;
					st.push(leftp);
				}
			} else if (top->counter == 2) {
				if (top->node->right != NULL) {
					IPair2 *rightp = new IPair2();
					rightp->node = top->node->right;
					st.push(rightp);
				}
			} else {
				st.pop();
			}

			top->counter++;
		}
		cout<<endl;
	}

class IPairOrder{
    public:
    Node *node;
    int state=0;
    IPairOrder(Node *node,int state){
        this->node=node;
    }

};
void AllOrderIteartive(Node *node){
    vector<int> pre;
    vector<int> in;
    vector<int> post;

    // code here
    stack<IPairOrder*> st;
    IPairOrder *rtp = new IPairOrder(node, 0);
    st.push(rtp);

    while (st.size() > 0) {
        IPairOrder *top=st.top();
        if(top->node==NULL){
            st.pop();
            continue;
        }
        if(top->state==0){
            pre.push_back(top->node->data);
            st.push(new IPairOrder(top->node->left,0));
            top->state++;
        }
        else if(top->state==1){
            in.push_back(top->node->data);
            st.push(new IPairOrder(top->node->right,0));
            top->state++;
        }
        else if(top->state==2){
            post.push_back(top->node->data);
            st.pop();
        }

    }

    cout<<"Pre -> ";for(int i:pre){cout<<i<<" ";} cout<<endl;
    cout<<"In -> ";for(int i:in){cout<<i<<" ";} cout<<endl;
    cout<<"Post -> ";for(int i:post){cout<<i<<" ";} cout<<endl;
}
void printSingleChild(Node *parent, Node *child){
    if(child==NULL){
        return;
    }
    if((parent->left==child&&parent->right==NULL)||
        (parent->right==child&&parent->left==NULL)){
            cout<<child->data<<endl;
    }
    printSingleChild(child,child->left);
     printSingleChild(child,child->right);

}
void printSingleChild(Node *node){
    printSingleChild(node,node->left);//for root
     printSingleChild(node,node->right);
}

void printSiblingLessNodes(Node *node) {
		if (node->left != NULL) {
			if (node->right == NULL) {
				cout<<(node->left->data);
			}
			printSiblingLessNodes(node->left);
		}

		if (node->right != NULL) {
			if (node->left == NULL) {
				cout<<(node->right->data);
			}
			printSiblingLessNodes(node->right);
		}
}

vector<int> nodeToRootPath(Node *root, int data) {
        if (root == NULL) {
            vector<int> vec;
            return vec;
        }
        if (root->data == data) {
            vector<int> list;
            list.push_back(root->data);
            return list;
        }
        vector<int> n2lcpath = nodeToRootPath(root->left, data);
        if (n2lcpath.size() > 0) {
            n2lcpath.push_back(root->data);
            return n2lcpath;
        }

        vector<int> n2rcpath = nodeToRootPath(root->right, data);
        if (n2lcpath.size() > 0) {
            n2lcpath.push_back(root->data);
            return n2rcpath;
        }
        vector<int> empty;
        return empty;
    }

void removeLeaves1(Node *node, Node *par) {//node is child
		if (node->left != NULL && node->right != NULL) {
			removeLeaves1(node->left, node);
			removeLeaves1(node->right, node);
		} else if (node->left != NULL) {
			removeLeaves1(node->left, node);
		} else if (node->right != NULL) {
			removeLeaves1(node->right, node);
		} else {  //node is leaf
			if (par->left == node) {
				par->left = NULL;
			} else {
				par->right = NULL;
			}
		}
	}
void removeLeaves1(Node *node){
    removeLeaves1(node->left,node);
    removeLeaves1(node->right,node);
}
void removeLeaves2(Node *node) {
		if (node->left != NULL) {
			// think of left
			if (node->left->left == NULL && node->left->right == NULL) {
				node->left = NULL;
			} else {
				removeLeaves2(node->left);
			}
		}

		if (node->right != NULL) {
			// think of right
			if (node->right->left == NULL && node->right->right == NULL) {
				node->right = NULL;
			} else {
				removeLeaves2(node->right);
			}
		}
	}

void removeLeaves3(Node *parent,Node *child){
     if(child==NULL){
        return;
    }
    if(child->left==NULL&&child->right==NULL){
        //leaf
        if(parent->left==child){
            parent->left=NULL;
        }
        else{
            parent->right=NULL;
        }
    }
    
    removeLeaves3(child,child->left);
    removeLeaves3(child,child->right);
}
void removeLeaves3(Node *node){
    removeLeaves3(node,node->left);
    removeLeaves3(node,node->right);
}
Node* transformToLD(Node *node){
    if(node==NULL){
        return NULL;
    }
    node->left=transformToLD(node->left);
    node->right=transformToLD(node->right);
    node->left = new Node(node->data, node->left, NULL);
    return node;
    
}
Node* transformFromLD(Node *node) {
       if(node==NULL){
        return NULL;
    }

        node->left = transformFromLD(node->left->left);
        node->right = transformFromLD(node->right);
        return node;
    }
int main(){
    
    vector<int> arr={10,20,40,80,-1,-1,90,-1,-1,50,100,-1,-1,-1,30,60,-1,110,-1,-1,70,120,-1,-1,-1};
    // vector<int> arr={1,2,3,4,5,6,7};
    Node *root= ConstructTree(arr);
    display(root);
    cout<<endl;
   
    // cout<<size(root)<<endl;
    // cout<<height(root)<<endl;
    // preOrder(root);
    // cout<<endl;
    // inOrder(root);
    // cout<<endl;
    // PostOrder(root);
    // cout<<find(root,50)<<endl;
    // cout<<find(root,51)<<endl;
    // cout<<maxInTree(root)<<endl;
    // vector<Node*> path=rootToNodePath(root,10);
    // for(Node *nn:path){
    //     cout<<nn->data<<" ";
    // }
    // cout<<LCA_01(root,60,120)<<endl;
    // cout<<LCA_01(root,110,120);
    // kaway_01(root,110,3);
    // int *ans=diameter02(root);
    // cout<<ans[0]<<endl;
    // diameter03(root);
    // cout<<maxdia<<endl; 
    // preOrderIterative1(root);
    // AllOrderIteartive(root);

    // isBalanced(root);
    // IsBST(root);
    // LargestBST(root);

    // printBinary(15);
    transformToLD(root);
    display(root);
    return 0;

}
