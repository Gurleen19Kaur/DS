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
			int value = this->data;
			if (this->next!=NULL){
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

// occurrences 
void occurrences(Node* &head, int key){ 
int count =0;
if(head==NULL) return;

while(head!=NULL && head->data==key){
	Node *temp=head;
	head=head->next;
	temp->next=NULL;
	count ++;
	delete temp;
}

 Node *curr= head;
 Node *prev=NULL;
 
 while(curr!=NULL){
 
 if(curr->data!= key){
 	prev = curr;
 	curr = curr -> next;
 }
 
 else{
 prev->next = curr -> next;
 curr->next=NULL;
 delete curr;
 curr = prev->next;

 count ++;
 }
 }
 	cout<<"number of occurrences are  "<<count<<"  "<<endl;
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
	Node *node = new Node(1);
	Node *head=node;
	Node *tail=node;
	insertAtPosition(head,tail,1,1);
		insertAtPosition(head,tail,1,2);
			insertAtPosition(head,tail,1,1);
				insertAtPosition(head,tail,1,2);
					insertAtPosition(head,tail,1,1);
						insertAtPosition(head,tail,1,3);
							insertAtPosition(head,tail,1,1);
						print(head);
							
						int key;
						cout<<"enter the key";
						cin>>key;
						
						occurrences(head,key);
	                 	print(head);
		
		return 0;
	
}

