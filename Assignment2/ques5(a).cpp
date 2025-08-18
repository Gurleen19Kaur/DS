//diagonal matrix

#include<iostream>
using namespace std;
int main(){
int i,j,n,a[100];
cout<<"enter the order of square matrix  ";
cin>>n;

cout<<"enter the non zero array elements  ";
for(i=0;i<n;i++){	
	cin>>a[i];
}	

for(i=0;i<n;i++){
	for(j=0;j<n;j++){
		if(i==j){
			 cout<<a[i]<<" ";
		}
		else{
		 cout<<"0 "; 
		}
	} 
	cout<<"\n";
} 
return 0;
}
 
