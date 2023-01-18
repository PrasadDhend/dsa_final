#include <iostream>
using namespace std;

void selectionSort(int arr[], int n) {
    int i, j, min_idx, temp;
    for (i = 0; i < n-1; i++) {
        min_idx = i;
        for (j = i+1; j < n; j++) {
            if (arr[j] < arr[min_idx]) {
                min_idx = j;
            }
        }
        temp = arr[min_idx];
        arr[min_idx] = arr[i];
        arr[i] = temp;
    }
}

void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n-1; i++) {
        for (int j = 0; j < n-i-1; j++) {
            if (arr[j] > arr[j+1]) {
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}



int main(){
    int arr[] = {5,4,9,2,8,6,1,45,12,54,984,61,654,654,654,6561,65,31687,15,66431,654,358,65151,6,561,651,165,61,615,15,684};
    int n = (sizeof(arr)/4);
    // selectionSort(arr, n);
    bubbleSort(arr, n);

    for (int i = 0; i < n; i++){
        cout << i+1 << ":- " << arr[i] << endl;
    }
    
    
    return 0;
}