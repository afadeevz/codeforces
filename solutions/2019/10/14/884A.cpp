#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    const auto ds = 86400;

    int n, t;
    cin >> n >> t;
    vector<int> a;
    a.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    int i = 0;
    while (t > 0) {
        t -= ds - a[i];
        i++;
    }

    cout << i;
}