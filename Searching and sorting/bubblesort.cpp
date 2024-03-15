#include<iostream>
using namespace std;

int main(){
    int i,j;
    int arr[7]={19,56,76,89,34,40,23};
     for( i=0 ; i<7 ;i++ ){
        for(j=0 ; j<6 ; j++){
            if( arr[j] > arr[j+1] ){
                //swapping
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
}
     cout<<"After sorting:\n"<<endl;
     for( i=0 ; i<7 ;i++){
        cout<<arr[i]<<"\t";
     }
    return 0;
}
/*bubble sort function
void bubbleSort(int arr[], int n)
{
    int i, j;
    bool swapped;
    for (i = 0; i < n - 1; i++) {
        swapped = false;
        for (j = 0; j < n - i - 1; j++) {
        
        //swap adjacent directly
            if (arr[j] > arr[j + 1]) {
                swap(&arr[j], &arr[j + 1]);
                swapped = true;
            }
        }
        if (swapped == false)
            break;
    }
}
*/