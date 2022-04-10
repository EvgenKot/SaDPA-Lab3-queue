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


typedef struct Queue 
{
    Node *head;
    Node *tail;

    size_t size;
} Queue;


void pushBack(Queue* q, int data) {
    q -> size ++;
    Node *newNode = (Node*) malloc(sizeof(Node));
    newNode->value = data;
    newNode->next = NULL;

    if (q->head == NULL) q->head = newNode;
    else q->tail->next = newNode;
    q->tail = newNode;
}


int pop(Queue* q) {
    q -> size --;
    Node* prev = NULL;
    int val;
    if (q->head == NULL) {
        exit(-1);
    }
    prev = q->head;
    val = prev->value;
    q->head = q->head->next;
    free(prev);
    return val;
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
    Queue q1;
    q1.head = NULL;
    q1.tail = q1.head;
    q1.size = 0;

    Queue q2;
    q2.head = NULL;
    q2.tail = q2.head;
    q2.size = 0;

    //Заполнение 1 очереди
    pushBack(&q1, 28);
    pushBack(&q1, 20);
    pushBack(&q1, -5);
    pushBack(&q1, 0);
    pushBack(&q1, 11);
    pushBack(&q1, -4);
    pushBack(&q1, -1);
    pushBack(&q1, 24);
    pushBack(&q1, -28);
    printf("[%d] size of queue \n ", q1.size);

    printQueue(q1.head);

    int data;
    int n = 0;
    int p = 0;

    int nmax = 0;
    int pmin = 0;

    //Поиск номеров нужных элементов и перемещение всех элементов во 2 очередь
    while (q1.head != NULL){ 
        data = pop(&q1);
        if (data > 0)
        {
           if (data < pmin){  
                pmin = data;
                p = 0;
                printf("   %d new positive min \n ", pmin);
            }
            else if (pmin == 0){
                pmin = data;
                p = 0;
                printf("%d first positive min \n ", pmin);
            }
        }
        else if (data < 0){
            if (data > nmax){  
                nmax = data;
                n = 0;
                printf("   %d new negative max \n ", nmax);
            }
            else if (nmax == 0){
                nmax = data;
                n = 0;
                printf("%d first negative max \n ", nmax);
            }
        }
        n++;
        p++;

        pushBack(&q2, data);      
    }

    printf("%d positive min on -%d position \n %d negative max on -%d position\n", pmin, p, nmax, n);
    printQueue(q2.head);

    p--;
    n--;

    //Перемещение всех элементов из 2 очереди обратно в 1 с заменой нужных элемнтов
    while (q2.head != NULL){
        data = pop(&q2);
        if (q2.size == n){
            pushBack(&q1, pmin);
        }
        else if (q2.size == p){
            pushBack(&q1, nmax);
        }
        else{
            pushBack(&q1, data);
        }     
    }
    printQueue(q1.head);

}
