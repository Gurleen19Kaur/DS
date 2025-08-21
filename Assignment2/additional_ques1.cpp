#include<iostream>
#include<cmath>
using namespace std;

int main(){
	int n,i,j;
	cout<<"enter the number of elements of array \n";
	cin>>n;
	int a[n];
	cout<<"enter array elements";
	for(i=0;i<n;i++){
		cin>>a[i];
	}
	int k;
	cout<<"enter the value of k(difference)\n";
	cin>>k;
	int count =0;
	for(i=0;i<n;i++){
		for(j=i+1;j<n;j++){
			if(abs(a[i]-a[j])==k){
				count++;
			}
				
			}
		}
	cout<<"number of such pairs "<<count<<" ";
	return 0;	
	}
