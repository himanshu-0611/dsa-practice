#include<iostream>
#include<vector>
#include<math.h>
#include<algorithm>
using namespace std;

void printV(vector<int> v) {
    cout << "\nPrinting the vector: ---------- ";
    for(int i=0; i<v.size(); i++) cout << v[i] << " ";
}

void print2DV(vector<vector<int>> v) {
    cout << "\nPrinting 2D vector: --------- ";
    for(int i = 0; i < v.size(); i++) {
        for(int j = 0; j < v[i].size(); j++) {
            cout << v[i][j] << ", ";
        }
        cout << endl;
    }
}

class Stack {
    public:
        int* arr;
        int top1;
        int top2;
        int size;

        Stack(int capacity) {
            arr = new int[capacity];
            size = capacity;
            top1 = -1;
            top2 = size;
        }

        void push1(int value) {
            //normal push or overflow
            if(top2 - top1 == 1) {
                cout << "Stack Overflow" << endl;
            }
            else {
                top1++;
                arr[top1] = value;
            }
        }
        void push2(int value) {
            //normal push or overflow
            if(top2 - top1 == 1) {
                cout << "Stack Overflow" << endl;
            }
            else {
                top2--;
                arr[top2] = value;
            }
        }
        void pop1() {
            //normal or underflow
            if(top1 == -1) {
                cout << "Stack Underflow" << endl;
            }
            else {
                top1--;
            }
        }
        void pop2() {
            //normal or underflow
            if(top2 == size) {
                cout << "Stack Underflow" << endl;
            }
            else {
                top2++;
            }
        }
        void print() {
            for(int i=0; i<size; i++) {
                cout << arr[i] << " ";
            }
            cout << endl;
        }
};

int main() {
    Stack s(10);
    s.push1(10);
    s.push2(17);
    s.print();
    return 0;
}