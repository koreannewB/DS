#include <stdio.h>
#include <stdlib.h>

typedef struct _node{
    int data;
    struct _node* next;
}Node;

typedef stuct _head{
    int count;
    Node* head;
}List;

List* createList(){
    List* list = malloc(sizeof(List));
    list->count = 0;
    list->head = NULL;

    return list;
}

void traverse(List* list){
    Node* pWalker = list->head;

    while(pWalker){
        printf("%d\t", pWalker->data);
        pWalker = pWalker->next;
    }
}

void insert(List* list , int data){
    // 1.찾기
    // 2.노드생성
    // 3.노드연결
    Node *pPre, *pLoc;
    pPre = pLoc = NULL;
    search(list, &pPre, &pLoc, data);


    Node *newNode = malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;

    if(pPre == NULL){
        newNode->next = list->head;
        list->head = newNode;
    } else{
        newNode->next = pPre->next;
        pPre->next = newNode;
    }
    list->count++;
}   
int search(List* list, Node** pPre, Node** pLoc, int target){
    *pPre = NULL;
    *pLoc = list->head;

    while((*pLoc) && (*pLoc)->data < target){
        (*pPre) = (*pLoc);
        (*pLoc) = (*pLoc)->next;   
    }
    if((*pLoc)->data != target) return 0;
    return 1;
}
void del(List* llist , int target){
    Node *pPre, *pLoc;
    pPre = pLoc = NULL;
    int found = search(list, &pPre, &pLoc, target);
    if(found == 0) return;
    if(pPre == NULL){
        list->head = pLoc->next;
    } else{
        pPre->next = pLoc->next;
    }
    free(pLoc);
    
}

void destroy(List* list){
    Node* pWalker = list->head;
    while(pWalker){
        Node *tmp = pWalker;
        
    }
}




int main(){
    List* list = createList(); //numbers are sorted in ascenting order

    insert(list, 10);
    insert(list, 20);
    insert(list, 15);

    traverse(list);

    del(list,15);
    //traverse(list);

    //destroyList(list);
    return 0;
}