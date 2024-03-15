#include<iostream>
using namespace std;

int binarysearch(int arr[], int size, int key) {

    int start = 0;
    int end = size - 1;

    while (start <= end) {
        int mid = (end + start) / 2;  // Calculate mid within the loop

        if (arr[mid] == key) {
            return mid;
        }
       if (key > arr[mid]) {
            start = mid + 1;
        }
        else {
            end = mid - 1;
        }
    }
    return -1;
}

int main() {

    int even[6] = {1, 5, 8, 15, 43, 56};
    int odd[5] = {3, 5, 7, 8, 16};

    int index1 = binarysearch(odd, 5, 16);
    int index2 = binarysearch(even, 6, 15);
    cout << index1 << endl;
    cout << index2 << endl;

    return 0;
}
