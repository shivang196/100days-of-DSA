#include <stdio.h>
#define MAX 100

int deque[MAX];
int front = -1, rear = -1;

// Check empty
int empty() {
    return (front == -1);
}

// Check full
int full() {
    return (rear == MAX - 1);
}

// push_front
void push_front(int x) {
    if (front == 0) {
        printf("Overflow\n");
        return;
    }

    if (empty()) {
        front = rear = 0;
    } else {
        front--;
    }

    deque[front] = x;
}

// push_back
void push_back(int x) {
    if (full()) {
        printf("Overflow\n");
        return;
    }

    if (empty()) {
        front = rear = 0;
    } else {
        rear++;
    }

    deque[rear] = x;
}

// pop_front
void pop_front() {
    if (empty()) {
        printf("-1\n");
        return;
    }

    if (front == rear) {
        front = rear = -1;
    } else {
        front++;
    }
}

// pop_back
void pop_back() {
    if (empty()) {
        printf("-1\n");
        return;
    }

    if (front == rear) {
        front = rear = -1;
    } else {
        rear--;
    }
}

// front element
int getFront() {
    if (empty()) return -1;
    return deque[front];
}

// back element
int getBack() {
    if (empty()) return -1;
    return deque[rear];
}

// size
int size() {
    if (empty()) return 0;
    return rear - front + 1;
}

// display
void display() {
    if (empty()) return;

    for (int i = front; i <= rear; i++) {
        printf("%d ", deque[i]);
    }
    printf("\n");
}

int main() {
    int choice, x;

    while (1) {
        scanf("%d", &choice);

        switch (choice) {
            case 1: // push_front
                scanf("%d", &x);
                push_front(x);
                break;

            case 2: // push_back
                scanf("%d", &x);
                push_back(x);
                break;

            case 3: // pop_front
                pop_front();
                break;

            case 4: // pop_back
                pop_back();
                break;

            case 5: // front
                printf("%d\n", getFront());
                break;

            case 6: // back
                printf("%d\n", getBack());
                break;

            case 7: // size
                printf("%d\n", size());
                break;

            case 8: // display
                display();
                break;

            case 9: // exit
                return 0;
        }
    }
}