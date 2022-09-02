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

bool identical(Node* root1,Node* root2){
	if(root1==NULL && root2==NULL){
		return true;
	}
	else if(root1!=NULL && root2!=NULL){
		bool r1=(root1->data==root2->data);
		bool l=identical(root1->left,root2->left);
		bool r=identical(root1->right,root2->right);
		return l && (r && r1);
	}
	return false;
}


int main(){
	Node* n3=NULL;
	Node* n1=new Node(1);
	n1->right=new Node(3);
	n1->right->right=new Node(5);
	n1->right->left=new Node(2);
	
	Node* n4=NULL;
	Node* n2=new Node(1);
	n2->right=new Node(3);
	n2->right->right=new Node(5);
	n2->right->left=new Node(2);
	
	if(identical(n1,n2)){
		cout<<"identical"<<endl;
	}
	else{
		cout<<"NOT identical"<<endl;
	}

	return 0;
}