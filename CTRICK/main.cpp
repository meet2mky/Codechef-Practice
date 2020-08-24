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

//#define int long long
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

const int MAXN = 20009;
int BIT[MAXN];
void update(int pos, int value, int n)
{
    while (pos <= n)
    {
        BIT[pos] += value;
        pos += (pos & (-pos));
    }
}
int query(int pos, int n)
{
    assert(pos <= n);
    int res = 0;
    while (pos > 0)
    {
        res += BIT[pos];
        pos -= (pos & (-pos));
    }
    return res;
}
int binary_(int sum, int n)
{
    int l = 1, r = n;
    // query(l,n) <= sum && query(r,n) >= sum
    while (r - l > 1)
    {
        int mid = (r + l) / 2;
        if (query(mid, n) >= sum)
        {
            r = mid;
        }
        else
        {
            l = mid + 1;
        }
    }
    if (query(l, n) == sum)
        return l;
    if (query(r, n) == sum)
        return r;
    assert(false);
    return -1;
}
void solve()
{
    test(zzz)
    {
        int n;
        cin >> n;
        rep(i, 1, n + 1)
        {
            update(i, 1, n);
        }
        int card_to_remove_extra = 0;
        vi ans(n + 1);
        rep(i, 1, n + 1)
        {

            int net_card_to_remove = card_to_remove_extra + 1 + i;

            int card_in_deck = n - i + 1;

            net_card_to_remove %= card_in_deck;
            if (net_card_to_remove == 0)
                net_card_to_remove += card_in_deck;
            int pos_ = binary_(net_card_to_remove, n);

            ans[pos_] = i;
            update(pos_, -1, n);
            card_to_remove_extra = query(pos_ - 1, n);
        }
        rep(i, 1, n + 1)
        {
            cout << ans[i] << ' ';
        }
        cout << "\n";
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