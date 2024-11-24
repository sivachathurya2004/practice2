#include <stdio.h>
#include <stdlib.h>

// Merge function to combine two sorted halves
void merge(int arr[], int start, int mid, int end) {
    int n1 = mid - start + 1;
    int n2 = end - mid;

    // Create temporary arrays
    int left[n1], right[n2];
    int i;
    for (int i = 0; i < n1; i++)
        left[i] = arr[start + i];
    for (int j = 0; j < n2; j++)
        right[j] = arr[mid + 1 + j];

    int i = 0, j = 0, k = start;
    while (i < n1 && j < n2) {
        if (left[i] <= right[j]) {
            arr[k] = left[i];
            i++;
        } else {
            arr[k] = right[j];
            j++;
        }
        k++;
    }

    // Copy remaining elements of left[], if any
    while (i < n1) {
        arr[k] = left[i];
        i++;
        k++;
    }

    // Copy remaining elements of right[], if any
    while (j < n2) {
        arr[k] = right[j];
        j++;
        k++;
    }
}

// Merge Sort function
void mergeSort(int arr[], int start, int end) {
    if (start < end) {
        int mid = start + (end - start) / 2;

        // Recursively sort first and second halves
        mergeSort(arr, start, mid);
        mergeSort(arr, mid + 1, end);

        // Merge the sorted halves
        merge(arr, start, mid, end);
    }
}

// Function to find the two repeating numbers
void findRepeatingNumbers(int arr[], int n) {
    // Sort the array using Merge Sort
    mergeSort(arr, 0, n - 1);

    int first = -1, second = -1;

    // Find the repeating elements in sorted array
    for (int i = 1; i < n; i++) {
        if (arr[i] == arr[i - 1]) {
            if (first == -1) {
                first = arr[i];
            } else if (second == -1 && arr[i] != first) {
                second = arr[i];
            }
        }
    }

    // Print the two repeating numbers in sorted order
    if (first > second) {
        int temp = first;
        first = second;
        second = temp;
    }
    printf("%d %d\n", first, second);
}

int main() {
    int T;
    printf("Enter number of test cases: ");
    scanf("%d", &T);

    while (T--) {
        int N;
        printf("\nEnter the size of the array: ");
        scanf("%d", &N);

        int arr[N];
        printf("Enter %d elements of the array: ", N);
        for (int i = 0; i < N; i++) {
            scanf("%d", &arr[i]);
        }

        // Find and print the two repeating numbers
        findRepeatingNumbers(arr, N);
    }

    return 0;
}
