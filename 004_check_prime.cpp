#include<iostream>
using namespace std;

bool checkprime(int n){
    bool prime=true;
    if(n==1){
        return !prime;
    }
    else{
        for(int i=2;i<n;i++){

            if(n%i==0){
              prime =false;
            }
          }
         return prime;
    }
}

int countPrimes(int n) {
  // Implement logic to count primes up to n
  int count=0;
  for(int i=1;i<=n;i++ ){
    bool check=checkprime(i);
    if(check==1){
      count++;
    }
  }
  cout<<count;
}

int main() {
    countPrimes(100);
    return 1;
}



