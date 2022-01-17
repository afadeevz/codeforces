#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <array>
#include <unordered_map>
#include <set>

using namespace std;

void run() {
    int n;
    cin >> n;
    vector<int> a;
    a.resize(n);
    set<int> nums;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        nums.insert(a[i]);
    }

    unordered_map<int, int> d;
    d.reserve(n);
    for (int i = 0; i < n; i++) {
        for (auto k : nums) {
            if (k >= a[i]) {
                break;
            }
            d[a[i]] = max(d[a[i]], d[k] + 1);
        }
    }

    cout << max_element(d.begin(), d.end())->second << endl;
}

int main() {
    int t;
    cin >> t;
    // t = 1;
    while (t--) {
        run();
    }
}