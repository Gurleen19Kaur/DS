#include<iostream>
using  namespace std;

void reverse(int a[100],int);

int main(){
	int n,i,a[100];
	cout<<"enter the number of elemnts";
	cin>>n;
	cout<<"enter the array elements";
	for(i=0;i<n;i++){
		cin>>a[i];
	}
	 reverse(a,n);
	cout<<"after reversing\n";
	for(i=0;i<n;i++){
		cout<<a[i]<<" ";
	}
	return 0;
}

void reverse(int a[], int n){
	int temp,i;
	for(i=0;i<n/2;i++){
		temp=a[i];
		a[i]=a[n-i-1];
		a[n-i-1]=temp;
	}
}
