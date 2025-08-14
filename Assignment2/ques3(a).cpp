#include<iostream>
using namespace std;
int main(){
	int i,missing;
	int a[]={1,2,3,4,6,7,8};
	int n=sizeof(a)/sizeof(a[0]);
	
	for(i=0;i<n-1;i++){
    if(a[i]!=i+1){
    missing=i+1;
    break;
}
}
cout<<"Missing number: "<<missing;
return 0;
}
