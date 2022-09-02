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

class Info{
	public:
		int size;
		int max;
		int min;
		int ans;
		int isBST;
};

Info largestBSTinBT(Node* root){
	if(root==NULL){
		return {0,INT_MIN,INT_MAX,0,true};
	}
	if(root->left==NULL && root->right==NULL){
		return {1,root->data,root->data,1,true};
	}
	
	Info lInfo=largestBSTinBT(root->left);
	Info rInfo=largestBSTinBT(root->right);
	
	Info curr;
	curr.size=(1+lInfo.size+rInfo.size);
	if(lInfo.isBST && rInfo.isBST && lInfo.max<root->data && rInfo.min>root->data){
		curr.min=min(lInfo.min,min(rInfo.min,root->data));
        curr.max=max(lInfo.max,max(rInfo.max,root->data));
        
        curr.ans=curr.size;
        curr.isBST=true;
        
        return curr;
    } 
    
    curr.ans=max(lInfo.ans,rInfo.ans);
    curr.isBST=false;
    return curr;
    
}


int main(){
	
	Node* n1=new Node(15);
	n1->left=new Node(20);
	n1->right=new Node(30);	
	n1->left->left=new Node(5);
	
    cout<<largestBSTinBT(n1).ans<<endl;
	return 0;
}