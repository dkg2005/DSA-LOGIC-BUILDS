#include <iostream>
using namespace std;

int main()
{
    int arr[100], n , search ,i;
    cout << "enter the size of array:" << endl;
    cin >> n;
    // input array
    cout << "enter the elemnets of the array:\n"
         << endl;
    for (i = 0; i < n; i++){
        cin>>arr[i];
    }
       // serach element
    cout<<"enter the element you want to search:";
    cin>>search;

    int high,low ;
    low = 0;
    high = n-1 ;
    // binary serach
    while (high>=low){
        int mid =low + (high - low)/2;
        if (arr[mid] == search){
            cout<<"element found at "<< mid+1 <<" location"<<endl;
            break;
        }
        else if (arr[mid]<search){
            low = mid+1;
        }  
        else {
            high =mid-1;
        }
    }
    if (low>high){
        cout<<"search element is not present in given array"<<endl;
    }
        return 0;
}