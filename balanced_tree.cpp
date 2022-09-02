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

int Theight(Node* n1){
	if(n1==NULL){
		return 0;
	}
	int lheight=Theight(n1->left);
	int rheight=Theight(n1->right);
	return max(lheight,rheight)+1;

}

bool balancedTree(Node* n1){
	if(n1==NULL){
		return true;
	}
	
	if(balancedTree(n1->left)==false){
		return false;
	}
	if(balancedTree(n1->right)==false){
		return false;
	}
	
	int lh=Theight(n1->left);
	int rh=Theight(n1->right);
	if(abs(lh-rh) <=1){
		return true;
	}
	else{
		return false;
	}
	
}

bool balancedT(Node* n1,int* height){
	if(n1==NULL){
		*height=NULL;
		return true;
	}
	
	int lh=0;
	int rh=0;
	
	if(balancedT(n1->left, &lh)==false){
		return false;
	}
	if(balancedT(n1->right, &rh)==false){
		return false;
	}
	
	*height=max(lh,rh)+1;
	if(abs(lh-rh) <=1){
		return true;
		
	}
	else{
		return false;
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
	
	
	Node* n2=new Node(1);
	n2->left=new Node(2);
	n2->left->left=new Node(3);
	
	
	bool c=balancedTree(n2);
	if(c==true){
		cout<<"Balanced tree";
	}
	else{
		cout<<"Unbalanced Tree";
	}
	cout<<endl;
	int height=0;
	int x=balancedT(n2,&height);
	if(x==true){
		cout<<"Balanced tree";
	}
	else{
		cout<<"Unbalanced Tree";
	}
	
	return 0;
}