#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <array>
#include <unordered_map>
#include <set>

using namespace std;

struct Query {
    int l;
    int r;
    int k;
};

void run() {
    string s;
    cin >> s;
    int q;
    cin >> q;
    vector<Query> qq;
    qq.resize(q);
    for (int i = 0; i < q; i++) {
        cin >> qq[i].l >> qq[i].r >> qq[i].k;
        qq[i].l--;
        qq[i].r--;
    }

    string ans;
    ans.resize(s.length());
    for (int i = 0; i < s.length(); i++) {
        int idx = i;
        for (int j = 0; j < q; j++) {
            if (qq[j].l > idx || idx > qq[j].r) {
                continue;
            }

            int d = qq[j].r - qq[j].l + 1;
            idx = qq[j].l + (idx - qq[j].l + qq[j].k) % d;
        }
        ans[idx] = s[i];
    }

    cout << ans << endl;
}

int main() {
    int t;
    // cin >> t;
    t = 1;
    while (t--) {
        run();
    }
}