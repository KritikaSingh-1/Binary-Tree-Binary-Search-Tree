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

int countNode(Node* n1){
	if(n1==NULL){
		return 0;
	}
	static int sum=0;
	
	sum=countNode(n1->left)+countNode(n1->right)+n1->data;
	
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
	
	cout<<countNode(n1);
	return 0;
}