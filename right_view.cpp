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

void rightView(Node* root){
	if(root==NULL){
		return;
	}
	
	queue<Node*> q;
	q.push(root);
	
	
	while(!q.empty()){
		int n=q.size();
		for(int i=0;i<n;i++){
			Node* curr=q.front();
			q.pop();
			if(i==n-1){
				cout<<curr->data<<" ";
			}
			
			if(curr->left!=NULL){
				q.push(curr->left);
			}
			if(curr->right!=NULL){
				q.push(curr->right);
			}
		}
	}
}

int main(){
	Node* n1=new Node(1);

	n1->left=new Node(2);
	n1->right=new Node(3);
	
	n1->left->left=new Node(4);
	n1->left->right=new Node(5);
	
	n1->right->left=new Node(6);
	n1->right->right=new Node(7);
	
	rightView(n1);
	return 0;
}