#include <stdio.h>
#include <stdlib.h>

// Define structure of doubly linked list node
struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
};

int main() {
    int n;
    scanf("%d", &n);

    struct Node *head = NULL, *temp = NULL, *newNode = NULL;

    for(int i = 0; i < n; i++) {
        int value;
        scanf("%d", &value);

        // Allocate memory for new node
        newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->data = value;
        newNode->next = NULL;
        newNode->prev = NULL;

        // If list is empty
        if(head == NULL) {
            head = newNode;
            temp = newNode;
        } else {
            temp->next = newNode;
            newNode->prev = temp;
            temp = newNode;
        }
    }

    // Traverse forward
    temp = head;
    while(temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }

    return 0;
}