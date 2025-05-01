#include<iostream>
#include<vector>
#include<math.h>
#include<algorithm>
using namespace std;

//* For Prime Factorization method
// bool checkprime(int n){
//     bool prime=true;
//     if(n==1){
//         return !prime;
//     }
//     else{
//         for(int i=2;i<n;i++){

//             if(n%i==0){
//               prime =false;
//             }
//           }
//          return prime;
//     }
// }

int countNoOfDivisors(int n) {

    //! Prime factorization - chat gpt code

    //TC: o(root n)
    //SC: o(1)

    int count = 1;
    int i = 2;

    // Check for all factors from 2 to sqrt(n)
    while (i * i <= n) {
        if (n % i == 0) {
            int exponent = 0;
            // Count the number of times i divides n
            while (n % i == 0) {
                n /= i;
                exponent++;
            }
            count *= (exponent + 1); // (exponent + 1) is the number of divisors for prime i
        }
        i++;
    }

    // If n is a prime number greater than 1
    if (n > 1) {
        count *= 2; // Prime numbers contribute (1 + 1) divisors: 1 and the number itself
    }

    return count;

    //! Prime Factorization - our code not working

    //get the prime factors divisible by the number
    //count and store the no of times each factor is occuring
    //calc the divisors from the above count

    //Below code is not working properly

    vector<int> v;
    vector<int> count(10, 0);
    int track = 0;

    for(int i=1; i<=n; i++) {
        if(checkprime(i)) {
            while(n%i == 0) {
                    // cout << "div i: " << i << endl;
                    auto x = find(v.begin(), v.end(), i);
                    if(x != v.end()) {
                        // cout << "I: " << i << endl;
                        count[track]++;
                    } else {
                        v.push_back(i);
                        count[track]++;
                    }
                    n = n/i;
                
            }
            track++;
        }
    }

    int fin = 1;
    for(int i=0; i<v.size(); i++) {
        fin = fin * (count[i]+1);
    }
    cout << endl;

    return fin;

    //! Square Root optimization - 1 to √n

    //TC: O(root n)
    //SC: O(1)
    
    // int count = 0;
    // for(int i=1; i*i<=n; i++) {
    //     if(n%i == 0) {
    //         cout << "i: " << i  << endl;
    //         if(i == n/i) count = count++;
    //         else count = count+2;
    //     }
    // }
    // return count;

    //! Simple Method

    //TC: O(n)

    // int div = n, c = 0;
    // while(div) {
    //     if(n%div == 0) c++;
    //     div--;
    // }
    // return c;
}

int main() {
    cout << countNoOfDivisors(12);
    return 0;
}