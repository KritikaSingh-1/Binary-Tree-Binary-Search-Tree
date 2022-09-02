#include<bits/stdc++.h>
using namespace std;
const int n=5;

int path(int i,int idx,int a[n][n]){
	if(idx<0 && idx>=n){
		return 0;
	}
	if(i==n-1){
		return a[i][idx];
	}
	int x=path(i-1,idx+1,a)+a[i][idx];
	int y=path(i+1,idx+1,a)+a[i][idx];
	int z=path(i+1,idx,a)+a[i][idx];
	return max(x,max(y,z));
}

int main(){
	int a[n][n];
	for(int =0;i<n;i++){
		for(int j=0;j<n;j++){
			cin>>a[i][j];
		}
	}
	int ans=0;
	for(int i=0;i<n;i++){
	    int y=	path(i,0,a);
	    ans=max(ans,y);
	}
	
	cout<<ans;
	return 0;
}
