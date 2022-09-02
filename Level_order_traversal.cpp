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

int printLevelorder(Node* root,int k){
	if(root==NULL){
		return -1;
	}
	queue<Node*> q;
	q.push(root);
	q.push(NULL);
	int level=0,sum=0;
	
	while(!q.empty()){
		Node* node=q.front();
		q.pop();
		if(node!=NULL){
			if(level==k){
				sum+=node->data;
			}
			 
			if(node->left){
				q.push(node->left);
			}
			if(node->right){
				q.push(node->right);
			}
		}
		else if(!q.empty()){
			q.push(NULL);
			level++;
		}
		
	}
	return sum;
}

int main(){
	Node* n1=new Node(1);

	n1->left=new Node(2);
	n1->right=new Node(3);
	
	n1->left->left=new Node(4);
	n1->left->right=new Node(5);
	
	n1->right->left=new Node(6);
	n1->right->right=new Node(7);
	int k;
	cin>>k;
	cout<<printLevelorder(n1,k);
	return 0;
}