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


int maxPathSumUtil(Node* root,int &ans){
	if(root==NULL){
		return 0;
	}
	int lefts=maxPathSumUtil(root->left,ans);
	int rights=maxPathSumUtil(root->right,ans);
	
	int NodeMax=max(max(root->data,root->data+lefts+rights),max(root->data+lefts,root->data+rights));
	ans=max(ans,NodeMax);
	
	int singlePathSum=max(root->data,max(root->data+lefts,root->data+rights));
    return singlePathSum;
}

int maxPathSum(Node* root){
	int ans=INT_MIN;
	maxPathSumUtil(root,ans);
	
	return ans;
}

int main(){
	Node* n1=new Node(1);
    
	n1->left=new Node(2);
	n1->right=new Node(3);
	
	n1->left->left=new Node(4);
	n1->left->right=new Node(5);
	
	n1->right->left=new Node(6);
	n1->right->right=new Node(7);
	cout<<maxPathSum(n1);
	return 0;
}