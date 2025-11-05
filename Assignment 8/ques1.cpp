#include<iostream>
using namespace std;

class Node{
	public:
	int data;
	Node* left;
	Node* right;
	
	Node(int d){
		this->data=d;
		this->left=NULL;
		this->right=NULL;
	}
};

Node* insert(Node *root,int d){
	if(root==NULL){
		return new Node(d);
	}
	if(d<root->data){
	root->left = insert(root->left, d);
	}
	else if(d>root->data){
	root->right = insert(root->right, d);
	}
	else{
		cout << "Duplicate value " << d << " not allowed!" << endl;
	}
	return root;
}

void inorder(Node* root){
	if(root!=NULL){
		inorder(root->left);
		cout<<root->data<<" ";
		inorder(root->right);
	}
}
void preorder(Node* root){
	if(root!=NULL){
		cout<<root->data<<" ";
		preorder(root->left);
		preorder(root->right);
	}
}
void postorder(Node* root){
	if(root!=NULL){
		postorder(root->left);
		postorder(root->right);
		cout<<root->data<<" ";
	}
}

int main(){
	Node* root = NULL;
	int n, d;

    cout << "Enter number of elements to insert: "<<endl;
    cin >> n;

    for (int i = 0; i < n; i++) {
        cout << "Enter value " << i + 1 << ": ";
        cin >> d;
        root = insert(root,d);
    }
    
    cout<<"inorder traversal"<<endl;
    inorder(root);
    cout<<endl;
     cout<<"preorder traversal"<<endl;
    preorder(root);
    cout<<endl;
     cout<<"postorder traversal"<<endl;
    postorder(root);
    cout<<endl;
    return 0;
}
