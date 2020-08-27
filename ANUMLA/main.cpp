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
vi test_data()
{
    vi num = {1, 1, 2, 3};
    int n = SZ(num);
}
void solve()
{
    test(zzz)
    {
        int n, some_;
        vi ans;
        cin >> n;
        multiset<int> ok;
        rep(i, 0, (1 << n))
        {
            cin >> some_;
            ok.insert(some_);
        }
        ok.erase(ok.lower_bound(0));
        auto it = ok.begin();
        ans.push_back(*it);
        ok.erase(it);
        if (n == 1)
        {
            for (auto xL : ans)
            {
                cout << xL << ' ';
            }
            cout << '\n';
            continue;
        }
        it = ok.begin();
        ans.push_back(*it);
        ok.erase(it);
        rep(i, 2, n)
        {
            // some shit happens
            int nsz = SZ(ans) - 1;
            rep(mask, 1, 1 << nsz)
            {
                int cnt = 0;
                int val = 0;
                rep(j, 0, nsz)
                {
                    if (mask & (1 << j))
                    {
                        cnt++;
                        val += ans[j];
                    }
                }
                if (cnt >= 1)
                {
                    ok.erase(ok.lower_bound(val + ans[SZ(ans) - 1]));
                }
            }
            it = ok.begin();
            ans.push_back(*it);
            ok.erase(it);
        }
        error("working ok?");
        for (auto xL : ans)
        {
            cout << xL << ' ';
        }
        cout << '\n';
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