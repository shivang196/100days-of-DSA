#include <stdio.h>

#define MAX 100

int stack[MAX];
int top = -1;

void push(int val) {
    if(top == MAX - 1) {
        printf("Stack Overflow\n");
    } else {
        stack[++top] = val;
    }
}

void pop() {
    if(top == -1) {
        printf("Stack Underflow\n");
    } else {
        top--;
    }
}

int main() {
    int n, m, i, val;

    scanf("%d", &n);

    // Push elements
    for(i = 0; i < n; i++) {
        scanf("%d", &val);
        push(val);
    }

    // Number of pops
    scanf("%d", &m);

    for(i = 0; i < m; i++) {
        pop();
    }

    // Display remaining elements (top to bottom)
    for(i = top; i >= 0; i--) {
        printf("%d ", stack[i]);
    }

    return 0;
}