#include<iostream>
using namespace std;

struct node{
	node():val(0),lson(NULL),rson(NULL){}
	int val;
	node *lson,*rson;
};

node * newnode(int val){
	node *t=new node;
	t->val=val;
	return t;
}

node* init(){
	node*root=newnode(-1);
	return root;
}


//insert a num
void insert(node*& root,int val){
	if(root==NULL){
		root=newnode(val);
		return;
	}
	if(val<root->val)insert(root->lson,val);
	else if(val==root->val) return;
	else insert(root->rson,val);
}

//search the BST to find whether val is exist
bool searchBST(node*root,int val){
	if(root==NULL)return false;
	else if(val==root->val)return true;
	else if(val<root->val)return searchBST(root->lson,val);
	else return searchBST(root->rson,val);
}

//inorder order traversal
void inorder_order(const node* root){
	if(root){
		inorder_order(root->lson);
		cout<<root->val<<endl;//print the value
		inorder_order(root->rson);
	}
}

void delete_tree(node*& root){
	if(root){
		delete_tree(root->lson);
		delete_tree(root->rson);
		root=NULL;
		delete root;
	}
}

int main(){
	int N;cin>>N;
	node* root=init();
	while(N--){
		int val;cin>>val;
		insert(root,val);
	}
	inorder_order(root);
	printf("find 3,status:%d\n",searchBST(root,3));

	delete_tree(root);
	return 0;
}
