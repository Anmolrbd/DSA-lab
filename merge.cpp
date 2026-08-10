#include <iostream>
using namespace std;

void display(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
}

void merge(int arr[], int l, int m, int r)
{
    int i = l;
    int j = m + 1;
    int k = 0;

    int size = r - l + 1;
    int temp[size];

    while (i <= m && j <= r)
    {
        if (arr[i] < arr[j])
        {
            temp[k] = arr[i];
            i++;
        }
        else
        {
            temp[k] = arr[j];
            j++;
        }
        k++;
    }

    while (i <= m)
    {
        temp[k] = arr[i];
        i++;
        k++;
    }

    while (j <= r)
    {
        temp[k] = arr[j];
        j++;
        k++;
    }

    for (int i = 0; i < size; i++)
    {
        arr[l + i] = temp[i];
    }
}

void mergeSort(int arr[], int l, int r)
{
    if (r > l)
    {
        int m = (l + r) / 2;

        mergeSort(arr, l, m);

        mergeSort(arr, m + 1, r);

        merge(arr, l, m, r);
    }
}

int main()
{
    int arr[] = {2, 6, 11, 4, 5, 7};
    int size = 6;

    mergeSort(arr, 0, size - 1);

    cout << "Sorted array: ";
    display(arr, size);

    return 0;
}