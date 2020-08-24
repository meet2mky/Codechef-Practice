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
#define mp make_pair
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

#define int long long
#define inf 0x3f3f3f3f

//variadic functions
template <typename T>
T sum() { return 0; }
template <typename T, typename... Args>
T sum(T a, Args... args) { return a + sum(args...); }

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
const int maxn = 100010;
int node, ans = (int)1e18;
int cur_ans = 0;
string str;
int dfs(int previ, int node, int col, vvi &g, vi &c)
{
    int temp = 0;
    if (c[node] != col)
        temp = 2 * c[node] - 1;

    for (int i : g[node])
        if (i != previ)
        {
            int t = dfs(node, i, col ^ 1, g, c);
            cur_ans += abs(t);
            temp += t;
        }
    return temp;
}
int compute(vvi &g, vi &c)
{
    //set cur_ans = 0;
    cur_ans = 0;
    int here = dfs(0, 1, 0, g, c);
    if (here == 0)
        return cur_ans;
    return 1e18;
}
void solve()
{
    ans = 1e18;
    cin >> node;
    vvi g;
    g.resize(node + 1);
    vi c(node + 1);
    rep(i, 1, node)
    {
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    cin >> str;
    rep(i, 1, node + 1)
    {
        c[i] = (str[i - 1] == '1');
    }
    ans = min(ans, compute(g, c));
    // change colors
    rep(i, 1, node + 1)
    {
        c[i] ^= 1;
    }
    ans = min(ans, compute(g, c));
    if (ans == 1e18)
    {
        cout << "-1\n";
    }
    else
    {
        cout << ans << endl;
    }
}

signed main()
{
    sync;
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    test(zzzz)
        solve();
    return 0;
}