#include <stdio.h>


int q[100];
int front;
int rear;

void enqueue(int number){
    q[++rear] = number;

    if(q[front] == -1){
        front++;
    }
}
int  dequeue(){
    int data = q[front];
    front++;

    if(front > rear){
        front = rear = -1;
    }
    return data;
}



int main(){
    for(int i=0; i<100; i++){
        q[i] = 0;
        front = rear = -1;
        enqueue(5);
        enqueue(3);
        enqueue(10);
        enqueue(-1);

        while(front<=rear && front != -1){
            printf("%d\t", dequeue());
            
        }
    }




    return 0;
}