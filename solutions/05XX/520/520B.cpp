#include <bits/stdc++.h>

using namespace std;

#pragma region

using LL = long long;
using ULL = unsigned long long;

#define SORT(x) sort(x.begin(), x.end())
#define RSORT(x) sort(x.rbegin(), x.rend())
#define READN(x, n) for(size_t i = 0, i < n; i++) {cin >> x[i];}

template <typename T>             inline T         read()         {T r; cin >> r; return r;}
template <typename T>             inline vector<T> readVec(size_t n = 0) {if (!n) {cin >> n;} vector<T> r; r.resize(n); for (size_t i = 0; i < n; i++) {cin >> r[i];} return r;}
template <typename T>             inline set<T>    readSet(size_t n = 0) {if (!n) {cin >> n;} set<T> r; for (size_t i = 0; i < n; i++) {T x; cin >> x; r.insert(x);} return r;}
template <typename T, typename U> inline map<T, U> readMap(size_t n = 0) {if (!n) {cin >> n;} map<T, U> r; for (size_t i = 0; i < n; i++) {T x; U y; cin >> x >> y; r[x] = y;} return r;}

template <typename T, size_t B> size_t lg(T x)   {size_t r; while (x >= B) {x /= B; r++;} return r;}
template <typename T>           size_t lg10(T x) {return lg<T, 10>(x);}
template <typename T>           size_t lg2(T x)  {return lg<T,  2>(x);}

template <typename T> void sort2(T& a, T& b) {if (a > b) swap(a, b);}
template <typename T> void sort3(T& a, T& b, T& c) {sort2(a, b); sort2(a, c); sort2(b, c);}
template <typename T> void sort4(T& a, T& b, T& c, T& d) {sort2(a, b); sort2(c, d); sort2(a, c); sort2(b, d); sort2(b, c);}

template <typename T> string toStr(T x) {return to_string(x);}
LL str2int(string s) {return stoll(s);}
ULL str2uint(string s) {return stoull(s);}

#pragma endregion

// #define MULTI_TEST

int solve(int n, int m) {
    vector<int> a(max(m, n) * 2 + 1, 999999);
    
    auto dfs = [&](int i, int k, auto&& dfs) {
        if (i < 0) {
            return;
        }
        if (i > 2 * m && i > 2 * n) {
            return;
        }

        if (a[i] <= k) {
            return;
        };
        a[i] = k;

        dfs(i * 2, k + 1, dfs);
        dfs(i - 1, k + 1, dfs);
    };

    dfs(n, 0, dfs);

    return a[m];
}

void run() {
    int n, m;
    cin >> n >> m;
    cout << solve(n, m) << endl;
}

int main() {
#ifdef MULTI_TEST
    size_t t;
    cin >> t;
    while (t--) {
        run();
    }
#else
    run();
#endif
}