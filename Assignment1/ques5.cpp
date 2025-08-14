#include<iostream>
using namespace std;
int main(){
int m,n,a[100][100],i,j;

cout<<"Enter rows and columns";
cin>>m>>n;

cout<<"Enter array elements\n";
for(i=0;i<m;i++){
  for(j=0;j<n;j++){
    cin>>a[i][j];
    }
        } 
for(i=0;i<m;i++){
    int sum=0;
    for(j=0;j<n;j++){
	sum+=a[i][j];}
    cout<<"Sum of row "<<i+1<<"=  "<<sum<<endl;
	
	}
for(j=0;j<n;j++){
    int sum=0;
    for(i=0;i<m;i++){
	sum+=a[i][j];}
    cout<<"Sum of column "<<j+1<<"=  "<<sum<<endl;
	}

return 0;
}
