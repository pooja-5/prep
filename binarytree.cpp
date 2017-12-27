// BINARY TREE

#include<iostream>
#include<stdlib.h>
#include<queue>
#include<stack>
using namespace std;

struct Node{
        int data;
        Node *left,*right;
}*root=NULL;

class BT{
	public:
		Node *createNode(int);
		void insertBT(Node*,int);
		void inorder(Node*);
};
Node *BT::createNode(int data){
	Node *newNode=new Node;
	newNode->data=data;
	newNode->left=newNode->right=NULL;
	return newNode;
}
void BT::insertBT(Node *root,int data){
	queue<Node*>q;
	Node *temp;
	if(!root)
		root=createNode(data);
	q.push(root);
	while(!q.empty()){
		temp=q.front();
		q.pop();
		if(temp->left)
			q.push(temp->left);
		else{
			temp->left=createNode(data);
			break;
		}
		if(temp->right)
			q.push(temp->right);
		else{
			temp->right=createNode(data);
			break;
		}
	}
}
void BT::inorder(Node *root){
	if(root==NULL)
		return;
	inorder(root->left);
	cout<<root->data<<endl;
	inorder(root->right);
}

int main(){
	BT *bt=new BT;
	int data;
	cout<<"\nENter data to create root:";
	cin>>data;
	bt->insertBT(root,data);
	for(int i=10;i<=15;i++)
		bt->insertBT(i);
	bt->inorder(root);
	return 0;
}
