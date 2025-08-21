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
	
	int count=0;
	for(i=0;i<n;i++){
		for(j=0;j<i;j++){
			if(a[i]==a[j]){
				break;
			}
			}
				if(i==j){
				count ++;
		}
	}
	
	cout<<"number of distinct element "<<count<<"  ";
	return 0;
}
