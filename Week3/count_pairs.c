#include <stdio.h>
#include <stdlib.h>

long long merge(int arr[], int low, int mid, int high) {
    long long count = 0;
    int j = mid + 1;

    for (int i = low; i <= mid; i++) {
        while (j <= high && (long long)arr[i] > 2LL * arr[j])
            j++;
        count += (j - (mid + 1));
    }

    int n = high - low + 1;
    int *temp = (int *)malloc(n * sizeof(int));

    int left = low, right = mid + 1, k = 0;

    while (left <= mid && right <= high) {
        if (arr[left] <= arr[right])
            temp[k++] = arr[left++];
        else
            temp[k++] = arr[right++];
    }

    while (left <= mid)
        temp[k++] = arr[left++];

    while (right <= high)
        temp[k++] = arr[right++];

    for (int i = 0; i < n; i++)
        arr[low + i] = temp[i];

    free(temp);
    return count;
}

long long mergeSort(int arr[], int low, int high) {
    if (low >= high)
        return 0;

    int mid = low + (high - low) / 2;

    long long count = 0;
    count += mergeSort(arr, low, mid);
    count += mergeSort(arr, mid + 1, high);
    count += merge(arr, low, mid, high);

    return count;
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
