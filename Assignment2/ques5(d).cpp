//upper triangular matrix

#include<iostream>
using namespace std;
int main(){
	int i,j,n,a[100];
	cout<<"order of array ";
	cin>>n;
	
	cout<<"enter the array elements in row major order  "; //size of 1 d array is n(n+1)/2 
	int z= (n*(n+1))/2;
	for(i=0;i<z;i++){
		cin>>a[i];
	}
	int k=0;
	 cout<<" upper triangular matrix \n"; // to print the array elements
	 for(i=0;i<n;i++){
	 	for(j=0;j<n;j++){
	 		if(i>j){
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
