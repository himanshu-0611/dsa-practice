#include<iostream>
using namespace std;

//TC: O(n)
//SC: O(n) - each call uses stack space

unsigned long long printFactorial(unsigned long long n) {
    if(n == 1 || n == 0) return 1;
    return n * printFactorial(n-1);
}

int main(){
    cout << printFactorial(5);
    return 0;
}