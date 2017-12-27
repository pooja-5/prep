//BST AND TRAVERSALS

#include<iostream>
#include<stdlib.h>
#include<queue>
#include<stack>
using namespace std;

struct Node{
	int data;
	Node *left,*right;
}*root=NULL;

class BST{
	public:
		Node* createNode(int);
		void insert(int);
		void insertBST(Node*,int);
		void inorder(Node*);
		void preorder(Node*);
		void postorder(Node*);
		int treeHeight(Node*);
		void displayLevel(Node*,int);
		void levelorder(Node*);
		void inorderStack(Node*);
		void preorderStack(Node*);
		void postorderStack(Node*);
		void spiralorder(Node*);
		void displaySpiral(Node*,int,bool);
};

Node* BST::createNode(int data){
	Node *temp=new Node;
	temp->data=data;
	temp->left=NULL;
	temp->right=NULL;
	return temp;
}

void BST::insert(int data){
	if(root)
		insertBST(root,data);
	else
		root=createNode(data);
}

void BST::insertBST(Node *root,int data){
	if(data> root->data){
		if(!root->right)
			root->right=createNode(data);
		else
			insertBST(root->right,data);
	}
				
	else{
		if(!root->left)
			root->left=createNode(data);
		else
			insertBST(root->left,data);
	}
}

void BST::inorder(Node *root){
	if(!root)
		return;
	inorder(root->left);
	cout<<root->data<<endl;
	inorder(root->right);
}

void BST::preorder(Node *root){
	if(!root)
		return;
	cout<<root->data<<endl;
	preorder(root->left);
	preorder(root->right);
}

void BST::postorder(Node *root){
	if(!root)
		return;
	postorder(root->left);
	postorder(root->right);
	cout<<root->data<<endl;
}

int BST::treeHeight(Node *root){
	if(root==NULL)
		return 0;
	int lheight=treeHeight(root->left);
	int rheight=treeHeight(root->right);
	if(lheight>rheight)
		return lheight+1;
	else
		return rheight+1;
}

void BST::displayLevel(Node *root,int ht){
	if(root==NULL)
		return;
	if(ht==1)
		cout<<root->data<<" ";
	else if(ht>1){
		displayLevel(root->left,ht-1);
		displayLevel(root->right,ht-1);
	}
}

void BST::levelorder(Node *root){
	int height=treeHeight(root);
	for(int i=1;i<=height;i++){
		displayLevel(root,i);
		cout<<endl;
	}
}
void BST::inorderStack(Node *root){
	stack<Node*>s;
	Node *r=root;
	Node *cur;
	while(!s.empty()||r!=NULL){
		if(r!=NULL){
			s.push(r);
			r=r->left;
		}
		else{
			cur=s.top();
			s.pop();
			cout<<cur->data<<endl;
			r=cur->right;
		}
	}
}
void BST::preorderStack(Node *root){
	stack<Node*>s;
	Node *r=root;
	Node *cur;
	while(!s.empty()||r!=NULL){
		if(r!=NULL){
			s.push(r);
			cout<<r->data<<endl;
			r=r->left;
		}
		else{
			cur=s.top();
			s.pop();
			r=cur->right;
		}
	}
}
void BST:: postorderStack(Node *root){
	stack<Node*>s1;
	stack<Node*>s2;
	Node *r=root;
	Node *temp;
	s1.push(r);
	while(!s1.empty()){
		r=s1.top();
		s1.pop();
		s2.push(r);
		if(r->left!=NULL)
			s1.push(r->left);
		if(r->right!=NULL)
			s1.push(r->right);
	}
	while(!s2.empty()){
		temp=s2.top();
		s2.pop();
		cout<<temp->data<<endl;
	}
}
void BST::displaySpiral(Node *root,int ht,bool val){
	if(root==NULL)
		return;
	if(ht==1)
		cout<<root->data<<" ";
	else if(ht>1){
		if(!val){
			displaySpiral(root->right,ht-1,val);
			displaySpiral(root->left,ht-1,val);
		}
		else{
			displaySpiral(root->left,ht-1,val);
			displaySpiral(root->right,ht-1,val);
		}
	}
}
void BST::spiralorder(Node *root){
	int ht=treeHeight(root);
	bool val=false;
	for(int i=1;i<=ht;i++){
		displaySpiral(root,i,val);
		val=!val;
		cout<<endl;
	}
}

		

int main(){
	BST *b=new BST;
	b->insert(5);
	b->insert(6);
	b->insert(8);
	b->insert(9);
	b->insert(1);
	cout<<"Inorder"<<endl;
	b->inorder(root);
	cout<<"levelorder"<<endl;
	b->levelorder(root);
	return 0;
	}
