#include<iostream>
using namespace std;
class Node{
	public:
		int data;
		Node *next;
		//constructor
		 Node(int data){
		 	this -> data = data;
		 	this ->next = NULL;
		 }
		 //destructor
		 ~Node(){
		 int value= this-> data;
		 if(this->next!=NULL){
		 	delete next;
		 	this->next=NULL;
	}
}
	
};

// insertion

void insertAtHead(Node* &head,int d){
	Node *temp= new Node(d);
	temp->next=head;
	head=temp;
}
void insertAtEnd(Node* &head,Node* &tail,int d){
	Node *temp=new Node(d);
	tail->next=temp;
	tail= tail->next;	
}

void insertAtPosition(Node* &head,Node* &tail,int pos,int d){
	if(pos==1){
		insertAtHead(head,d);
		return ;
	}
	
	Node *temp = head;
	
	if(temp->next==NULL){
		insertAtEnd(head,tail,d);
		return ;
	}
	
	int cnt=1;
	while(cnt<pos-1){
		temp=temp->next;
		cnt++;
	}
	Node *nodetoinsert= new Node(d);
	nodetoinsert->next=temp->next;
	temp->next=nodetoinsert;
	
}
// deletion

void deletefromFront(Node* &head){
	Node *temp=head;
	head=temp->next;
	temp->next=NULL;
	delete temp;
}

void deletefromPosition(Node* &head,int pos){
	if(pos==1){
		deletefromFront(head);
		return;
	}
	else{                                // this will handle deletion from end and at any mentioned position
		Node *curr=head;
	Node *prev=NULL;
	int cnt=1;
	while(cnt<pos){
		prev=curr;
		curr=curr->next;
		cnt++;
	}
	prev->next=curr->next;
	curr->next=NULL;
	
	delete curr;

	}
}

//search for a node value and find its position
void searching(Node* &head , int d){
	Node *temp=head;
	int index=1;
	while(temp->data != d){
		index++;
		temp=temp->next;
	}
	 cout<<d<<" "<<"found at "<<index<<" ";
		
}
//print the node values
void print(Node* &head){
	Node *temp= head;
	while(temp!=NULL){
		cout<<temp->data<<" ";
		temp= temp->next;		
	}
	cout<<endl;
}
int main(){
	Node *node= new Node(10);
	Node *head = node;
	Node *tail = node;
	
	insertAtHead(head,5);
	print(head);
	
	insertAtEnd(head,tail,7);
	print(head);
	
	insertAtPosition(head,tail,3,99);
		print(head);
		
		deletefromFront(head);
		print(head);
		
		deletefromPosition(head,3);
		print(head);
		
		searching(head,99);
	return 0;
}
