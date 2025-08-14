#include<iostream>
using namespace std;
void bubblesort(int a[100],int);
void printarr(int a[100],int);
int i,j,temp;
int main(){
int a[]={64,34,25,12,22,11,9};
int n=sizeof(a)/sizeof(a[0]);
int i,j,temp;
bubblesort(a,n);
cout<<"sorted array";
printarr(a,n);
return 0;}

void bubblesort(int a[],int n){
  
for(i=0;i<n-1;i++){
   for(j=0;j<n-i-1;j++){
    if(a[j]>a[j+1]){
      temp=a[j];
        a[j]=a[j+1];
            a[j+1]=temp;
                }  
                    }
                        }
						}
						
void printarr(int a[], int n){
 
        for(i=0;i<n;i++) {
		cout<<a[i]<<" ";
		}
		}
