#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <array>

using namespace std;

void run() {
    array<int, 100001> a = {0};
    int n;
    cin >> n;
    
    int n2 = 0, n4 = 0, n6 = 0, n8 = 0;

    auto inc = [&](int x) {
        a[x]++;
        if (a[x] == 2) {
            n2++;
        } else if (a[x] == 4) {
            n2--;
            n4++;
        } else if (a[x] == 6) {
            n4--;
            n6++;
        } else if (a[x] == 8) {
            n6--;
            n8++;
        }
    };

    auto dec = [&](int x) {
        a[x]--;
        if (a[x] == 1) {
            n2--;
        } else if (a[x] == 3) {
            n2++;
            n4--;
        } else if (a[x] == 5) {
            n4++;
            n6--;
        } else if (a[x] == 7) {
            n6++;
            n8--;
        }
    };

    auto canBuild = [&]() {
        if (n8) {
            return true;
        }
        if (n6 >= 2) {
            return true;
        }
        if (n6 && (n4 || n2)) {
            return true;
        }
        if (n4 >= 2) {
            return true;
        }
        if (n4 && n2 >= 2) {
            return true;
        }
        return false;
    };

    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        inc(x);
    }

    int q;
    cin >> q;
    for (int i = 0; i < q; i++) {
        char c;
        int x;
        cin >> c >> x;
        if (c == '+') {
            inc(x);
        } else {
            dec(x);
        }

        cout << (canBuild() ? "YES\n" : "NO\n");
    }


}

int main() {
    int t;
    // cin >> t;
    t = 1;
    while (t--) {
        run();
    }
}