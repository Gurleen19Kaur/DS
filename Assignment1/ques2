#include <iostream>
using namespace std;

int main(){
    int n,a[100],i,j,k;
    cout<<"Enter number of elements: ";
    cin>>n;

     cout<<"Enter array elements: ";
    for(i=0;i<n;i++)
        cin>>a[i];

    for(i=0;i<n;i++){
        for(j=i+1;j<n;j++){ 
            if(a[i]==a[j]){
                for(k=j;k<n-1;k++){ // shift to left
                    a[k]=a[k+1];
                }
                n--;     
                j--;     
            }
        }
    }

    cout<<"Array after removing duplicates: ";
    for(i=0;i<n;i++){
        cout<<a[i]<<" ";
    }

    return 0;
}
