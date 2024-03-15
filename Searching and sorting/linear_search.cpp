#include <iostream>
using namespace std;

bool search(int arr[], int key)
{
    for (int i = 0; i < 10; i++)
    {
        if (arr[i] == key)
        {
            return 1;
        }
    }
    return 0;
}
int main()
{
    int arr[10] = {2, 5, 9, -34, -5, 0, 3, 6, 7, 13};
    int key;
    cout << "Enter the element which you want to search: ";
    cin >> key;

    bool found = search(arr, key);

    if (found)
    {
        cout << "key is Present" << endl;
    }
    else
    {
        cout << "Key is Absent" << endl;
    }
    return 0;
}