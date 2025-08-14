#include<iostream>
using namespace std;

int main(){
    char ch;
    cout<<"Enter an uppercase character\n";
    cin>>ch;

    if(ch>='A' && ch<='Z'){
        ch=ch+32; 
        cout<<"Lowercase \n"<<ch;
    }
    else{
        cout<<"Not an uppercase letter!";
    }

    return 0;
}
