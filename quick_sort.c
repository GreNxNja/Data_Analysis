#include <stdio.h>

// Function to partition the array into two halves
// and return the index of the pivot element
int partition(int arr[], int low, int high)
{
    int pivot = arr[high];
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++)
    {
        if (arr[j] < pivot)
        {
            i++;
            // Swap arr[i] and arr[j]
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }

    // Swap arr[i + 1] and arr[high] (pivot)
    int temp = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = temp;

    return (i + 1);
}

// Function to implement quicksort
void quicksort(int arr[], int low, int high)
{
    if (low < high)
    {
        // Partition the array into two halves and get the pivot index
        int pivotIndex = partition(arr, low, high);

        // Recursively sort the sub-arrays
        quicksort(arr, low, pivotIndex - 1);
        quicksort(arr, pivotIndex + 1, high);
    }
}

int main()
{
    int n;

    // Get the number of elements from the user
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    int arr[n];

    // Get array elements from the user
    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    // Perform quicksort
    quicksort(arr, 0, n - 1);

    // Display the sorted array
    printf("\nSorted array:\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}
