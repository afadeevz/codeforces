#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <array>
#include <unordered_map>
#include <set>

using namespace std;

void run() {
    long long n;
    cin >> n;
    
    for (long long b = 1; b * b <= n; b++) {
        if (n % b == 0) {
            long long a = n * n / b;
            if ((a + b) % 2) {
                continue;
            }
            if (a == b) {
                continue;
            }

            long long m = (a - b) / 2;
            long long k = (a + b) / 2;
            cout << m << ' ' << k << endl;
            return;
        }
    }

    cout << "-1\n";
}

int main() {
    int t;
    // cin >> t;
    t = 1;
    while (t--) {
        run();
    }
}