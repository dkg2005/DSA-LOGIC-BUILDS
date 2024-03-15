// INSERTION SORT
#include <iostream>
using namespace std;

void insertionSort(int n, int arr[])
{
    for (int i = 0; i < n; i++)
    {
        int pivot = arr[i];
        int j = i - 1;
        for (j = i - 1; j >= 0; j--)
        {
            if (arr[j] > pivot)
            {
                // shift
                arr[j + 1] = arr[j];
            }
            else
            {
                break;
            }
        }
        arr[j + 1] = pivot;
    }
}

int main()
{
    int n = 7;
    int arr[n] = {10, 1, 7, 4, 8, 2, 11};
    for (int k = 0; k < n; k++)
    {
        cout << arr[k] << endl;
    }
    insertionSort(n, arr);
    cout << "after sorting:" << endl;
    for (int k = 0; k < n; k++)
    {
        cout << arr[k] << endl;
    }
    return 0;
}
