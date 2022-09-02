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


bool check(Node* n1,Node* min=NULL,Node* max=NULL){
	if(n1==NULL){
		return true;
	}

	if( min!=NULL && min->data >= n1->data){
		return false;
	}
	if(max!=NULL && max->data <= n1->data){
		return false;
	}
	
	bool lvalid=check(n1->left,min,n1);
	bool rvalid=check(n1->right,n1,max);
	
	return lvalid and rvalid;
}

int main(){
	Node* root=new Node(1);
	root->left=new Node(2);
	root->right=new Node(3);
	
     if(check(root,NULL,NULL)){
     	cout<<"valid"<<endl;
	 }
	 else{
	 	cout<<"not valid"<<endl;
	 }
	return 0;
}