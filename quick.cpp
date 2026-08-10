#include <iostream>
using namespace std;

int partition(int arr[], int low, int high)
{
    int pivot = arr[low];
    int i = low;
    int j = high;

    while (i < j)
    {
        // Move j from right to left
        while (i < j && arr[j] >= pivot)
        {
            j--;
        }

        // Put smaller element at position i
        if (i < j)
        {
            arr[i] = arr[j];
            i++;
        }

        // Move i from left to right
        while (i < j && arr[i] <= pivot)
        {
            i++;
        }

        // Put larger element at position j
        if (i < j)
        {
            arr[j] = arr[i];
            j--;
        }
    }

    // Put pivot in its correct position
    arr[i] = pivot;

    return i;
}

void quickSort(int arr[], int low, int high)
{
    if (low < high)
    {
        int p = partition(arr, low, high);

        quickSort(arr, low, p - 1);
        quickSort(arr, p + 1, high);
    }
}

int main()
{
    int arr[] = {5, 8, 3, 7, 2, 6};
    int size = 6;

    quickSort(arr, 0, size - 1);

    cout << "Sorted array: ";

    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}