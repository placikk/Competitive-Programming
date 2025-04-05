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
const int mxN = 107;
int x1[mxN], x2[mxN], yy1[mxN], y2[mxN];
vector<int> graf[mxN];
int dp[mxN];

void solve(){
    int n,k; cin >> n >> k;
    rep(i,1,n) cin >> x1[i] >> yy1[i] >> x2[i] >> y2[i];

    rep(i,1,n) graf[i].clear();
    rep(i,1,n) dp[i] = x2[i]-x1[i];

    rep(i,1,n) rep(j,i+1,n){
        if(y2[j] <= yy1[i] || y2[i] <= yy1[j]) continue;
        if(x1[i] < x1[j]) graf[i].pb(j);
        else graf[j].pb(i);
    }
    rep(x,1,n){
        rep(v,1,n){
            for(auto u : graf[v]){
                dp[v] = max(dp[v], dp[u] + k + x2[v]-x1[v]);
            }
        }
    }

    int res = 0;
    rep(i,1,n) res = max(res, dp[i]);

    int mnx = x1[1], mxx = x2[1];
    rep(i,1,n) mnx = min(mnx, x1[i]);
    rep(i,1,n) mxx = max(mxx, x2[i]);
    int mny = yy1[1], mxy = y2[1];
    rep(i,1,n) mny = min(mny, yy1[i]);
    rep(i,1,n) mxy = max(mxy, y2[i]);

    if(res >= mxx-mnx) cout << "0\n";
    else cout << (mxy-mny)*(mxx-mnx-res) << "\n";
}

int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t; cin >> t;
    while(t--) solve();
}