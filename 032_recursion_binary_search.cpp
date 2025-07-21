#include<iostream>
#include<vector>
#include<math.h>
#include<algorithm>
using namespace std;

int binarySearch(int* arr, int size, int t, int s, int e) {

    if(s > e) return -1;

    int mid = (s+e)/2;
    if(arr[mid] == t) return mid;

    else if(arr[mid] < t) return(arr, size, t, mid+1, e);
    else return(arr, size, t, s, mid-1);
}

int main() {
    int arr[] = {11, 22, 33, 44, 55};

    cout << "Element Found at index: " << 
    binarySearch(arr, 5, 11, 0, 4);

    return 0;
}