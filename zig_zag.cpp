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



void zigzag(Node* root){
	if(root==NULL){
		return;
	}
	stack<Node*>  curr;
	stack<Node*> next;
	bool leftToRight=true;
	
	curr.push(root);
	while(!curr.empty()){
		Node* temp=curr.top();
		curr.pop();
		
		if(temp){
			cout<<temp->data<<" ";
		
		
		if(leftToRight){
			if(temp->left){
				next.push(temp->left);
			}
			if(temp->right){
				next.push(temp->right);
			}
		}
		
		else{
			if(temp->right){
				next.push(temp->right);
			}
			if(temp->left){
				next.push(temp->left);
			}
		}
		
	 
	}
	if(curr.empty()){
		leftToRight=!leftToRight;
		swap(curr,next);
	}
		
	}
}

int main(){
	Node* n1=new Node(12);
	n1->left=new Node(9);
	n1->right=new Node(15);
	n1->left->right=new Node(10);

	n1->left->left=new Node(5);
	
	
	zigzag(n1);
	cout<<endl;
	return 0;
}