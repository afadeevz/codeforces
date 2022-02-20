#include <iostream>
#include <vector>
#include <set>
#include <map>

using namespace std;

#pragma region

using LL = long long;
using ULL = unsigned long long;

#define X first
#define Y second

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

using str = string;
using sv = string_view;

#define vec2(T, V, M, N, X) vector<vector<T>> V(M, vector<T>(N, X))

template <typename T, typename F> auto mapFind(T& m, F f) {return std::max_element(m.begin(), m.end(), f);}
template <typename T> auto mapMaxKey(T& m) {return mapFind(m, [](auto a, auto b) {return a.X < b.X;});}
template <typename T> auto mapMaxVal(T& m) {return mapFind(m, [](auto a, auto b) {return a.Y < b.Y;});}
template <typename T> auto mapMinKey(T& m) {return mapFind(m, [](auto a, auto b) {return a.X > b.X;});}
template <typename T> auto mapMinVal(T& m) {return mapFind(m, [](auto a, auto b) {return a.Y > b.Y;});}

#pragma endregion

// #define SINGLE_TEST
#define MULTI_TEST

void run() {
    LL s, i, e;
    cin >> s >> i >> e;

    if (s <= i) {
        int d = i - s;
        e -= d;
        s += d;
    }

    if (e < 0) {
        cout << 0 << endl;
    }

    
}

int main() {
    cout.precision(17);

#ifdef SINGLE_TEST
    run();
#endif

#ifdef MULTI_TEST
    size_t t;
    cin >> t;
    while (t--) {
        run();
    }
#endif
}