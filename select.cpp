
#include<iostream>
#include<conio.h>
using namespace std;

void selectionsort(int arr[], int size)
{
    for(int i = 0; i < size - 1; i++)
    {
        int min = i;

        for(int j = i + 1; j < size; j++)
        {
            if(arr[j] < arr[min])
            {
                min = j;
            }
        }

        int temp = arr[i];
        arr[i] = arr[min];
        arr[min] = temp;
    }
}

void display(int arr[], int size)
{
    for(int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
}

int main()
{
    int arr[] = {64, 25, 12, 22, 11};
    int size = 5;

    selectionsort(arr, size);

    cout << "Sorted array: ";
    display(arr, size);

    return 0;
}

