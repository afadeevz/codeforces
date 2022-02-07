#include <bits/stdc++.h>

using namespace std;

#pragma region

#define LL long long
#define SORT(x) sort(x.begin(), x.end())
#define RSORT(x) sort(x.rbegin(), x.rend())
#define READN(x, n) for(size_t i = 0, i < n; i++) {cin >> x[i];}

template<typename T>             inline T         read()         {T r; cin >> r; return r;}

template<typename T>             inline vector<T> readVec(size_t n = 0) {if (!n) {cin >> n;} vector<T> r; r.resize(n); for (size_t i = 0; i < n; i++) {cin >> r[i];} return r;}
template<typename T>             inline set<T>    readSet(size_t n = 0) {if (!n) {cin >> n;} set<T> r; for (size_t i = 0; i < n; i++) {T x; cin >> x; r.insert(x);} return r;}
template<typename T, typename U> inline map<T, U> readMap(size_t n = 0) {if (!n) {cin >> n;} map<T, U> r; for (size_t i = 0; i < n; i++) {T x; U y; cin >> x >> y; r[x] = y;} return r;}

template <typename T, size_t B> size_t lg(T x)   {size_t r; while (x >= B) {x /= B; r++;} return r;}
template <typename T>           size_t lg10(T x) {return lg<T, 10>(x);}
template <typename T>           size_t lg2(T x)  {return lg<T,  2>(x);}

#pragma endregion

// #define MULTI_TEST

void run() {
    int n; cin >> n; auto a = readVec<int>(n); SORT(a);
    int m; cin >> m; auto b = readVec<int>(m); SORT(b);

    int ans = 0;
    int j = 0;
    for (int i = 0; i < n; i++) {
        while (b[j] < a[i] - 1) {
            j++;
        }
        if (b[j] > a[i] + 1) {
            continue;
        }
        ans++;
        j++;
    }

    cout << ans;
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