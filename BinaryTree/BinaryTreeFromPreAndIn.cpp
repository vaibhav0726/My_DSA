#include <iostream>
#include "BinaryTreeNode.h"
using namespace std;

// we can create the binary tree using two given combinations:-
// (1) Inorder and postorder traversal or (2) Inorder and preorder traversal
// can't make a binary tree using postorder and preorder traversal

int preIndex = 0;
BinaryTreeNode<int>* cTree(int pre[], int in[], int is, int ie){
    if(is > ie)
        return NULL;
    
    BinaryTreeNode<int>* root = new BinaryTreeNode(pre[preIndex++]);

    int inIndex;
    for(int i=is; i<=ie; i++){
        if(in[i] == root->key){
            inIndex = i;
            break;
        }
    }

    root->left  = cTree(pre, in, is, index-1);
    root -> right = cTree(pre, in, index+1, ie);
    return root;
}

int main(){
    BinaryTreeNode<int>* root = takeinput2();
    printTreeLevelWise(root);
}