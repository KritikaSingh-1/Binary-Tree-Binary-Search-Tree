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
//0(n^2)
int catalan(int n){
	if(n<=1){
		return 1;
	}
	int res=0;
	for(int i=0;i<n;i++){
		res+= catalan(i)* catalan(n-i-1);
	}
	return res;
	
}

//Possible bst
vector<Node*> constructTrees(int start,int end){
	vector<Node*> trees;
	if(start>end){
		trees.push_back(NULL);
		return trees;
	}
	for(int i=start;i<=end;i++){
		vector<Node*> leftSubtrees=constructTrees(start,i-1);
		vector<Node*> rightSubtrees=constructTrees(i+1,end);
		
		for(int j=0;j<leftSubtrees.size();j++){
			Node* left=leftSubtrees[j];
			for(int k=0;k<rightSubtrees.size();k++){
				Node* right=rightSubtrees[k];
				Node* node=new Node(i);
				node->left=left;
				node->right=right;
				trees.push_back(node);
			}
		}	
	}
	return trees;
}


void display(Node* n){
	if(n==NULL){
		return;
	}
	cout<<n->data<<" ";
	display(n->left);
	
	display(n->right);
}
int main(){
/*	for(int i=0;i<10;i++){
		cout<<catalan(i)<<" ";
	}
	cout<<endl;*/
	//bst
	vector<Node*> totalTrees=constructTrees(1,3);
	for(int i=0;i<totalTrees.size();i++){
		cout<<(i+1)<<" : ";
		display(totalTrees[i]);
		cout<<endl;
	}
	
	return 0;
}