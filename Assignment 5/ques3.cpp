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

void middle(Node* &head){
	
	Node *temp = head;
	int length=0;
	while(temp!=NULL){
		temp = temp->next;
		length ++ ;
	}
	cout<<"the length is "<<length<<"  "<<endl;
	//middle
	int middle;
	middle=(length/2) + 1;
	int n=1;
	Node *ans = head;
	while(n<middle){
		ans = ans->next;
		n++;	
	}
	cout<<"the middle of link list is "<<ans->data<<"  "<<endl;
	
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
	Node* node= new Node(1);
	Node * head = node;
	Node *tail = node;
	insertAtPosition(head,tail,2,2);
		insertAtPosition(head,tail,3,3);
			insertAtPosition(head,tail,4,4);
				insertAtPosition(head,tail,5,5);
					insertAtPosition(head,tail,6,6);
						insertAtPosition(head,tail,7,7);
							insertAtPosition(head,tail,8,8);
						print(head);
						
						middle(head);
	return 0;
}
