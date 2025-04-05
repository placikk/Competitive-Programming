//https://codeforces.com/contest/767/problem/E
#pragma GCC optimize ("O3")
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define rep(i, a, b) for (int i = (a); i <= (b); i++)
#define per(i, a, b) for (int i = (b); i >= (a); i--)
#define SZ(x) ((int)x.size())
#define all(x) x.begin(), x.end()
#define pb push_back
#define mp make_pair
#define st first
#define nd second
using ll = long long;
using lf = long double;
using pii = pair <int,int>;
using pll = pair<ll, ll>;
auto& operator<<(auto& o, pair<auto, auto> p) {
    return o << "(" << p.first << ", " << p.second << ")";
}
auto operator<<(auto& o, auto x)->decltype(end(x), o) {
    o << "{"; int i = 0; for (auto e: x) o << ", " + 2*!i++ << e;
    return o << "}";
}
#define dbg(x...) cerr<<"["#x"]: ", [](auto...$) {((cerr << $ << "; "),...)<<endl;}(x)
const int mxN = 1e5+7;
int c[mxN], w[mxN];
bool res[mxN];

int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n,k; cin >> n >> k;
    rep(i,1,n) cin >> c[i];
    rep(i,1,n) cin >> w[i];
    priority_queue<pair<int,int>> q;

    int odp = 0;
    rep(i,1,n){
        if(c[i]%100 == 0) continue;
        q.push({-(100-(c[i]%100))*w[i], i});
        if(k < c[i]%100){
            odp -= q.top().st;
            res[q.top().nd] = 1;
            q.pop();
            k += 100;
        }
        k -= c[i]%100;
    }
    cout << odp << "\n";
    rep(i,1,n){
        if(res[i]) cout << c[i]/100 + 1 << " 0\n";
        else cout << c[i]/100 << " " << c[i]%100 << "\n";
    }
}