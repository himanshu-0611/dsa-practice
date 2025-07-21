#include<iostream>

        x /= 10;
    }
    while(num) {
        int pow = 1;
        for(int i=1; i<=count; i++) {
            pow *= (num%10);
        }
        ch = ch + pow;
        num /= 10;
    }
    if(ch == orig) return "Yes";
    return "No";
}

int main() {
    cout << isNarcissistic(153);
    return 0;
}