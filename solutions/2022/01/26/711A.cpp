#include <iostream>
#include <string>
#include <vector>

using namespace std;

void run() {
    int n;
    cin >> n;
    vector<string> s(n);

    for (int i = 0; i < n; i++) {
        cin >> s[i];
    }
    for (int i = 0; i < n; i++) {
        bool y = false;
        auto& si = s[i];
        if (si[0] == 'O' && si[1] == 'O') {
            si[0] = '+';
            si[1] = '+';
            y = true;
        } else if (si[3] == 'O' && si[4] == 'O') {
            si[3] = '+';
            si[4] = '+';
            y = true;
        }

        if (!y) {
            continue;
        }

        cout << "YES\n";
        for (int j = 0; j < n; j++) {
            cout << s[j] << endl;
        }
        return;
    }

    cout << "NO\n";
}

int main() {
    int t = 1;
    // int t; cin >> t;
    while (t--) {
        run();
    }
}