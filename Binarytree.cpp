#include<iostream>
#include<stdlib.h>
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
	
int main(){
	BST* b=new BST;
	char ch='y';
	int opt,data;
	cout<<"Enter data to create root:";
	cin>>data;
	b->insert(data);
	while(ch=='y'){
		cout<<"\n1.Insert\n2.Inorder\n3.Preorder\n4.Postorder\n5.Level order\n";
		cout<<"\nEnter option:";
		cin>>opt;
		switch(opt){
			case 1:
				cout<<"\nEnter data to insert:";
				cin>>data;
				b->insert(data);
				break;
			case 2:
				cout<<"\nInorder traversal"<<endl;
				b->inorder(root);
				break;
			case 3:
				cout<<"\nPreorder"<<endl;
				b->preorder(root);
				break;
			case 4:
				cout<<"\nPostorder"<<endl;
				b->postorder(root);
				break;
			case 5:
				cout<<"\nLevelorder"<<endl;
				b->levelorder(root);
				break;
			default:exit(0);
		}
	}
	return 0;
	}
