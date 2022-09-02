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


Node* sortedBST(int arr[],int start,int end){
	if(start>end){
		return NULL;
	}
	int mid =(start+end)/2;
	Node* root=new Node(arr[mid]);
	
	root->left=sortedBST(arr,start,mid-1);
	root->right=sortedBST(arr,mid+1,end);
	
	return root;
}

void display(Node* n){
	if(n==NULL){
		return;
	}
	
	display(n->left);
	cout<<n->data<<" ";
	display(n->right);
}
int main(){
	int arr[]={10,20,30,40,50};
	Node* node=sortedBST(arr,0,4);
	display(node);
	
	return 0;
}