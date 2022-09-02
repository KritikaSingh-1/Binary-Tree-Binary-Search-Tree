#include<bits/stdc++.h>
using namespace std;

class Node{
public:
	int data;
	Node* left;
	Node* right;
	
	Node(int val){
		data=val;
		left=NULL;
		right=NULL;
	}	
};

Node* insertBST(Node* root,int val){
	if(root==NULL){
		return new Node(val);
	}
	if(val<root->data){
		root->left=insertBST(root->left,val);
	}
	else{
		root->right=insertBST(root->right,val);
	}
	return root;
}


void display(Node* root){
	if(root==NULL){
		return;
	}
	cout<<root->data<<" ";
	display(root->left);
	
	display(root->right);
}

Node* buildBST(int preorder[],int* preorderIdx,int key,int min,int max,int n){
	if(*preorderIdx>=n){
		return NULL;
	}
	Node* root=NULL;
	if(key>min && key<max){
		root=new Node(key);
		*preorderIdx=*preorderIdx+1;
		
		if(*preorderIdx<n){
			root->left=buildBST(preorder,preorderIdx,preorder[*preorderIdx],min,key,n);
		}
		if(*preorderIdx<n){
			root->right=buildBST(preorder,preorderIdx,preorder[*preorderIdx],key,max,n);
		
		}
	}
	return root;
}

int main(){
	int preorder[]={10,2,1,13,11};
    int n=5;
    int preorderIdx=0;
    Node* root=buildBST(preorder,&preorderIdx,preorder[0],INT_MIN,INT_MAX,n);
    display(root);
    cout<<endl;
    
	return 0;
}