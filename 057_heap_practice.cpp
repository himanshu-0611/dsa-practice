#include<iostream>
#include<vector>
#include<math.h>
#include<algorithm>
using namespace std;

class Heap{
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
        for(int i=1; i<=index; i++) {
            if(i==0) {
                cout << 'X' << " ";
            } else {
                cout << arr[i] << " ";
            }
        }
        cout << endl;
    }

    void insert(int value) {
        if(index == size-1) {
            cout << "Overflow" << endl;
            return;
        }

        index++;
        arr[index] = value;
    
        int childIndex = index;

        while(childIndex > 1) {
            int parentIndex = childIndex/2;
            
            if(arr[parentIndex] < arr[childIndex]) {
                swap(arr[parentIndex], arr[childIndex]);
                
                childIndex = parentIndex;
            } else {
                break;
            }
        }
    }

    void deleteFromHeap() {
        // swap arr[1] with arr[last elem]
        // index--
        // call heapify on index 1

        if(index == 0) {
            cout << "Underflow" << endl;
        }

        swap(arr[1], arr[index]);
        index--;
        int capacity = index;
        heapify(1, capacity);
    }

    void heapify(int i, int capacity) {
        // we need to fix the position of index given to us
        // so get the index of both the children of i
        // maintain a greaterIndex = i
        // if leftchild is greater than greaterIndex, then greaterIndex = left index
        // if rightchild is greater than greaterIndex, then greaterIndex = left index 
        // if greaterIndex != i:
        //     swap greaterIndex and i values
        // recursively call heapify(for the greaterIndex)

        int leftChild = 2*i;
        int rightChild = 2*i + 1;
        int greaterIndex = i;

        if(leftChild < capacity && arr[greaterIndex] < arr[leftChild]) {
            greaterIndex = leftChild;
        }
        if(rightChild < capacity && arr[greaterIndex] < arr[rightChild]) {
            greaterIndex = rightChild;
        }

        if(greaterIndex != i) {
            swap(arr[i], arr[greaterIndex]);
            heapify(greaterIndex, capacity);
        }
    }
};

void heapify(vector<int>& arr, int i, int capacity) {
    // we need to fix the position of index given to us
    // so get the index of both the children of i
    // maintain a greaterIndex = i
    // if leftchild is greater than greaterIndex, then greaterIndex = left index
    // if rightchild is greater than greaterIndex, then greaterIndex = left index 
    // if greaterIndex != i:
    //     swap greaterIndex and i values
    // recursively call heapify(for the greaterIndex)

    int leftChild = 2*i;
    int rightChild = 2*i + 1;
    int greaterIndex = i;

    if(leftChild < capacity && arr[greaterIndex] < arr[leftChild]) {
        greaterIndex = leftChild;
    }
    if(rightChild < capacity && arr[greaterIndex] < arr[rightChild]) {
        greaterIndex = rightChild;
    }

    if(greaterIndex != i) {
        swap(arr[i], arr[greaterIndex]);
        heapify(arr, greaterIndex, capacity);
    }
}

void buildHeap(vector<int>& arr) {
    for(int i=arr.size()/2; i>=0; i--) {
        heapify(arr, i, arr.size());
    }
}

void heapSort(vector<int> arr) {
    // we pop and push and last
    // from max to 1: we go on swapping index 1 with n
    // and we heapify the remaing array
    while(n > 1) {
        swap(arr[1], arr[n]);
        n--;
        heapify(arr, n, 1);
    }
}

int main() {
    // Heap pq(6);
    // pq.insert(2);
    // pq.insert(34);
    // pq.insert(6);
    // pq.insert(3);
    // // pq.insert(20);

    // pq.deleteFromHeap();

    // pq.printHeap();

    vector<int> arr = {3, 2, 5, 22, 15, 511};
    buildHeap(arr);

    for(int i=0; i<arr.size(); i++) {
        cout << arr[i] << " ";
    }
}