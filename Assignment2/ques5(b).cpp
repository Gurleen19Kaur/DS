//tridiagonal matrix
#include<iostream>
#include<cmath>
using namespace std;
int main(){
	int i,j,n,a[100];
	cout<<"order of array ";
	cin>>n;
	
	cout<<"enter the array elements in row major order  ";
	int z=(3*n)-2;
	for(i=0;i<z;i++){
		cin>>a[i];
	}
	int k=0;
	 cout<<"triangular matrix \n";
	 for(i=0;i<n;i++){
	 	for(j=0;j<n;j++){
	 		if(abs(i-j)>1){
	 			cout<<"0 ";
			 }
			 else{
			 	cout<<a[k]<<" "; 
			 	k++;
			 }
		 } 
		 cout<<"\n";
	 }
	return 0;
	
}
