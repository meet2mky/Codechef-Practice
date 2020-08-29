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
#define endl '\n'
#define MOD 1000000007
#define ll long long
#define ld long double
#define SZ(z) (int)(z).size()
#define test(t) \
    int t;      \
    cin >> t;   \
    while (t--)

//#define int long long
#define inf 0x3f3f3f3f
#define linf 0x3f3f3f3f3f3f3f3f
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

void solve()
{
    test(zzz)
    {
        int n;
        cin >> n;
        vi a(n);
        rep(i, 0, n)
        {
            cin >> a[i];
            a[i]++;
            a[i] %= n;
        }
        int res = 0;
        vb blocked(n, false);
        rep(i, 0, n)
        {
            if (!blocked[i])
            {
                int curr = i;
                map<int, int> seen;
                seen[i] = 1;
                vi here = {i};
                while (seen[(curr + a[curr]) % n] == 0 && blocked[(curr + a[curr]) % n] == false)
                {
                    curr += a[curr];
                    curr %= n;
                    seen[curr] = 1;
                    here.pb(curr);
                }
                curr += a[curr];
                curr %= n;

                if (seen[curr] == 1)
                {
                    rep(j, 0, SZ(here))
                    {
                        if (here[j] == curr)
                        {
                            res += SZ(here) - j;
                            break;
                        }
                    }
                }
                for (auto x : seen)
                {
                    blocked[x.first] = true;
                }
            }
        }
        cout << res << '\n';
    }
}

signed main()
{
    sync;
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    solve();
    return 0;
}