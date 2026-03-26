#include <stdio.h>
#include <stdlib.h>
int stack[100];
int top = -1; //empty stack

void push(int data){
    stack[++top] = data;

}

int pop(){
    return stack[top--];
}





int main(){
    for (int i=0; i<100; i++) {stack[i] = 0;}
    

    push(1);
    push(10);
    push(3);
    
    while(top >= 0){
        data = pop();
        printf("%d\n",data);
    }
    return 0;

    }