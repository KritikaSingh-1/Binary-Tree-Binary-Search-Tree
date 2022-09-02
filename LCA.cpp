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

bool getPath(Node* n1,int n,vector<int> &path){
	if(n1==NULL){
		return false;
	}
	path.push_back(n1->data);
	if(n1->data==n){
		return true;
	}
	if(getPath(n1->left,n,path) || getPath(n1->right,n,path)){
		return true;
	}
	path.pop_back();
	return false;
}

int ancestor(Node* root,int n1,int n2){
	vector<int> path1,path2;
	if(!getPath(root,n1,path1) || !getPath(root,n2,path2)){
		return -1;
	}
	int pc;
	for(pc=0;pc<path1.size() && path2.size();pc++){
		if(path1[pc]!=path2[pc]){
			break;
		}
	}
	return path1[pc-1];
}

//second method

Node* LCA2(Node* root,int n1,int n2){
	if(root==NULL){
		return NULL;
	}
	if(root->data==n1 ||root->data==n2){
		return root;
	}
	Node* leftLCA=LCA2(root->left,n1,n2);
	Node* rightLCA=LCA2(root->right,n1,n2);
	
	if(leftLCA && rightLCA){
		return root;
	}
	if(leftLCA!=NULL){
		return leftLCA;
	}
	return rightLCA;
}


int main(){
	Node* n1=new Node(1);

	n1->left=new Node(2);
	n1->right=new Node(3);
	
	n1->left->left=new Node(4);
	n1->left->right=new Node(5);
	
	n1->right->left=new Node(6);
	n1->right->right=new Node(7);
    
    int lca=ancestor(n1,4,5);
    if(lca==-1){
    	cout<<"Not exist"<<endl;
	}
	else{
	    cout<<"Lca:"<<lca<<endl;	
	}
	
    Node* Lca =LCA2(n1,4,5);
    if(Lca==NULL){
    	cout<<"Not exist"<<endl;
	}
	else{
	    cout<<"Lca:"<<Lca->data<<endl;	
	}
    return 0;
}