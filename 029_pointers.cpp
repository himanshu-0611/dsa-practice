#include<iostream>
#include<vector>
#include<math.h>
#include<algorithm>
using namespace std;

int addFunc(int *arr, int s) {

    cout << "arr: " << arr << endl << endl;

    cout << "*arr: " << *arr << endl << endl;

    cout << "arr + 1: " << arr + 1 << endl << endl;

    cout << "*arr + 1: " << *arr + 1 << endl << endl;

    cout << "*(arr + 1): " << *(arr + 1) << endl << endl;

    int sum = 0;
    for(int i=0; i<s; i++) sum += arr[i];

    return sum;
}

int main() {

    //! 5. 2d array using pointers --------------------------------------------------------------------

    int** arr = new int* [5];

    for(int i=0; i<5; i++) {

        arr[i] = new int[3];
    }

    for(int i=0; i<5; i++) {

        for(int j=0; j<3; j++) {

            arr[i][j] = i;
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }



    //! 4. Pointer to an array ----------------------------------------------------------------------

    // int arr[] = {5,6,7,8};
    // int (*arr_ptr) [4] = &arr;
    
    
    // char arr[] = "fghi";
    // char (*arr_ptr) [5] = &arr;

    // cout << "arr:\t" << arr << endl << endl;

    // cout << "&arr:\t" << &arr << endl << endl;

    // cout << "arr + 1:\t" << arr + 1 << endl << endl;

    // cout << "&arr+1:\t" << &arr+1 << endl << endl;
    
    // cout << "arr_ptr:\t" << arr_ptr << endl << endl;

    // cout << "arr_ptr + 1:\t" << arr_ptr + 1 << endl << endl;

    // cout << "*arr_ptr:\t" << *arr_ptr << endl << endl;

    // cout << "&arr_ptr[2]:\t" << &arr_ptr[2] << endl << endl;

    //! 3. Double/Multiple pointers -----------------------------------------------------

    // int a = 5;
    // int* p = &a;
    // int**  q = &p;

    // cout << "a:\t" << a << endl << endl;

    // cout << "&a:\t" << &a << endl << endl;

    // cout << "p:\t" << p << endl << endl;

    // cout << "*p:\t" << *p << endl << endl;

    // cout << "&q:\t" << &p << endl << endl;

    // cout << "q:\t" << q << endl << endl;

    // cout << "&q:\t" << &q << endl << endl;

    // cout << "*q:\t" << *q << endl << endl;

    // cout << "**q:\t" << **q << endl << endl;

    // cout << "***q:\t" << ***q << endl << endl;



    //! 2. Passing array in func ----------------------------------------------------------------------

    // int arr[] = {1,2,3,4,5};

    // cout << "Passing arr: " << arr << endl << endl;

    // cout << "SUM: " << addFunc(arr, 5);


    //! 1. Comparing Int and Char Array for Pointers Basics ---------------------------------------------------------------------------------------
    
    // int arr[] = {1,2,3,4,5};
    // int *ptr =  arr;
    // // char arr[] = "abcdef";
    // // char *ptr =  arr;

    // cout << "arr: " << arr << endl << endl;

    // cout << "&arr: " << &arr << endl << endl;

    // cout << "&arr[2]: " << &arr[2] << endl << endl;

    // cout << "*arr: " << *arr << endl << endl;

    // cout << "*arr + 1: " << *arr + 1 << endl << endl;

    // cout << "*(arr + 1): " << *(arr + 1) << endl << endl;

    // cout << "ptr: " << ptr << endl << endl;

    // cout << "*ptr: " << *ptr << endl << endl;

    // cout << "ptr + 1: " << ptr + 2 << endl << endl;

    // cout << "arr + 1: " << arr + 2 << endl << endl;
    return 0;
}