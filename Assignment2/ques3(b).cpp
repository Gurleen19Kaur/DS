#include<iostream>
using namespace std;
int missing(int a[100], int);
int i;
int main(){
	int n;
	cout<<"enter number of elements";
	cin>>n;
	
	int a[n];
	cout<<"enter sorted array\n";
	for(i=0;i<n-1;i++){
        cin>>a[i];
    }
    cout<<"missing num \n"<<missing(a,n);
    return 0;
	}
	
	int missing(int a[],int n){
		int low=0,high=n-1;
    while(low<=high){
        int mid=(low+high)/2;
        if(a[mid]==mid+1) low=mid+1;
        else high=mid-1;
    }
    return low+1;
	}
