#include <stdio.h>
#include <stdlib.h>

// Function for qsort comparison
int compare(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

int main() {
    int n;

    // Input size
    scanf("%d", &n);

    int arr[n];

    // Input elements
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Sort array
    qsort(arr, n, sizeof(int), compare);

    int left = 0, right = n - 1;
    int min_sum = arr[left] + arr[right];
    int min_left = left, min_right = right;

    while (left < right) {
        int sum = arr[left] + arr[right];

        // Update closest sum
        if (abs(sum) < abs(min_sum)) {
            min_sum = sum;
            min_left = left;
            min_right = right;
        }

        // Move pointers
        if (sum < 0)
            left++;
        else
            right--;
    }

    // Output result pair
    printf("%d %d\n", arr[min_left], arr[min_right]);

    return 0;
}
