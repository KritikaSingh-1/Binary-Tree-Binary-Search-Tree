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
//case 1
void NodeAtK(Node* root,int k){
	if(root==NULL || k<0){
		return;
	}
	if(k==0){
		cout<<root->data<<" "<<endl;
	}
	if(k>0){
		NodeAtK(root->left,k-1);
		NodeAtK(root->right,k-1);		
	}
}

//case 2
int printNodesAtK(Node* root,Node* target,int k){
	if(root==NULL){
		return -1;
	}
	
	if(root==target){
		NodeAtK(root,k);
		return 0;
	}
	
	int dl = printNodesAtK(root->left,target,k);
	if(dl!=-1){
		if(dl+1==k){
			cout<<root->data<<" ";
		}else{
			NodeAtK(root->right,k-dl-2);
		}
		return 1+dl;
	}
	
	int dr=printNodesAtK(root->right,target,k);
	if(dr!=-1){
		if(dr+1==k){
			cout<<root->data<<" ";
		}else{
			NodeAtK(root->left,k-dr-2);
		}
		return 1+dr;
	}
	
	return -1;
}

int main(){
	Node* n1=new Node(1);

	n1->left=new Node(2);
	n1->right=new Node(3);
	
	n1->left->left=new Node(4);
	n1->left->right=new Node(5);
	
	n1->right->left=new Node(6);
	n1->right->right=new Node(7);
	
    printNodesAtK(n1,n1->left,1);
    return 0;
}