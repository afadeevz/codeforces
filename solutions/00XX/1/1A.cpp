#include <bits/stdc++.h>

using namespace std;

#pragma region

#define LL long long
#define SORT(x) sort(x.begin(), x.end())
#define RSORT(x) sort(x.rbegin(), x.rend())
#define READN(x, n) for(size_t i = 0, i < n; i++) {cin >> x[i];}

template<typename T>             inline T         read()         {T r; cin >> r; return r;}
template<typename T>             inline vector<T> read(size_t n) {vector<T> r; r.resize(n); for (size_t i = 0; i < n; i++) {cin >> r[i];} return r;}
template<typename T>             inline set<T>    read(size_t n) {set<T> r; for (size_t i = 0; i < n; i++) {T x; cin >> x; r.insert(x);} return r;}
template<typename T, typename U> inline map<T, U> read(size_t n) {map<T, U> r; for (size_t i = 0; i < n; i++) {T x; U y; cin >> x >> y; r[x] = y;} return r;}

template <typename T, size_t B> size_t lg(T x)   {size_t r; while (x >= B) {x /= B; r++;} return r;}
template <typename T>           size_t lg10(T x) {return lg<T, 10>(x);}
template <typename T>           size_t lg2(T x)  {return lg<T,  2>(x);}

#pragma endregion

// #define MULTI_TEST

void run() {
    LL n, m, a;
    cin >> n >> m >> a;
    auto ans = ((n + a - 1) / a) * ((m + a - 1) / a);
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