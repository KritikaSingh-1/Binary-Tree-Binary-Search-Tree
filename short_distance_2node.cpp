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

Node* LCA(Node* root,int n1,int n2){
	if(root==NULL){
		return NULL;
	}
	if(root->data==n1 || root->data==n2){
		return root;
	}
	
	Node* left= LCA(root->left,n1,n2);
	Node* right= LCA(root->right,n1,n2);
	
	if(left!=NULL && right!=NULL){
		return root;
	}
	if(left==NULL && right==NULL){
		return NULL;
	}
	
	if(left!=NULL){
		return left;
	}
	
		return right;
	
}

int findDst(Node* root,int k,int dist){
	if(root==NULL){
		return -1;
	}
	if(root->data==k){
		return dist;
	}
	
	int left=findDst(root->left,k,dist+1);
	if(left!=-1){
		return left;
	}
	return findDst(root->right,k,dist+1);
}

int distance(Node*root,int n1,int n2){
	Node* lca=LCA(root,n1,n2);
	int d1=findDst(lca,n1,0);
	int d2=findDst(lca,n2,0);
	
	return d1+d2;
}
int main(){
	Node* n1=new Node(1);

	n1->left=new Node(2);
	n1->right=new Node(3);
	
	n1->left->left=new Node(4);
//	n1->left->right=new Node(5);
	
//	n1->right->left=new Node(6);
	n1->right->right=new Node(5);
	
	cout<<distance(n1,4,5);
	return 0;
}
