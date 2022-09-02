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

void flatten(Node* n1){
	if(n1==NULL ||(n1->left==NULL && n1->right==NULL)){
		return;
	}
	
	if(n1->left!=NULL){
		flatten(n1->left);
		
		Node* temp=n1->right;
		n1->right=n1->left;
		Node* t=n1->right;
		
		n1->left=NULL;		
		
		while(t->right!=NULL){
			t=t->right;
		}
		t->right=temp;
    }
    
    if(n1->right!=NULL){
    	flatten(n1->right);	
	}
}

void inorderPrint(Node* root)
{
	if(root==NULL){
		return;
	}
	inorderPrint(root->left);
	cout<<root->data<<" ";
	inorderPrint(root->right);
}

int main(){
	Node* n1=new Node(1);

	n1->left=new Node(2);
	n1->right=new Node(3);
	
	n1->left->left=new Node(4);
	n1->left->right=new Node(5);
	
	n1->right->left=new Node(6);
	n1->right->right=new Node(7);
	
	inorderPrint(n1);
	cout<<endl;
    flatten(n1);
    inorderPrint(n1);
    cout<<endl;
    return 0;
}