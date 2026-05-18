#include <stdio.h>
#include <stdlib.h>

typedef struct _node {
    int key;
    struct _node *left;
    struct _node *right;
}Node;

addBST(Node* root, int key){
    if(root ==NULL){
        Node* newNode = malloc(sizeof(Node));
        newNode->key = key;
        newNode->left = newNode ->right = NULL;
        return newNode;
    }
    if (key < root->key){
        root->left = addBST(root->left, key);
    }
    else if (key > root->key){
        root->right = addBST(root->right, key);
    }
    return root;
}

Node* deleteBST(Node* root,int key){
    if(root == NULL) {return NULL;}
    if(key<root->key){
        root->left = deleteBST(root->left,key);
        else if(key>root->key){root->right = deleteBST(root->right,key);
        }
    }
}



int main() {
    Node* root = NULL;
    root =addBST(root ,23);
    root =addBST(root ,18);
    root =addBST(root ,44);
    root =addBST(root ,12);
    root =addBST(root ,20);
    root =addBST(root ,35);
    root =addBST(root ,52);
    






}