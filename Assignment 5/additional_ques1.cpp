#include<iostream>
using namespace std;

class Node{
	public:
		int data;
		Node *next;
		
		Node(int data){
			this->data=data;
			this->next=NULL;
		}
		
		~Node(){
			int value= this->data;
			if(this->next!=NULL){
				delete next;
				this->next = NULL;
			}
		}
		
};

int intersection(Node* &head1,Node* &head2){
	Node *ptrA=head1;
	Node *ptrB=head2;
	
	while(ptrA!=NULL && ptrB!=NULL){
		if(ptrA==ptrB){
			return (ptrA->data);
		}
		else{
		
		ptrA=ptrA->next;
		ptrB=ptrB->next;
		
		if(ptrA->next==NULL){
			ptrA=head2;
		}
		if(ptrB->next==NULL){
			ptrB=head1;
		}
	}
		
	
	} 
}
 

void print(Node* &head1,Node* &head2){
	Node *temp=head1;
	Node *temp2=head2;
	
	while(temp!=NULL){
		cout<<temp->data<<" ";
		temp=temp->next;
	}
	cout<<endl;
	while(temp2!=NULL){
		cout<<temp2->data<<" ";
		temp2=temp2->next;
	}
	
}

int main(){
	Node *node;
	
	Node *head1=new Node(4);
	head1->next=new Node(1);
	
	Node *head2=new Node(5);
	head2->next=new Node(6);
	head2->next->next=new Node(1);
	
	Node *temp= new Node(8);
	head1->next->next=temp;
	head2->next->next->next=temp;
	
	temp->next= new Node(5);
	 print(head1,head2);
	 
	 int output=intersection(head1,head2);
	 cout<<"answer is= "<<output<<" ";
	 return 0;
	
}
