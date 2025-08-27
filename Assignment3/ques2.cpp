#include<iostream>
using namespace std;
#define n 100
 
class stack{
	
	public:
	char stack[n];
	int top=-1; 
	
	void push(string a  ){
			if(top==n-1){
		cout<<"overflow!!";
	}
	else{
	
	int z=0;
	while(a[z]!='\0'){
		 z++;
	}
	
	 
	for(int i=0;i<z;i++){
		top++;
      stack[top]=a[i];
		}
	}
	}
	
	void display(){
		for(int i=top;i>=0;i--){
			cout<<stack[i]<<" ";
		}
	
	}
	};
	
	int main(){
		stack s;
		string a ="datastructures";
		 s.push(a);
		 s.display();
		 
	}
