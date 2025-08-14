#include<iostream>
using namespace std;
int main(){
int n,a[100],i,j,num,low,high,mid;
cout<<"Enter number of elements ";
cin>>n;
cout<<"Enter elements in sorted order \n";
for(i=0;i<n;i++) cin>>a[i];
cout<<"Enter element to search ";
cin>>num;

low=0;high=n-1;

while(low<=high){
mid=(low+high)/2;

if(a[mid]==num){
cout<<"Element found at position "<<mid+1;
return 0;
}
else if(a[mid]<num){
low=mid+1;}
else if(a[mid]>num){
high=mid-1;}
}
cout<<"Element not found";
return 0;
}
