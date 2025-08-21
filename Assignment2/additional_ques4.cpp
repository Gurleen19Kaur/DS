#include<iostream>
using namespace std;
int main(){
	int n,i;
	cout<<"enter the number of elements of array \n";
	cin>>n;
	int a[n];
	cout<<"enter array elements(containg only 0 ,1,2)\n";
	for(i=0;i<n;i++){
		cin>>a[i];}
		
		// count the 0 ,1,2
		int c0=0,c1=0,c2=0;
		for(i=0;i<n;i++){
			if(a[i]==0){
				c0++;
			}
			if(a[i]==1){
				c1++;
			}
			if(a[i]==2){
				c2++;
			}
		}
		int b[n];
		for(i=0;i<c0;i++){
			b[i]=0;
		}
		for(;i<c0+c1;i++){
			b[i]=1;
		}
		for(;i<c0+c1+c2;i++){
			b[i]=2;
		}
		
		cout<<"the sorted array is: \n";
		for(i=0;i<n;i++){
			cout<<b[i]<<" ";
		}
return 0;
}
