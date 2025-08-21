#include<iostream>
using namespace std;
void transpose(int a[20][3],int);
void bubblesort(int t[20][3], int);
int main(){
	int i , j , r , val, c ,a[20][3];
	cout<<"enter the rows columns and no of  non zero elements of sparse matrix \n";
	cin>>r>>c>>val;
	
	a[0][0]=r;
	a[0][1]=c; a[0][2]=val;
	
	cout<<"enter the non zero elemnts (row,column,value)\n";
	for(i=1;i<val+1;i++){
	 	cin>>a[i][0]>>a[i][1]>>a[i][2];}
	cout<<"transposed matrix\n";
	transpose(a, val);
	return 0;
}

void transpose(int a[][3], int val){
	int t[20][3],i,j;
 // storing it in another matrix named t
	for(i=0;i<val+1;i++){
		     t[i][0]=a[i][1];
		     t[i][1]=a[i][0];
		     t[i][2]=a[i][2];
				}
				bubblesort(t,val+1);
				for(i=0;i<val+1;i++){
					for(j=0;j<3;j++){
						cout<<t[i][j]<<" ";
					} cout<<"\n";
				}
	
}

void bubblesort(int t[20][3], int n){
	int i , j ,temp , k;
	
	for(i=0;i<n-1;i++){
		for(j=0;j<n-i-1;j++){
			if(t[j][0]>t[j+1][0] || ((t[j][0]==t[j+1][0])&& (t[j][1]>t[j+1][1])) ) {
				for(k=0;k<3;k++){
				
				temp=t[j][k];
				t[j][k]=t[j+1][k];
				t[j+1][k]=temp;}
			}
		}
	}
}
