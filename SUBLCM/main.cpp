/*****************************************************************
IN GOD WE TRUST !!   

Author:- meet2mky
Date: -
Problem:-
Institue:- NITA
******************************************************************/
#include <iostream>
#include <bitset>
#include <map>
#include <unordered_map>
#include <vector>
#include <cstring>
#include <set>
#include <utility>
#include <algorithm>
#include <queue>
#include <cassert>
#include <cctype>
#include <iomanip>
#include <stack>
#include <ctime>
#include <iterator>
#include <sstream>
using namespace std;
#define sync                      \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0)
#define rep(i, a, b) for (int i = (a); i < (b); i++)
#define repi(i, a, b) for (int i = (a); i > (b); i--)
#define all(x) (x).begin(), (x).end()
#define setall(x, val) fill(all(x), val)
#define pb push_back
#define vb vector<bool>
#define vi vector<int>
#define vvi vector<vi>
#define pii pair<int, int>
#define sp(x) setprecision(x)
#define endl '\n'
#define ll long long
#define ld long double
#define SZ(z) (int)(z).size()
#define inf 0x3f3f3f3f
#define linf 0x3f3f3f3f3f3f3f3f
#define eps 0.0000001 // eps = 1e-7
#define PI 3.141592653589793238

//#define int long long
const int MOD = 1000000007;

//variadic functions
template <typename T>
T sum() { return 0; }
template <typename T, typename... Args>
T sum(T a, Args... args) { return a + sum(args...); }

//Debugger  -------------------------------------------->
#define error(args...)                           \
    {                                            \
        string _s = #args;                       \
        replace(_s.begin(), _s.end(), ',', ' '); \
        stringstream _ss(_s);                    \
        istream_iterator<string> _it(_ss);       \
        err(_it, args);                          \
    }

void err(istream_iterator<string> it)
{
}
template <typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args)
{
    cerr << *it << " = " << a << endl;
    err(++it, args...);
}
//Debugger  <--------------------------------------------
const int N = 1e6 + 10;
int spf[N];
void sieve()
{
    //  error("Something is fishy I can feel it!");
    rep(i, 0, N)
    {
        spf[i] = i;
    }
    // i < 2 is invalid
    for (int i = 2; i * i < N; i++)
    {
        if (spf[i] == i)
        {
            for (int j = i * i; j < N; j += i)
            {
                spf[j] = i;
            }
        }
    }
    //  error("Atleast this is ok!");
}
void solve()
{

    int n;
    cin >> n;
    //  error(n);
    vi a(n);
    for (auto &x : a)
    {
        cin >> x;
    }
    //  error(n);
    int l = 0;
    int r = 1;
    int res = 1;
    // [l..r)
    vector<bool> p(N, false);
    vector<int> primes[n];
    rep(i, 0, n)
    {
        int num = a[i];
        int prev = -1;
        while (num > 1)
        {
            prev = spf[num];
            primes[i].push_back(prev);
            num /= spf[num];
            while (spf[num] == prev && num > 1)
                num /= spf[num];
        }
    }
    for (auto x : primes[0])
    {
        p[x] = true;
    }
    while (l < n - 1 && r < n)
    {
        bool ok = true;
        for (auto now : primes[r])
        {
            if (p[now] == true)
            {
                ok = false;
                break;
            }
        }
        if (ok)
        {
            for (auto now : primes[r])
            {
                p[now] = true;
            }
            r++;
        }
        else
        {
            for (auto now : primes[l])
            {
                p[now] = false;
            }
            l++;
        }
        res = max(res, r - l);
    }
    (res == 1) ? cout << -1 : cout << res;
    cout << endl;
}

signed main()
{
    sync;
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    sieve();
    int t = 1;
    cin >> t;
    //  error(t);
    while (t--)
    {
        solve();
    }
    return 0;
}