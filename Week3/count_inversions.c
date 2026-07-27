#include <stdio.h>
#include <stdlib.h>

long long merge(int arr[], int low, int mid, int high) {
    long long inv = 0;

    int n = high - low + 1;
    int *temp = (int *)malloc(n * sizeof(int));

    int i = low, j = mid + 1, k = 0;

    while (i <= mid && j <= high) {
        if (arr[i] <= arr[j]) {
            temp[k++] = arr[i++];
        } else {
            temp[k++] = arr[j++];
            inv += (mid - i + 1);
        }
    }

    while (i <= mid)
        temp[k++] = arr[i++];

    while (j <= high)
        temp[k++] = arr[j++];

    for (i = 0; i < n; i++)
        arr[low + i] = temp[i];

    free(temp);
    return inv;
}

long long mergeSort(int arr[], int low, int high) {
    if (low >= high)
        return 0;

    int mid = low + (high - low) / 2;

    long long inv = 0;
    inv += mergeSort(arr, low, mid);
    inv += mergeSort(arr, mid + 1, high);
    inv += merge(arr, low, mid, high);

    return inv;
}

int main() {
    int n;
    scanf("%d", &n);

    int *arr = (int *)malloc(n * sizeof(int));

    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    printf("%lld\n", mergeSort(arr, 0, n - 1));

    free(arr);
    return 0;
}
