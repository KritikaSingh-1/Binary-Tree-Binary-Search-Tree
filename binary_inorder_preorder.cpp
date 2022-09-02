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

int search(int inorder[],int start,int end,int curr){
	for(int i=start;i<=end;i++){
		if(inorder[i]==curr){
			return i;
		}
	}
	
	return -1;
}

Node* buildTree(int preorder[],int inorder[],int start,int end){
    static int idx=0;
    if(start>end){
    	return NULL;
	}
    int curr=preorder[idx];
    idx++;
    Node* node=new Node(curr);
    if(start==end){
    	return node;
	}
    int pos=search(inorder,start,end,curr);
    node->left=buildTree(preorder,inorder,start,pos-1);
    node->right=buildTree(preorder,inorder,pos+1,end);
     
    return node; 
}

void display(Node* root){
	if(root==NULL){
		return;
	}
	display(root->left);
	cout<<root->data<<" ";
	display(root->right);
}

int main(){
	Node* n1=new Node(1);
	n1->left=new Node(2);
	n1->right=new Node(3);
	
	n1->left->left=new Node(4);
	n1->left->right=new Node(5);
	
	n1->right->left=new Node(6);
	n1->right->right=new Node(7);
	
	int preorder[]={1,2,4,3,5};
	int inorder[]={4,2,1,5,3};
	
	Node* root=buildTree(preorder,inorder,0,4);
	display(root);
	return 0;
}
