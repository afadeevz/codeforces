#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int f(vector<int>& x, int m) {
    int l = 0, r = x.size() - 1;

    while (l != r) {
        int mid = (l + r + 1) / 2;
        if (x[mid] > m) {
            r = mid - 1;
        } else {
            l = mid;
        }
    }

    if (l == 0 && m < x[0]) {
        return 0;
    }

    return l + 1;
}

int main() {
    int n, q;
    vector<int> x;

    cin >> n;
    x.reserve(n);
    for (int i = 0; i < n; i++) {
        int xi;
        cin >> xi;
        x.push_back(xi);
    }
    sort(x.begin(), x.end());

    cin >> q;
    for (int i = 0; i < q; i++) {
        int mi;
        cin >> mi;
        cout << f(x, mi) << endl;
    }
}