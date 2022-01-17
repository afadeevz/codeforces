#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;

        vector<int> s;
        s.resize(n);
        for (int i = 0; i < n; i++) {
            cin >> s[i];
        }
        sort(s.begin(), s.end());

        int ans = 9999;
        for (int i = 0; i < n - 1; i++) {
            ans = min(ans, s[i+1] - s[i]);
        }

        cout << ans << endl;
    }

}