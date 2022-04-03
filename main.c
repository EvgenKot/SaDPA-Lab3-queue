#include <stdio.h>
#include <stdlib.h>




/*
Ращупкин Евгений КЭ-203
28 вариант
Очередь
Поменять местами наибольшее среди отрицательных
и наименьшее среди положительных элементов целочисленной очереди.
*/


typedef struct Node {
    int value;
    struct Node *next;
} Node;


void push(Node **head, int data) {
    Node *tmp = (Node*) malloc(sizeof(Node));
    tmp->value = data;
    tmp->next = (*head);
    (*head) = tmp;
}



void pushBack(Node *head, Node *tail, int data) {
    Node *newNode = (Node*) malloc(sizeof(Node));
    newNode->value = data;
    newNode->next = NULL;
    if (head == NULL) head = newNode;
    else tail->next = newNode;

    tail = newNode;
}

int pop(Node **head) {
    Node* prev = NULL;
    int val;
    if (head == NULL) {
        exit(-1);
    }
    prev = (*head);
    val = prev->value;
    (*head) = (*head)->next;
    free(prev);
    return val;
}


void fromArrayBack(Node **head, Node **tail, int *arr, size_t size) {
    int i = size;
    while (i != -1) {
        pushBack(*head, *tail, arr[i]);
        i--;
    }

}

void printQueue(Node* head) {

    while (head) {
        printf("%d ", head->value);
        head = head->next;
    }
    printf(" < Queue");
    printf("\n");
}





void main() {
    Node* head = NULL;
    Node* tail = head;

    push(&head, 5);
    push(&head, 6);
    pushBack(head, tail, 28);
    //pushBack(head, tail, 20);
    //pushBack(head, tail, 0);
    //pushBack(head, tail, -1);
    //int arr[] = {10, 1, 10,-3,4,5,-6,7,8,0,15};
    //fromArrayBack(&head, arr, 11);


    printQueue(head);
}
