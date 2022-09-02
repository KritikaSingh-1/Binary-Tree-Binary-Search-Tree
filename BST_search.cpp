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
	display(root->left);
	cout<<root->data<<" ";
	display(root->right);
}


Node* search(Node* n1,int key){
	if(n1==NULL){
		
		return NULL;
	}
	if(n1->data==key){
		
		return n1;
	}
	else if(key<n1->data){
		search(n1->left,key);
		
	}
	else{
		search(n1->right,key);
		
	}
	
}

Node* inorderSucc(Node* root){
	Node* curr=root;
	while(curr && curr->left!=NULL){
		curr= curr->left;
	}
	return curr;
}
Node* deleteBST(Node* root,int key){
	if(root==NULL){
		return NULL;
	}
	if(key<root->data){
		root->left=deleteBST(root->left,key);
	    
	}
	else if(key>root->data){
		root->right=deleteBST(root->right,key);
	
	}
	else{
		if(root->left==NULL ){
			Node* temp=root->right;
			free(root);
			return temp;
		}
		else if(root->right==NULL ){
			Node* temp=root->left;
			free(root);
			return temp;	
		}
		
		Node* temp=inorderSucc(root->right);
		root->data=temp->data;
		root->right=deleteBST(root->right,temp->data);
		
	}
	return root;
}


int main(){
	Node* root=NULL;
	root=insertBST(root,5);
	insertBST(root,1);
	insertBST(root,3);
	insertBST(root,4);
	insertBST(root,2);
	insertBST(root,7);
    display(root);
    cout<<endl;
    
    Node* n=search(root,5);
    if(n==NULL){
    	cout<<"Not exist";
	}
	else{
		cout<<"Exist";
	}
    cout<<endl;
    
    deleteBST(root,7);
    display(root);
	return 0;
}