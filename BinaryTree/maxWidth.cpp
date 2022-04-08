#include <iostream>
#include "BinaryTreeNode.h"
using namespace std;

int maxWidth(BinaryTreeNode<int>* root){
	if(root == NULL)
		return 0;
	queue<BinaryTreeNode<int>*> q;
	q.push(root);
    int res= 0;
	while(q.size()!=0){
		int count = q.size();
        res = max(res,count);
		for(int i=0; i<count; i++){
			BinaryTreeNode<int>* front = q.front();
			q.pop();
			if(front->left != NULL)
				q.push(front->left);
			if(front->right != NULL)
				q.push(front->right);
		}
	}
    return res;
}

int main(){
	BinaryTreeNode<int>* root = takeInput2();
	cout << maxWidth(root);
}