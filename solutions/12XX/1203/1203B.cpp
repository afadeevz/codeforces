#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <array>

using namespace std;

void run() {
    int n;
    cin >> n;
    vector<int> a;
    a.resize(4 * n);
    for (int i = 0; i < 4 * n; i++) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());

    for (int i = 0; i < 4 * n; i += 2) {
        if (a[i] != a[i + 1]) {
            cout << "NO\n";
            return;
        }
    }

    int s = a[0] * a[4 * n - 1]; 
    for (int i = 0; i < 2 * n; i += 2) {
        if (a[i] * a[4 * n - i - 1] != s) {
            cout << "NO\n";
            return;
        }
    } 

    cout << "YES\n";
    return;
}

int main() {
    int t;
    cin >> t;
    // t = 1;
    while (t--) {
        run();
    }
}