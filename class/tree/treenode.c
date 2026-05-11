#include <stdio.h>

typedef struct _node {
    char data;
    struct _node *left;
    struct _node *right;
}Node;

void preorder(Node * root){
    printf("%c -->", root->data);
    if(root->left != NULL) preorder(root->left);
    if(root->right != NULL) preorder(root->right);
}

Node* q[100];
int front;
int rear;

void enq(Node *newNode){
    q[++rear] = newNode;


if (front == -1) front++;
}

Node* deq(){
    Node* ret = q[front++];

    if(front > rear) front = rear = -1;

    return ret;
}

void bft(Node* root){
    front = rear = -1;
    
    Node* currentNode = root;
    while(currentNode != NULL){
        printf("%c -->",currentNode ->data);
        if(currentNode->left) enq(currentNode->left);
        if(currentNode->right) enq(currentNode->right);
        if(front != -1){
            currentNode = deq();    
        }
        else{
            currentNode = NULL;
        }

    }
}
int main() {
    Node A,B,C,D,E,F;
    A.data = 'A';
    A.left = &B;
    A.right = &E;

    B.data = 'B';
    B.left = &C;
    B.right = &D;

    C.data = 'C';
    C.left = C.right = NULL;

    D.data = 'D';
    D.left = D.right = NULL;

    E.data = 'E';
    E.left = NULL;
    E.right = &F;

    F.data = 'F';
    F.left = F.right = NULL;

    preorder(&A);
}