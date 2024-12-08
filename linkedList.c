#include "stdio.h"
#include "stdlib.h"

struct mychain
{
    int num;
    struct mychain* next;
};
void linkedListTraversal(struct mychain* head) {
    while(head != NULL){
        printf("%d\n", head->num);
        head = head->next;
    }
}
struct mychain* insertAtHead(struct mychain* head, int data) {
    struct mychain* newNode = (struct mychain*) malloc(sizeof(struct mychain));
    newNode->num = data;
    newNode->next = head;
    return newNode;
}
struct mychain* insertAtIndex(struct mychain* head, int data, int index) {
    struct mychain* newNode = (struct mychain*) malloc(sizeof(struct mychain));
    struct mychain* ptr = head;
    int chainIndex = 0;
    while(chainIndex != index - 1) {
        ptr = ptr->next;
        chainIndex++;
    }
    newNode->num = data;
    newNode->next = ptr->next;
    ptr->next = newNode;
    return newNode;
}
struct mychain* insertAtEnd(struct mychain* head, int data){
    struct mychain* newNode = (struct mychain*) malloc(sizeof(struct mychain));
    newNode->num = data;
    struct mychain* ptr = head;
    while(ptr->next != NULL) {
        ptr = ptr->next;
    }
    ptr->next = newNode;
    newNode->next = NULL;
    return newNode;
}
struct mychain* insertAfterNode(struct mychain* toPutAfterNode, int num) {
    struct mychain* newNode = (struct mychain*) malloc(sizeof(struct mychain));
    newNode->num = num;
    newNode->next = toPutAfterNode->next;
    toPutAfterNode->next = newNode;
    return newNode
}
int main(int argc, char *argv[]) {
    struct mychain* head = (struct mychain*) malloc(sizeof(struct mychain));
    struct mychain* second = (struct mychain*) malloc(sizeof(struct mychain));
    struct mychain* third = (struct mychain*) malloc(sizeof(struct mychain));
    head->num = 1;
    head->next = second;
    second->num = 2;
    second->next = third;
    third->num = 3;
    third->next = NULL;
    struct mychain* newHead = insertAtHead(head, 56);
    insertAtIndex(newHead, 4, 1);
    insertAtEnd(newHead, 64);
    struct mychain* current = newHead;
    linkedListTraversal(current);
    return 0;
}