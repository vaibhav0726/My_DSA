#include <iostream>
#include <queue>
#include <stack>
#include "BinaryTreeNode.h"
using namespace std;

// method:-1
// time:- O(n)
void spiralForm(BinaryTreeNode<int>* root){

	queue<BinaryTreeNode<int>*> q;
	q.push(root);
	bool reverse = false;
	stack<int> s;

	while(q.size() != 0){
		int count = q.size();
		for(int i=0; i<count; i++){
			BinaryTreeNode<int>* front = q.front();
			q.pop();
			if(reverse)
				s.push(front -> data);
			else
				cout << front -> data << ",";
			if(front -> left != NULL)
				q.push(front -> left);
			if(front -> right != NULL)
				q.push(front -> right);
		}
		if(reverse){
			while(s.empty() == false){
				cout << s.top() << ",";
				s.pop();
			}
		}
		reverse = !reverse;
		cout << endl;
		
	}
}

// method:-2 efficient (using only one stack)
// time:- O(n)
void spiralForm2(BinaryTreeNode<int>* root){
	stack<BinaryTreeNode<int>*> s1;
	stack<BinaryTreeNode<int>*> s2;
	s1.push(root);
	while(s1.size() != 0 || s2.size() != 0){
		while(s1.size() != 0){
			BinaryTreeNode<int> * top = s1.top();
			cout << top ->data << ",";
			s1.pop();
			if(top -> left != NULL)
				s2.push(top -> left);
			if(top -> right != NULL)
				s2.push(top -> right);
		}
		cout << endl;
		while(s2.size() != 0){
			BinaryTreeNode<int> * top = s2.top();
			cout << top -> data << ",";
			s2.pop();
			if(top -> right != NULL)
				s1.push(top -> right);
			if(top -> left != NULL)
				s1.push(top -> left);
		}
		cout << endl;
	}
}

int main(){
	BinaryTreeNode<int>* root = takeInput2();
	spiralForm(root);
	cout << endl;
	spiralForm2(root);
}