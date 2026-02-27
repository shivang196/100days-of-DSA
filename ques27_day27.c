#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

// Function to create a linked list
struct Node* createList(int n) {
    struct Node *head = NULL, *temp = NULL, *newNode = NULL;
    
    for(int i = 0; i < n; i++) {
        int value;
        scanf("%d", &value);
        
        newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->data = value;
        newNode->next = NULL;

        if(head == NULL) {
            head = newNode;
            temp = newNode;
        } else {
            temp->next = newNode;
            temp = newNode;
        }
    }
    return head;
}

// Function to get length
int getLength(struct Node* head) {
    int count = 0;
    while(head != NULL) {
        count++;
        head = head->next;
    }
    return count;
}

// Function to find intersection
struct Node* findIntersection(struct Node* head1, struct Node* head2) {
    int len1 = getLength(head1);
    int len2 = getLength(head2);

    int diff = abs(len1 - len2);

    // Move pointer of longer list
    if(len1 > len2) {
        for(int i = 0; i < diff; i++)
            head1 = head1->next;
    } else {
        for(int i = 0; i < diff; i++)
            head2 = head2->next;
    }

    // Traverse both lists together
    while(head1 != NULL && head2 != NULL) {
        if(head1 == head2)
            return head1;
        head1 = head1->next;
        head2 = head2->next;
    }

    return NULL;
}

int main() {
    int n, m;

    scanf("%d", &n);
    struct Node* head1 = createList(n);

    scanf("%d", &m);
    struct Node* head2 = createList(m);

    // OPTIONAL: Simulate intersection if values match
    struct Node* temp1 = head1;
    struct Node* temp2 = head2;

    while(temp2 != NULL) {
        temp1 = head1;
        while(temp1 != NULL) {
            if(temp1->data == temp2->data) {
                temp2->next = temp1->next;
                break;
            }
            temp1 = temp1->next;
        }
        temp2 = temp2->next;
    }

    struct Node* intersection = findIntersection(head1, head2);

    if(intersection != NULL)
        printf("%d", intersection->data);
    else
        printf("No Intersection");

    return 0;
}