#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node* next;
} node;

void linklisttraverse(struct node* head);
void insertAtFirst(struct node** head, int data);
void insertAtIndex(struct node** head, int data, int index);
void insertAtEnd(struct node** head, int data);
node* deleteAtFirst(node* head);
node* deleteAtIndex(node* head, int index);
node* deleteAtEnd(node* head);

int main() {
    node* head = NULL;
    insertAtFirst(&head, 10);
    insertAtIndex(&head, 20, 1);  // Inserting at index 1
    insertAtIndex(&head, 30, 2);
    insertAtEnd(&head, 40);

    printf("linked list at intial stage\n");
    linklisttraverse(head);

    head = deleteAtFirst(head);
    printf("linked list after delete the 1st node\n");
    linklisttraverse(head);

    head = deleteAtIndex(head, 2); // Deleting at index 2
    printf("linked list after delete the 2nd node\n");
    linklisttraverse(head);

    head = deleteAtEnd(head);
    printf("linked list after delete the last node\n");
    linklisttraverse(head);

    return 0;
}

void linklisttraverse(struct node* head) {
    node* ptr = head;
    while (ptr != NULL) {
        printf("%d\n", ptr->data);
        ptr = ptr->next;
    }
}

void insertAtFirst(struct node** head, int data) {
    struct node* newHead = (struct node*)malloc(sizeof(struct node));
    newHead->data = data;
    newHead->next = *head;
    *head = newHead;
}

void insertAtIndex(node** head, int data, int index) {
    node* newNode = (node*)malloc(sizeof(node));
    newNode->data = data;
    newNode->next = NULL;

    if (index == 0) {
        newNode->next = *head;
        *head = newNode;
        return;
    }

    node* temp = *head;
    int i = 0;
    while (i != index - 1 && temp != NULL) {
        temp = temp->next;
        i++;
    }

    if (temp == NULL) {
        // Index out of bounds, do nothing.
        return;
    }

    newNode->next = temp->next;
    temp->next = newNode;
}

void insertAtEnd(node** head, int data) {
    node* newNode = (node*)malloc(sizeof(node));
    newNode->data = data;
    newNode->next = NULL;

    if (*head == NULL) {
        // If the list is empty, new node becomes the head.
        *head = newNode;
        return;
    }

    node* temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }

    temp->next = newNode;
}

node* deleteAtFirst(node* head) {
    node* p = head;
    head = head->next;
    free(p);
    return head;
}

node* deleteAtIndex(node* head, int index) {
    if (index == 0) {
        node* temp = head;
        head = head->next;
        free(temp);
        return head;
    }

    node* p = head;
    node* q = head->next;
    int i = index - 1;
    while (i--) {
        p = p->next;
        q = q->next;
    }
    p->next = q->next;
    free(q);
    return head;
}

node* deleteAtEnd(node* head) {
    if (head == NULL || head->next == NULL) {
        // If the list is empty or has only one element.
        free(head);
        return NULL;
    }

    node* temp = head;
    node* q = head->next;
    while (q->next != NULL) {
        temp = temp->next;
        q = q->next;
    }
    temp->next = NULL;
    free(q);
    return head;
}
