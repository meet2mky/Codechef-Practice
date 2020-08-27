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
int ok(int a, int b, int c)
{
    int a_now = a;
    int b_now = 0;
    int step = 1;
    while (a_now != c && b_now != c)
    {
        int this_much = min(b - b_now, a_now);
        b_now += this_much;
        a_now -= this_much;
        step++;
        if (b_now == c || a_now == c)
        {
            break;
        }
        if (b_now == b)
        {
            b_now = 0;
            step++;
        }
        if (a_now == 0)
        {
            a_now = a;
            step++;
        }
    }
    return step;
}
void solve()
{
    test(zzzz)
    {
        int a, b, c;
        cin >> a >> b >> c;
        if (c > max(a, b))
        {
            cout << "-1\n";
        }
        else if (c % __gcd(a, b) != 0)
        {
            cout << "-1\n";
        }
        else if (c == a || c == b)
        {
            cout << "1\n";
        }
        else
        {
            cout << min(ok(a, b, c), ok(b, a, c)) << "\n";
        }
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