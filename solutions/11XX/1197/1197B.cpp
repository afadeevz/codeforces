#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

void run() {
    int n;
    cin >> n;
    vector<int> a;
    a.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    int i;
    for (i = 0; i < n - 1 && a[i] < a[i+1]; i++) {}
    for (; i < n - 1 && a[i] > a[i+1]; i++) {}

    cout << (i == n - 1 ? "YES\n" : "NO\n");
}

int main() {
    int t = 1;
    // int t; cin >> t;
    while (t--) {
        run();
    }
}