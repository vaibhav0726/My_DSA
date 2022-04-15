#include <iostream>
#include <queue>
using namespace std;

template<typename T>
class BinaryTreeNode{
public:
	T data;
	BinaryTreeNode* left;
	BinaryTreeNode* right;
	BinaryTreeNode(T data){
		this->data = data;
		this->left=NULL;
		this->right=NULL;
	}
	~BinaryTreeNode(){
		delete left;
		delete right;
	}
};

void printTree(BinaryTreeNode<int>* root){
	if(root==NULL)
		return;

	cout << root->data;
	printTree(root->left);
	printTree(root->right);
}

void printTree2(BinaryTreeNode<int>* root){
	if(root==NULL)
		return;

	cout << root->data << ":";
	if(root->left != NULL){
		cout << " L" <<root->left->data;
	}
	if(root->right != NULL){
		cout << " R" <<root->right->data;
	}
	cout << endl;
	printTree2(root->left);
	printTree2(root->right);
}

// printing tree level wise
// time:- O(n) or 0(n) space:-O(w) or 0(w) where the w (it can goes from 0 to n) is the width of the tree
void printTreeLevelWise(BinaryTreeNode<int>* root){

	queue<BinaryTreeNode<int>*> q;
	q.push(root);
	while(q.size() !=0 ){
		BinaryTreeNode<int>* front = q.front();
		q.pop();
		if(front != NULL)
			cout << front->data << ":";	
		cout << "L:";
		if(front->left != NULL){
			cout << front->left->data << ",";
			q.push(front->left); 
		}
		else{
			cout << "-1" << ",";
		}

		cout << "R:" ;
		if(front->right != NULL){
			cout << front->right->data;
			q.push(front->right);
		}
		else{
			cout <<"-1";
		}
		cout << endl;

	}

	// return root;

}

// taking input recursively
BinaryTreeNode<int>* takeInput(){
	int rootData;
	// cout<<"Enter root data" <<endl;
	cin >> rootData; 
	if(rootData == -1){
		return NULL;
	}

	BinaryTreeNode<int>* root = new BinaryTreeNode<int>(rootData);
	BinaryTreeNode<int>* leftChild = takeInput();
	BinaryTreeNode<int>* rightChild = takeInput();
	root->left = leftChild;
	root->right = rightChild;
	return root;
}

// taking input levelwise
BinaryTreeNode<int>* takeInput2(){
	int rootData;
	// cout<<"Enter root data" <<endl;
	cin >> rootData; 
	if(rootData == -1){
		return NULL;
	}

	BinaryTreeNode<int>* root = new BinaryTreeNode<int>(rootData);
	queue<BinaryTreeNode<int>*> pendingNodes;
	pendingNodes.push(root);

	while(pendingNodes.size() !=0 ){
		BinaryTreeNode<int>* front = pendingNodes.front();
		pendingNodes.pop();
		// cout<< "Enter left child of " << front->data <<endl;
		int leftChildData;
		cin >> leftChildData;
		if(leftChildData != -1){
			BinaryTreeNode<int>* leftChild = new BinaryTreeNode<int>(leftChildData);
			front->left = leftChild;
			pendingNodes.push(leftChild);
		}

		// cout<< "Enter right child of " << front->data <<endl;
		int rightChildData;
		cin >> rightChildData;
		if(rightChildData != -1){
			BinaryTreeNode<int>* rightChild = new BinaryTreeNode<int>(rightChildData);
			front->right = rightChild;
			pendingNodes.push(rightChild);
		}

	}

	return root;

}

// basically the size of the tree
// time:-O(n) space:- O(h) or 0(h)
int numNodes(BinaryTreeNode<int>* root){
	if(root == NULL)
		return 0;

	return 1 + numNodes(root->left) + numNodes(root->right);
}

// time:- O(n) space:-O(h)
int height(BinaryTreeNode<int>* root){
	if(root==NULL)
		return 0;

	return 1+ max(height(root->left), height(root->right));
}

// int main(){
// 	// BinaryTreeNode<int>* root = new BinaryTreeNode<int>(1);
// 	// BinaryTreeNode<int>* left = new BinaryTreeNode<int>(2);
// 	// BinaryTreeNode<int>* right = new BinaryTreeNode<int>(3);
// 	// root->left=left;
// 	// root->right=right;

// 	BinaryTreeNode<int>* root = takeInput2();

// 	// printTree2(root);
// 	// printTreeLevelWise(root);
// 	cout << numNodes(root) << endl;
// 	cout << height(root) << endl;
// 	delete root;
// }
