#include <stdio.h>
#include <stdlib.h>
typedef struct Node{
    int data;
    struct Node* link;
}Node;
typedef struct Head{
    Node* front;
    Node* rear;
    int count;
}Head;



void enqueue(Head* q,int data){
    Node* newNode = malloc(sizeof(Node));
    newNode->data = data;
    newNode->link = NULL;

    if(q->front == NULL){
        q->front = newNode;
    } else {
        q->rear->link = newNode;
    }

    q->rear = newNode;
    q->count++;
}

int dequeue(Head* q){
    int data = q->front;

    if(q->count == 1){
        q->rear == NULL;
    }
    q->front = q->front->link;
    q->count--;
    return data;
}

int main(){
    Head* q = malloc(sizeof(Head));
    q->front = NULL;
    q->rear = NULL;
    q->count = 0;

    enqueue(q, 5);
    enqueue(q, 3);
    enqueue(q, 10);
    enqueue(q, -1);

    printf("%d\n", dequeue(q)); 
    printf("%d\n", dequeue(q)); 
    printf("%d\n", dequeue(q)); 
    printf("%d\n", dequeue(q)); 
    return 0;
}