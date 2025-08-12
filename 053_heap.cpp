#include<iostream>
#include<vector>
#include<math.h>
#include<algorithm>
using namespace std;

class Heap {
    public:
        int *arr;
        int size;
        int index;

    Heap(int capacity) {
        size = capacity;
        arr = new int[size];
        index = 0;
    }

    void printHeap() {
        for(int i=0; i<size; i++) {
            if(i == 0) {
                cout << 'X' << " ";
            } else {
                cout << arr[i] << " ";
            }
        }
        cout << endl;
    }

    void insert(int value) {
        //overlfow
        if(index == size-1) {
            cout << "Overflow" << endl;
            return;
        }
        // insert
        index++; //we use 1 base indexing
        arr[index] = value;
        // position correction
        int childIndex = index;
        while(childIndex > 1) {
            int parentIndex = childIndex/2;
            //when child > parent
            if(arr[childIndex] > arr[parentIndex]) {
                swap(arr[childIndex], arr[parentIndex]);
                //log bhul jate h
                childIndex = parentIndex;
            } else {
                //parent > child
                break;
            }
        }
    }

    void deleteFromHeap() {
        swap(arr[1], arr[index]);
        index--;
        //correct position -> 1 index - new element
        int capacity = index;
        heapify(arr, capacity, 1); //1 index par value h usko heapify krna h
    }
    void heapify(int *arr, int capacity, int currIndex) {
        int i = currIndex; 
        int leftChild = 2*i;
        int rightChild = 2*i + 1;
        //now target is to find largest index
        int largestIndex = i;

        //check for leftIndex
        if(leftChild < capacity && arr[leftChild] > arr[largestIndex]) {
            largestIndex = leftChild;
        }
        //check for rightIndex
        if(rightChild < capacity && arr[rightChild] > arr[largestIndex]) {
            largestIndex = rightChild;
        }

        //yaha tk agae - largest index 3ino mese sabse badi value pr hoga

        //agar current ele hi largest h, to kuch krne ki need hi nahi h
        //agar current element largest nahi h toh operations perform karo
        if(largestIndex != i) {
            //current element is not largest - left ya right mese kuch large h
            swap(arr[i], arr[largestIndex]);
            i = largestIndex;

            //ek mese solve kr diya
            //baki recursion
            heapify(arr, capacity, i);
        }
    }

    void buildHeap(int *arr, int n) {
        for(int i=n/2; i>=1; i--) {
            heapify(arr, n, i);
        }
    }
};

void heapify(int *arr, int capacity, int currIndex) {
        int i = currIndex;
        cout << "Working on digit: " << arr[i] << endl;
        int leftChild = 2*i;
        int rightChild = 2*i + 1;
        //now target is to find largest index
        int largestIndex = i;

        //check for leftIndex
        //<= as 5 ke equal bhi chalega
        if(leftChild <= capacity && arr[leftChild] > arr[largestIndex]) {
            largestIndex = leftChild;
        }
        //check for rightIndex
        if(rightChild <= capacity && arr[rightChild] > arr[largestIndex]) {
            largestIndex = rightChild;
        }

        //yaha tk agae - largest index 3ino mese sabse badi value pr hoga

        //agar current ele hi largest h, to kuch krne ki need hi nahi h
        //agar current element largest nahi h toh operations perform karo
        if(largestIndex != i) {
            //current element is not largest - left ya right mese kuch large h
            swap(arr[i], arr[largestIndex]);
            i = largestIndex;

            //ek mese solve kr diya
            //baki recursion
            heapify(arr, capacity, i);
        }
    }

    void buildHeap(int *arr, int n) {
        for(int i=n/2; i>=1; i--) {
            heapify(arr, n, i);
        }
    }

    void heapSort(int *arr, int n) {
        while(n > 1) {
            swap(arr[1], arr[n]);
            n--;
            heapify(arr, n, 1);
        }
    }

int main() {
    // int arr[] = {-1, 1, 50, 30, 40, 35, 25, 100};
    int arr[] = {-1, 1, 8, 6, 3, 4, 2, 5};
    int size = 7;
    heapify(arr, size, 1);
    cout << "Printing Array: " << endl;
    for(int i=0; i<=size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    heapSort(arr, size);
    cout << "Printing array after heap sort call: " << endl;
    for(int i=0; i<=size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    // Heap pq(1000);
    // pq.buildHeap(arr, size);
    // pq.insert(7);
    // pq.insert(8);
    // pq.insert(2);
    // pq.insert(4);
    // pq.insert(5);
    // cout << "Print Heap: " << endl;
    // pq.printHeap();

    // pq.deleteFromHeap();
    // cout << "Print Heap: " << endl;
    // pq.printHeap();
    return 0;
}