#include<iostream>
using namespace std;
void reverse(char str[200]);

int main(){
	char str[200];
    cout<<"Enter a string: ";
    cin>>str;
    reverse(str);
    cout<<"Reversed string \n"<<str;
    return 0;
}
void reverse(char str[]){
	int n=0, i;
    char temp;
    while (str[n]!='\0') {
        n++;
    }
    for(i=0;i<n/2;i++){
        temp=str[i];
        str[i]=str[n-i-1];
        str[n-i-1]=temp;
    }
}
