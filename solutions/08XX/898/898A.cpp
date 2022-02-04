#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

void run() {
    int n;
    cin >> n;
    int d = n % 10;
    if (d < 5) {
        n -= d;
    } else {
        n += 10 - d;
    }

    cout << n << endl;
}

int main() {
    int t = 1;
    // int t; cin >> t;
    while (t--) {
        run();
    }
}