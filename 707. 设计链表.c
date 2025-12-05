#include<stdio.h>
#include<stdlib.h>

struct ListNode {
    struct ListNode* next; 
    int val; 
}; 

typedef struct {
    int size; 
    struct ListNode* head; 
} MyLinkedList;
 

struct ListNode* creatNode(int val) {
    struct ListNode* node = (struct ListNode*)malloc(sizeof(struct ListNode)); 
    node->next = NULL; 
    node->val = val; 
    return node; 
}

MyLinkedList* myLinkedListCreate() {
    MyLinkedList* node = (MyLinkedList*)malloc(sizeof(MyLinkedList)); 
    node->head = NULL; 
    node->size = 0;  
    return node; 
}

int myLinkedListGet(MyLinkedList* obj, int index) {
    if (index < 0 || index >= obj->size) {
        return -1; 
    }  
    struct ListNode* curr = obj->head; 
    for (int i = 0; i < index; i++) {
        curr = curr->next; 
    } 
    return curr->val; 
}

void myLinkedListAddAtHead(MyLinkedList* obj, int val) {
    struct ListNode* head = obj->head; 
    struct ListNode* node = (struct ListNode*)malloc(sizeof(struct ListNode)); 
    node->val = val; 
    node->next = head; 
    obj->head = node;  
    obj->size++; 
}

void myLinkedListAddAtTail(MyLinkedList* obj, int val) { 
    struct ListNode* node = (struct ListNode*)malloc(sizeof(struct ListNode)); 
    node->val = val; 
    node->next = NULL; 
    if (obj->head == NULL) {
        obj->head = node; 
    } else {
        struct ListNode* head = obj->head; 

        while (head->next != NULL) {
        head = head->next; 
    } 
    head->next = node; 
    }
 
    obj->size++; 
}

void myLinkedListAddAtIndex(MyLinkedList* obj, int index, int val) {
    if (index < 0 || index > obj->size) {
        return; 
    } 
    struct ListNode* node = (struct ListNode*)malloc(sizeof(struct ListNode)); 
    node->val = val;  
    struct ListNode* curr = obj->head;  
    if (index == 0) {
        myLinkedListAddAtHead(obj, val); 
        return; 
    }
    for (int i = 0; i < index - 1; i++) {
        curr = curr->next; 
    } 
    node->next = curr->next; 
    curr->next = node;  
    obj->size++; 
}

void myLinkedListDeleteAtIndex(MyLinkedList* obj, int index) {
    if (index < 0 || index >= obj->size) {
        return; 
    }  
    if (obj->head == NULL) {
        return; 
    } 
    if (index == 0) { 
        free(obj->head); 
        obj->head = obj->head->next; 
        return; 
    }
    struct ListNode* curr = obj->head; 
    for (int i = 0; i < index - 1; i++) {
        curr = curr->next; 
    } 
    struct ListNode* temp = curr->next; 
    curr->next = temp->next; 
    free(temp); 
    obj->size--; 
}

void myLinkedListFree(MyLinkedList* obj) {
    struct ListNode* temp = obj->head; 
    struct ListNode* curr = temp->next; 
    while (curr != NULL) {
        free(temp); 
        temp = curr; 
        curr = curr->next; 
    } 
    free(temp); 
    free(obj); 
} 