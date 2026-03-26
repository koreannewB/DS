#include <stdio.h>
#include <stdlib.h>


typedef struct Node{
    int data;
    struct Node* link;
}Node;
typedef struct Head{
    int count;
    Node* top;
}Head;



void push(Head* stack, int data){
    Node* newNode = malloc(sizeof(Node));
    newNode->data = data;
    newNode->link = stack->top;

    stack->count++;
    stack->top = newNode;
}

int pop(Head* stack){
    int data = stack->top->data;

    stack->count--;
    stack->top = stack->top->link;
    return data;
}

int main(){
    Head *stack = (Head*)malloc(sizeof(Head));

    stack->count = 0;
    stack->top = NULL;;
    push(stack ,1);
    push(stack ,10);
    push(stack ,3);

    int data;
    while(stack->top){
        data = pop(stack);
        printf("%d\n",data);
    }

    return 0;
}