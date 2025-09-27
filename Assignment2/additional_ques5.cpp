#include<iostream>
using namespace std;
int main(){
	int n,i;
	cout<<"enter the number of elements of array \n";
	cin>>n;
	int a[n];
	cout<<"enter array elements \n";
	for(i=0;i<n;i++){
		cin>>a[i];}
		
		

	//duplicating two
		for(i=0;i<n-1;i++){
			if(a[i]==2){
				for(int j=n;j>i;j--){
					a[j]=a[j-1];
					}
				a[i+1]=2;
				i++;
				n=n+1;
			}
		}
		cout<<"final array";
	for(i=0;i<n;i++){
		cout<<a[i]<<" ";
	}	
	return 0;}
