#include<iostream>
#include<vector>
#include<math.h>
#include<algorithm>
#include<limits.h>
using namespace std;

void printEvenNos(int* arr, int size) {
    
    if(size <= 0) return;

    if(arr[size-1] % 2 == 0) cout << arr[size-1] << " ";

    printEvenNos(arr, size-1);
}

void printOddNos(int* arr, int size) {
    
    if(size <= 0) return;

    if(arr[size-1] & 1 == 1) cout << arr[size-1] << " ";

    printOddNos(arr, size-1);
}

int maxVal(int* arr, int size, int maxi) {

    if(size <= 0) return maxi;

    if(arr[size-1] > maxi) maxi = arr[size-1];
    
    return maxVal(arr, size-1, maxi);
}

int minVal(int* arr, int size, int mini) {

    if(size <= 0) return mini;

    if(arr[size-1] < mini) mini = arr[size-1];
    
    return minVal(arr, size-1, mini);
}

int searchEle(int* arr, int size, int t) {

    if(size <= 0) return -1;

    if(arr[size-1] == t) return size-1;

    return searchEle(arr, size-1, t);
}

void printArrRev(int* arr, int size, int idx) {

    if(size <= 0) return;

    cout << arr[size-1] << " ";

    printArrRev(arr, size-1, idx);

    // //Base case: 
    // if(idx >= size) return;

    // printArrRev(arr, size, ++idx);
    
    // cout << arr[idx-1] << " ";
    
}

void printArr(int* arr, int size, int idx) {

    //Base case: 
    if(idx >= size) return;

    cout << arr[idx] << " ";

    printArr(arr, size, ++idx);
}

int main() {
    int arr[] = {44, 11, 55, 22, 99};

    int idx = 0;
    cout << "Print Array: ";
    printArr(arr, 5, idx);
    
    cout << endl << "Print Arr Rev: ";
    printArrRev(arr, 5, idx);

    cout << endl << "Element found at: " <<
    searchEle(arr, 5, 111);

    int mini = INT_MAX;
    cout << endl << "Min Val: " <<
    minVal(arr, 5, mini);

    int maxi = INT_MIN;
    cout << endl << "Max Val: " <<
    maxVal(arr, 5, maxi);

    cout << endl;
    printOddNos(arr, 5);

    cout << endl;
    printEvenNos(arr, 5);

    return 0;
}