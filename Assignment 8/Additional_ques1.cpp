//sum of left leaf nodes
#include<iostream>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int d) {
        data = d;
        left = right = NULL;
    }
};

Node* insert(Node* root, int data, bool insertLeft) {
    if (root == NULL)
        return new Node(data);
    if (insertLeft) {
        if (root->left == NULL)
            root->left = new Node(data);
        else
            insert(root->left, data, insertLeft);
    } else {
        if (root->right == NULL)
            root->right = new Node(data);
        else
            insert(root->right, data, insertLeft);
    }

    return root;
}

int getsum(Node* root,bool isleftchild){
		int left_sum,	right_sum;
		if(root==NULL){
		return 0;
	}
	
	if(root->left==NULL&&root->right==NULL){
		return (isleftchild)? root->data : 0;
	}
	if(root->left!=NULL){
	left_sum= getsum(root->left,true);
	}
	if(root->right!=NULL){
	right_sum = getsum(root->right,false);
	}
	
	return left_sum+right_sum;
}


int main(){
	Node* root = new Node(30);
	root = insert(root, 9, true);   // left of root (root is 30) 
root = insert(root, 20, false); 
root->right = insert(root->right, 15, true);  // left of 20
root->right = insert(root->right, 7, false);  // right of 20

    
    int sum = getsum(root,false);// the root node is neither the left node nor the right node so its false.
    cout<<"the sum of left leaf nodes are "<<sum<<" "<<endl;
    return 0;
}

