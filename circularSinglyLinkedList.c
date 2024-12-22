#include "stdio.h"
#include "stdlib.h"

struct myChain {
    int num;
    struct myChain* next;
};
void circularChainTraverse(struct myChain* chainHead) {
    struct myChain* p=chainHead;
    do {
        printf("Element: %d\n", p->num);
        p=p->next;
    } while (p != chainHead);
}
int main() {
    printf("This program is to demonstrate the basic functionality of a cirlcularSinglyLinkedList\n");
    struct myChain* firstNode = (struct myChain*) malloc(sizeof(struct myChain));
    struct myChain* secondNode = (struct myChain*) malloc(sizeof(struct myChain));
    struct myChain* thirdNode = (struct myChain*) malloc(sizeof(struct myChain));
    struct myChain* fourthNode = (struct myChain*) malloc(sizeof(struct myChain));
    firstNode->num = 1;
    secondNode->num = 2;
    thirdNode->num = 3;
    fourthNode->num = 4;
    firstNode->next = secondNode;
    secondNode->next = thirdNode;
    thirdNode->next = fourthNode;
    fourthNode->next = firstNode; // Making the fourth node point to the first node, forming a circular linked list.
    circularChainTraverse(firstNode);
    
}