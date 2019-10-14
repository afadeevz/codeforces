#include <iostream>

using namespace std;

int f(int n) {
    if (n % 10) {
        return n - 1;
    }
    return n / 10;
}

int main() {
    int n, k;
    cin >> n >> k;

    for (int i = 0; i < k; i++) {
         n = f(n);
    }

    cout << n << endl;
}