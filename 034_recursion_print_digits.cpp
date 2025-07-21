#include<iostream>
#include<vector>
#include<math.h>
#include<algorithm>
using namespace std;

void printDigits(int t) {

    if(t == 0) return;
    
    printDigits(t/10);
    
    cout << t%10 << endl;
}

int makeDigit(int* arr, int size, int dig, int mult) {

    if(size <= 0) return dig;

    dig += arr[size-1]*mult;

    mult *= 10;

    return makeDigit(arr, size-1, dig, mult);
}

int main() {
    printDigits(234);

    int arr[] = {4,5,3,2};
    int dig = 0, mult = 1;

    cout << "Dig: " <<
    makeDigit(arr, 4, dig, mult);
    return 0;
}