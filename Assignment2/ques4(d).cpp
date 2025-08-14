#include<iostream>
using namespace std;

int main(){
    int n,i,j,k;
    char str[50][50],temp[50];
    
    cout<<"Enter number of strings \n";
    cin>>n;
    
    cout<<"Enter "<<n<<" strings \n";
    for(i=0;i<n;i++){
        cin>>str[i];
    }
    
    for(i=0;i<n-1;i++){
        for(j=i+1;j<n;j++){
            k=0;
            while(str[i][k]==str[j][k] && str[i][k]!='\0'){
                k++;
            }
            if(str[i][k]>str[j][k]){
                for(k=0;k<50;k++){
				temp[k]=str[i][k];
				str[i][k]=str[j][k];
				str[j][k]=temp[k];
				}
            }
        }
    }
    cout<<"Strings in alphabetical order:\n";
    for(i=0;i<n;i++){
        cout<<str[i]<<"\n";
    }
    return 0;
}
