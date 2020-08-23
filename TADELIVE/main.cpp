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
#define pii pair<int,int>
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
T sum() { return 0;}
template<typename T, typename... Args>
T sum(T a, Args... args){ return a + sum(args...);}

void solve()
{
    int n,x,y;
    cin >> n >> x >> y;
    vi a(n),b(n);
    rep(i,0,n) cin >> a[i];
    rep(i,0,n) cin >> b[i];
    vector<pair<int,pii> > here(n);
    rep(i,0,n) here[i] = {abs(a[i]-b[i]),{a[i],b[i]}};
    sort(all(here));
    int x_count = 0;
    int y_count = 0;
    int ans = 0;
    for(auto it = rbegin(here); it!=rend(here);it++){
        if(it->second.first > it->second.second){
            if(x_count < x){
                ans+=it->second.first;
                x_count++;
            }else{
                ans += it->second.second;
                y_count++;
            }
        }else{
            if(y_count < y){
                ans += it->second.second;
                y_count++;
            }else{
                ans+=it->second.first;
                x_count++;
            }

        }
    }
    cout << ans << endl;
}
signed main()
{
    sync;
#ifndef ONLINE_JUDGE
   freopen("input.txt","r", stdin);
   freopen("output.txt","w", stdout);
#endif
    solve();
    return 0;
}