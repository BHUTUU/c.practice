#include "stdio.h"
#include "stdlib.h"

struct mychain
{
    int num;
    struct mychain* next;
};

void linkedListTraversal(struct mychain* head) {
    printf("[ ");
    while(head != NULL){
        printf("%d ", head->num);
        head = head->next;
    }
    printf("]\n");
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
    return head;
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
    return head;
}
struct mychain* insertAfterNode(struct mychain* toPutAfterNode, int num) {
    struct mychain* newNode = (struct mychain*) malloc(sizeof(struct mychain));
    newNode->num = num;
    newNode->next = toPutAfterNode->next;
    toPutAfterNode->next = newNode;
    return newNode;
}
struct mychain* deleteHead(struct mychain* head) {
    struct mychain* temp = head->next;
    free(head);
    return temp;
}
struct mychain* deleteAtIndex(struct mychain* head, int index) {
    // struct mychain* temp = head;
    // int chainIndex = 0;
    // while(chainIndex!= index - 1) {
    //     if(temp->next !=NULL) {
    //         temp = temp->next;
    //         chainIndex++;
    //     } else {
    //         printf("Index out of range\n");
    //         return head;
    //     }
    // }
    // struct mychain* toDeleteNode=temp->next;
    // temp->next = toDeleteNode->next;
    // free(toDeleteNode);
    // return head;

    //for more clarity it can be also done as follow:

    struct mychain* p = head;
    struct mychain* q = p->next;
    for(int i=0; i<index-1; i++) {
        if (q != NULL && q->next !=NULL) {
            p=p->next;
            q=q->next;
        } else {
            printf("Index out of range\n");
            return head;
        }
    }
    p->next = q->next;
    free(q);
    return head;
}
struct mychain* deleteLastNode(struct mychain* head) {
    struct mychain* p = head;
    struct mychain* q = p->next;
    while(q->next!=NULL) {
        p=p->next;
        q=q->next;
    }
    free(q);
    p->next = NULL;
    return head;
}
struct mychain* deleteNodeWithNum(struct mychain* head, int numValue) {
    struct mychain* p=head;
    struct mychain* q=p->next;
    if(p->num==numValue) {
        head = q;
        free(p);
        return head;
    }
    while(q->num!=numValue && q->next!=NULL) {
        p=p->next;
        q=q->next;
    }
    if(q->num==numValue) {
        p->next = q->next;
        free(q);
    }
    return head;
}
int main() {
    struct mychain* head = (struct mychain*) malloc(sizeof(struct mychain));
    struct mychain* second = (struct mychain*) malloc(sizeof(struct mychain));
    struct mychain* third = (struct mychain*) malloc(sizeof(struct mychain));
    head->num = 1;
    head->next = second;
    second->num = 2;
    second->next = third;
    third->num = 3;
    third->next = NULL;
    head = insertAtHead(head, 56);
    printf("new head is %d\n", head->num);
    head=insertAtIndex(head, 4, 1);
    head=insertAtEnd(head, 64);
    struct mychain* current = head;
    printf("Printing chain elements before delete operation of head\n");
    linkedListTraversal(current);
    printf("Printing chain elements after delete operation of head\n");
    head=deleteHead(current);
    linkedListTraversal(head);
    printf("Printing chain elements after delete at index 2\n");
    head=deleteAtIndex(head, 2);
    linkedListTraversal(head);
    printf("printing chain elements after deleting end element\n");
    head=deleteLastNode(head);
    linkedListTraversal(head);
    printf("Printing chain elements after deleting node with num=1\n");
    head=deleteNodeWithNum(head, 1);
    linkedListTraversal(head);
    return 0;
}