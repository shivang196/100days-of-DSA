#include <stdio.h>

int main() {
    int n, i, j;
    int isIdentity = 1;

    // Read size of matrix
    scanf("%d", &n);

    int matrix[n][n];

    // Read matrix elements
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }

    // Check identity matrix condition
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            if ((i == j && matrix[i][j] != 1) ||   // diagonal must be 1
                (i != j && matrix[i][j] != 0)) {   // non-diagonal must be 0
                isIdentity = 0;
                break;
            }
        }
        if (!isIdentity)
            break;
    }

    // Output result
    if (isIdentity)
        printf("Identity Matrix");
    else
        printf("Not an Identity Matrix");

    return 0;
}
