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

void swap(int *a,int *b){
	int temp=*a;
	*a=*b;
	*b=temp;
}

void calcpoint(Node* root,Node** first,Node** mid,Node** last,Node** prev){
	if(root==NULL){
		return;
	}
	calcpoint(root->left,first,mid,last,prev);
	
	if(*prev && root->data<(*prev)->data){
		if(!*first){
			*first=*prev;
			*mid=root;
		}
		else{
			*last=root;
			
		}
	}
	*prev =root;
	calcpoint(root->right,first,mid,last,prev);
}

void restoreBST(Node* root){
	
	Node* first,*mid,*last,*prev;
	first=NULL;
	mid=NULL;
	last=NULL;
	prev=NULL;
	
	calcpoint(root,&first,&mid,&last,&prev);
	
	//case1
	if(first && last){
		swap(&(first->data),&(last->data));
	}
	else if(first && mid){
		swap(&(first->data),&(mid->data));
	}
	
}

void inorder(Node* n1){
	if(n1==NULL){
		return;
	}
	inorder(n1->left);
	cout<<n1->data<<" ";
	inorder(n1->right);
}

int main(){
	
	Node* n1=new Node(6);
	n1->left=new Node(9);
	n1->right=new Node(3);	
	n1->left->left=new Node(1);
	n1->left->right=new Node(4);
	n1->right->right=new Node(13);
	inorder(n1);
	cout<<endl;
    restoreBST(n1);
    inorder(n1);
    cout<<endl;
	return 0;
}