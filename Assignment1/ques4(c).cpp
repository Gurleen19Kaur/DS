#include<iostream>
using namespace std;
int main(){
	
int m,n;
int a[100][100],t[100][100];
cout<<"Enter rows and columns of the matrix \n";
cin>>m>>n;
int i,j;

cout<<"Enter elements of the matrix \n";
for(i=0;i<m;i++){
for(j=0;j<n;j++){
cin>>a[i][j];
}
}
//transpose
for(i=0;i<m;i++){
	for(j=0;j<n;j++){
		t[j][i]=a[i][j];
	}
}
cout<<"transpose of matrix \n";
for(i=0;i<n;i++){
for(j=0;j<m;j++){
cout<<t[i][j]<<" ";}
cout<<endl;
}
return 0;}
