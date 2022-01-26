#include <iostream>

using namespace std;

void run() {
    string s;
    cin >> s;
    if (s.length() > 10) {
        cout << s[0] << s.length() - 2 << s.back() << endl;
    } else {
        cout << s << endl;
    }
}

int main() {
    // int t = 1;
    int t; cin >> t;
    while (t--) {
        run();
    }
}