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
Node* minimum(Node* root) {
    if (root == NULL) return NULL;
    
    while (root->left != NULL) {
        root = root->left;
    }
    return root;
}

Node* inorderSuccessor(Node* root, Node* target) {
    if (target->right != NULL) {
        return minimum(target->right);
    }
    Node* successor = NULL;
    Node* ancestor = root;

    while (ancestor != target) {
        if (target->data < ancestor->data) {
            successor = ancestor; 
            ancestor = ancestor->left;
        } else {
            ancestor = ancestor->right;
        }
    }
    return successor;
}

Node* search(Node* root, int key) {
    if (root == NULL || root->data == key)
        return root;
    if (key < root->data)
        return search(root->left, key);
    else
        return search(root->right, key);
}

int main(){
	Node* root = NULL;
	int n, d,key;

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
    
   Node* minNode = minimum(root);
    if (minNode != NULL)
        cout << "The minimum value in the BST is: " << minNode->data << endl;
    else
        cout << "The tree is empty!" << endl;
        
    cout << "\nEnter the node value to find its in-order successor: ";
    cin >> key;
        
        Node* target = search(root, key);
    if (target == NULL) {
        cout << "Node not found in the BST." << endl;
    } else {
        Node* succ = inorderSuccessor(root, target);
        if (succ)
            cout << "In-order successor of " << key << " is: " << succ->data << endl;
        else
            cout << "In-order successor of " << key << " does not exist." << endl;
    }
    
  
    return 0;
}
