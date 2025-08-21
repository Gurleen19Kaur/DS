#include<iostream>
using namespace std;
void bubblesort(int c[20][3], int );
int main(){
	int i , j , r1 , val1, c1 ,a[20][3],c[20][3];
		// input matrix A
	cout<<"enter the rows columns and no of  non zero elements of A sparse matrix \n";
	cin>>r1>>c1>>val1;
	
	a[0][0]=r1;
	a[0][1]=c1; a[0][2]=val1;
	
	cout<<"enter the non zero elemnts of A (row,column,value)\n";
	for(i=1;i<val1+1;i++){
	 	cin>>a[i][0]>>a[i][1]>>a[i][2];}
	 	// input matrix B
	 	int r2,c2,val2,b[20][3];
	 	cout<<"enter the rows columns and no of  non zero elements of B sparse matrix \n";
	cin>>r2>>c2>>val2;
	
	b[0][0]=r2;
	b[0][1]=c2; b[0][2]=val2;
	
	cout<<"enter the non zero elemnts OF B (row,column,value)\n";
	for(i=1;i<val2+1;i++){
	 	cin>>b[i][0]>>b[i][1]>>b[i][2];}
	 	
	 	cout<<"Result of addition is : \n"; 
		 int k=0;
		 i=1,j=1;
	 	while(i<val1+1 && j<val2+1){
	 			if(a[i][0]==b[j][0]&&a[i][1]==b[j][1]){
	 			
	 				c[k][0]=a[i][0];
	 				c[k][1]=a[i][1];
	 				c[k][2]=a[i][2]+b[j][2]; k++;
	 				i++;j++;}
	 				else if(a[i][0]<b[j][0] || (a[i][1]==b[j][1])&&a[i][1]<b[j][1]){
	 					c[k][0]=a[i][0];
	 				c[k][1]=a[i][1];
	 				c[k][2]=a[i][2]; k++;
					 i++;}
					 else{
					 	c[k][0]=b[j][0];
	 				c[k][1]=b[j][1];
	 				c[k][2]=b[j][2]; k++;
					j++;}
			 }
		 
		 bubblesort(c,k); //function call for sorting

		 for(i=0;i<k;i++){
		 	for(j=0;j<3;j++){
		 		cout<<c[i][j]<<"  ";
			 } cout<<"\n";
		 }
	 	
	 return 0; 	
}

void bubblesort(int c[20][3], int n){
	int i , j ,temp , k;
	
	for(i=0;i<n-1;i++){
		for(j=0;j<n-i-1;j++){
			if(c[j][0]>c[j+1][0] || ((c[j][0]==c[j+1][0])&& (c[j][1]>c[j+1][1])) ) {
				for(k=0;k<3;k++){
				
				temp=c[j][k];
				c[j][k]=c[j+1][k];
				c[j+1][k]=temp;}
			}
		}
	}
}
