#include<iostream>
#include<vector>
#include<math.h>
#include<algorithm>
using namespace std;

// string factorial(int N) {
//     long long ans = N, x = (long long int) N;
//     while(x >= 1) {
//         long long val = (long long)(x-1);
//         long long ans1 = ans;
//         while(val) {
//             if(val == 1) break;
//             ans += (long long) ans1;
//             val--;
//         }
//         x--;
//     }
//     cout << "ANS: " << ans << endl;


//     string s;
//     while(ans) {
//         int digit = ans%10;
//         cout << " DIGIT : " <<  digit << endl;
//         if(digit == 0) s += '0';
//         if(digit == 1) s += '1';
//         if(digit == 2) s += '2';
//         if(digit == 3) s += '3';
//         if(digit == 4) s += '4';
//         if(digit == 5) s += '5';
//         if(digit == 6) s += '6';
//         if(digit == 7) s += '7';
//         if(digit == 8) s += '8';
//         if(digit == 9) s += '9';
//         ans /= 10;
//     }
//     cout << " BEOFRE RETU: " << s << endl;
//     reverse(s.begin(), s.end());
//     return s;
// }

string factorial(int N) {
    // Use a vector to store the digits of the factorial result
    vector<int> result(1, 1); // Initialize with 1 (0! = 1)

    for (int i = 2; i <= N; i++) {
        int carry = 0;
        for (int j = 0; j < result.size(); j++) {
            int prod = result[j] * i + carry;
            result[j] = prod % 10; // Store the last digit
            carry = prod / 10;    // Carry over the remaining digits
        }
        while (carry) {
            result.push_back(carry % 10);
            carry /= 10;
        }
    }

    // Convert the result vector to a string
    string s;
    for (auto it = result.rbegin(); it != result.rend(); ++it) {
        s += to_string(*it);
    }

    return s;
}

int main() {
    cout << factorial(25);
    return 0;
}