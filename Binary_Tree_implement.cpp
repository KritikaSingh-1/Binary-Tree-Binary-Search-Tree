/*
maximum nodes at level L=2^L
maximum nodes in a tree of height H is 2^H-1
minimum number of levels or height is log2(N+1)
a binary tree with L leaves has at least log2(N+1)+1 number of levels

*/

#include<bits/stdc++.h>
using namespace std;

class Node{
public:
	int data;
	Node* left;
	Node*right;
	
	Node(int val){
		data=val;
		left=NULL;
		right=NULL;
	}
	
	
};
void preorder(Node* root){
		if(root==NULL){
			return;
		}
		cout<<root->data<<" ";
		preorder(root->left);
		preorder(root->right);
}

void inorder(Node* root){
	if(root==NULL){
		return;
	}
	inorder(root->left);
	cout<<root->data<<" ";
	inorder(root->right);
}

void postorder(Node* root){
	if(root==NULL){
		return;
	}
	postorder(root->left);
	postorder(root->right);
	cout<<root->data<<" ";
}

int main(){
	Node* n1=new Node(1);
	n1->left=new Node(2);
	n1->right=new Node(3);
	
	n1->left->left=new Node(4);
	n1->left->right=new Node(5);
	
	n1->right->left=new Node(6);
	n1->right->right=new Node(7);
	preorder(n1);
	cout<<endl;
	inorder(n1);
	cout<<endl;
	postorder(n1);
	return 0;
}