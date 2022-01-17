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
    sort(a.begin(), a.end());
    long long ans = 1ll * a[n-1] * a[n-2] * a[n-3] * a[n-4] * a[n-5];
    ans = max(ans, 1ll * a[n-1] * a[n-2] * a[n-3] * a[0] * a[1]);
    ans = max(ans, 1ll * a[n-1] * a[0] * a[1] * a[2] * a[3]);
    cout << ans << endl; 
}

int main() {
    // int t = 1;
    int t; cin >> t;
    while (t--) {
        run();
    }
}