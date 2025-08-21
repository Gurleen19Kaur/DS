#include<iostream>
using namespace std;
int main(){
	int a[20], i, j, n;
	cout<<"enter the number of elements\n";
	cin>>n;
	cout<<"enter array elements\n";
	for(i=0;i<n;i++){
		cin>>a[i];
	}
	
	int inversion=0;
	
	for(i=0;i<n-1;i++){
		for(j=i+1;j<n;j++){
			if(a[i]>a[j]){
				inversion++;
			}
		}
	}
	cout<<"no of inversions "<<inversion<<" ";
	return 0;
}
