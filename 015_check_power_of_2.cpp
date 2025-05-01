#include<iostream>
using namespace std;

string isPowerOfTwo(int num) {

    // ! 3rd Solution
    if(num == 0) return "No";

    //below code is based on that input > 0
    num = num & (num-1);
    if(num == 0) return "Yes";
    else return "No";

    // ! 2nd Solution
    // int n = num;
    // if(n == 1) return "Yes";
    // if(n == 3) return "No";
    // while(n >= 1) {
    //     n = n >> 1;
    //     cout << "n is: " << n << endl;
    //     if(n == 1) return "Yes";
    //     if(n & 1) return "No";
    // }
    // return "No";

 
    // ! 1st Solution
    // int n = 2;
    // if(num == 2 || num == 1) return "Yes";
    // while(n <= num) {
    //     n = n*2;
    //     if(n == num) return "Yes";
    // }
    // return "No";
}

int main() {
    cout << isPowerOfTwo(8);
    return 0;
}