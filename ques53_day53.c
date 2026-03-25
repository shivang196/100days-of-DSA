#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *left, *right;
}Node;

Node* createNode(int val){
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = val;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Build tree from level order
Node* buildTree(int arr[], int n){
    if(n==0 || arr[0]==-1) return NULL;

    Node* root = createNode(arr[0]);
    Node* queue[n];
    int front=0, rear=0;

    queue[rear++] = root;
    int i=1;

    while(front<rear && i<n){
        Node* curr = queue[front++];

        if(arr[i] != -1){
            curr->left = createNode(arr[i]);
            queue[rear++] = curr->left;
        }
        i++;

        if(i<n && arr[i] != -1){
            curr->right = createNode(arr[i]);
            queue[rear++] = curr->right;
        }
        i++;
    }
    return root;
}

// Vertical order traversal
void verticalOrder(Node* root){
    if(!root) return;

    // queue for BFS
    Node* q[100];
    int hd[100];

    int front=0, rear=0;

    q[rear] = root;
    hd[rear++] = 0;

    int map[200][100] = {0};
    int size[200] = {0};

    int min=0, max=0;

    while(front<rear){
        Node* curr = q[front];
        int h = hd[front++];
        
        map[h+100][size[h+100]++] = curr->data;

        if(h<min) min=h;
        if(h>max) max=h;

        if(curr->left){
            q[rear] = curr->left;
            hd[rear++] = h-1;
        }

        if(curr->right){
            q[rear] = curr->right;
            hd[rear++] = h+1;
        }
    }

    for(int i=min;i<=max;i++){
        for(int j=0;j<size[i+100];j++){
            printf("%d ", map[i+100][j]);
        }
        printf("\n");
    }
}

int main(){
    int n;
    scanf("%d",&n);

    int arr[n];
    for(int i=0;i<n;i++)
        scanf("%d",&arr[i]);

    Node* root = buildTree(arr,n);

    verticalOrder(root);

    return 0;
}