#include<iostream>
#include<vector>
#include<math.h>
#include<algorithm>
using namespace std;

int sortedArray(int* arr, int size) {

    if(size <= 1) return 1;

    if(arr[size-2] > arr[size-1]) return 0;

    return sortedArray(arr, size-1);

}

int main() {
    int arr[] = {11, 22, 33, 66, 55};

    cout << sortedArray(arr, 5);
    return 0;
}