#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct {
    int val;
    struct node *next;
} node;


void push(node *head, int val);
void printNodes(node *head);


void push(node *head, int val) {

    node *curr = head;

    if (curr->val == NULL && curr->next == NULL) {
        curr->val = val;
        return;
    }

    node *new_node = (node*) malloc(sizeof(node));

    if (new_node == NULL) {
        printf("Can't create a second node.\n");
        return;
    }

    new_node->val = val;
    new_node->next = NULL;

    if (head->next == NULL) {
        head->next = new_node;
        return;
    }


    while (curr->next != NULL) {
        curr = curr->next;
    }

    curr->next = new_node;
}

void printNodes(node *head) {
    node *curr = head;
    int i = 0;

    while (curr->next != NULL) {
        printf("{id: %d, val: %d}\n", i, curr->val);
        curr = curr->next;
        i++;
    }
}


int main() {

    srand(time(NULL));

    int total_values = 20;

    node *head = (node*) malloc(sizeof(node));

    if (head == NULL) {
        printf("Could not create initial node.");
        return 1;
    }

    head->val = NULL;
    head->next = NULL;

    for (int i = 0; i < total_values; i++) {
        push(head, rand());
    }

    printNodes(head);


    return 0;
}

