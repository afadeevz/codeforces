#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

void run() {
    long long n, r;
    cin >> n >> r;
    long long ans;
    if (n <= r) {
        ans = 1 + (n - 1) * n / 2;
    } else {
        ans = (r + 1) * r / 2;
    }
    cout << ans << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        run();
    }
}