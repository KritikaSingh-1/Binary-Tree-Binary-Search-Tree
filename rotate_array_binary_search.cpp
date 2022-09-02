#include<iostream>
using namespace std;

int rotateArray(int arr[],int key,int left,int right){
	if(left>right){
		return -1;
	}
	int mid=(left+right)/2;
	if(arr[mid]==key){
		return mid;
	}
	if(arr[left]<=arr[mid]){
		if(key>=arr[left] && key<=arr[mid]){
			return rotateArray(arr,key,left,mid-1);
		}
		
		return rotateArray(arr,key,mid+1,right);
	}
	if(key>=arr[mid] && key<=arr[right]){
		return rotateArray(arr,key,mid+1,right);
	}
	return rotateArray(arr,key,left,mid-1);
		
}

int main(){
	int arr[]={6,7,8,9,10,1,2,5};
	int n=8;
	int idx=rotateArray(arr,8,0,n-1);
	if(idx==-1){
		cout<<"Key doesnt exist"<<endl;
	}
	else{
		cout<<idx<<endl;
	}
	
	return 0;
}