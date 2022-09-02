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

void sumTree(Node* root){
    if(root==NULL){
    	return;	
	}	
	
	
	sumTree(root->left);
	sumTree(root->right);
	if(root->left!=NULL){
		root->data+=root->left->data;
	}
	if(root->right!=NULL){
		root->data+=root->right->data;
	}
}

void preorder(Node* root){
	if(root==NULL){
		return;
	}
	cout<<root->data<<" ";
	preorder(root->left);
	preorder(root->right);
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
	sumTree(n1);
	preorder(n1);
	return 0;
}