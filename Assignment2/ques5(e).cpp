//symmetric matrix

#include<iostream>
using namespace std;
int main(){
	int i,j,n,a[100];
	cout<<"order of array ";
	cin>>n;
	
	cout<<"enter the array elements in row major order (lower triangular matrix)  ";
	int z= (n*(n+1))/2;
	for(i=0;i<z;i++){
		cin>>a[i];
	} int k=0;
	 cout<<" symmetric matrix \n";
	 for(i=0;i<n;i++){
	 	for(j=0;j<n;j++){ 
	 		if(i>=j){
			 	cout<<a[k]<<" "; 
			 	k++;}
			 	else{
			 	int m = j * (j + 1) / 2;
                cout << a[m + i]<<" ";

				 }
			 }	 cout<<"\n";
		 }  
	 return 0;
}
