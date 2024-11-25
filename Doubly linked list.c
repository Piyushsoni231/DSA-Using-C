#include <stdio.h>
#include <stdlib.h>


typedef struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
} Node;


typedef struct DoublyLinkedList {
    Node* front;
    Node* rear;
} DoublyLinkedList;


Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}


DoublyLinkedList* createList() {
    DoublyLinkedList* list = (DoublyLinkedList*)malloc(sizeof(DoublyLinkedList));
    list->front = NULL;
    list->rear = NULL;
    return list;
}


void insertFront(DoublyLinkedList* list, int data) {
    Node* newNode = createNode(data);
    if (list->front == NULL) { 
        list->front = list->rear = newNode;
    } else {
        newNode->next = list->front;
        list->front->prev = newNode;
        list->front = newNode;
    }
    printf("Inserted %d at the front.\n", data);
}


void insertEnd(DoublyLinkedList* list, int data) {
    Node* newNode = createNode(data);
    if (list->rear == NULL) { 
        list->front = list->rear = newNode;
    } else {
        newNode->prev = list->rear;
        list->rear->next = newNode;
        list->rear = newNode;
    }
    printf("Inserted %d at the end.\n", data);
}


void deleteFront(DoublyLinkedList* list) {
    if (list->front == NULL) { 
        printf("Error: Cannot delete from an empty list.\n");
        return;
    }
    Node* temp = list->front;
    int data = temp->data;
    if (list->front == list->rear) { 
        list->front = list->rear = NULL;
    } else {
        list->front = list->front->next;
        list->front->prev = NULL;
    }
    free(temp);
    printf("Deleted %d from the front.\n", data);
}


void deleteEnd(DoublyLinkedList* list) {
    if (list->rear == NULL) { 
        printf("Error: Cannot delete from an empty list.\n");
        return;
    }
    Node* temp = list->rear;
    int data = temp->data;
    if (list->front == list->rear) { 
        list->front = list->rear = NULL;
    } else {
        list->rear = list->rear->prev;
        list->rear->next = NULL;
    }
    free(temp);
    printf("Deleted %d from the end.\n", data);
}


void search(DoublyLinkedList* list, int key) {
    Node* current = list->front;
    int position = 0;
    while (current) {
        if (current->data == key) {
            printf("Element %d found at position %d.\n", key, position);
            return;
        }
        current = current->next;
        position++;
    }
    printf("Element %d not found.\n", key);
}


void displayForward(DoublyLinkedList* list) {
    if (list->front == NULL) {
        printf("List is empty.\n");
        return;
    }
    Node* current = list->front;
    printf("List in forward direction: ");
    while (current) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}


void displayReverse(DoublyLinkedList* list) {
    if (list->rear == NULL) {
        printf("List is empty.\n");
        return;
    }
    Node* current = list->rear;
    printf("List in reverse direction: ");
    while (current) {
        printf("%d ", current->data);
        current = current->prev;
    }
    printf("\n");
}


int main() {
    DoublyLinkedList* list = createList();

    insertFront(list, 10);
    insertFront(list, 20);
    insertEnd(list, 30);
    insertEnd(list, 40);
    displayForward(list);
    displayReverse(list);

    deleteFront(list);
    displayForward(list);
    deleteEnd(list);
    displayForward(list);

    search(list, 10);
    search(list, 50);

    return 0;
}
