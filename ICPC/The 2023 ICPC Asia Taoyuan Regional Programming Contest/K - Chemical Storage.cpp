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
const int mxN = 1e4+7;
vector<int> graf[mxN];
int c[mxN], deg[mxN], n;

int vis[mxN], c1[mxN], c2[mxN], cnt1, cnt2, blo[mxN];

void dfs(int v){
    vis[v] = 1;
    if(c1[v]) cnt1++;
    if(c2[v]) cnt2++;
    for(auto u : graf[v]) if(!vis[u] && !blo[u]) dfs(u);
}

vector<int> zablokowane(vector<int> v){
    for(auto x : v) {
        c[x] = 1;
        for(auto y : graf[x]) deg[y]++;
    }
    queue<int> q;
    for(auto x : v){
        bool ok = 0;
        for(auto y : graf[x]) if(deg[y] == 1) ok = 1;
        if(ok) q.push(x);
    }

    while(SZ(q)){
        int x = q.front(); q.pop();
        if(!c[x]) continue;
        c[x] = 0;
        for(auto y : graf[x]) {
            deg[y]--;
            if(deg[y] == 1){
                for(auto z : graf[y]) if(c[z]) q.push(z);
            }
        }
    }
    vector<int> res;
    rep(i,1,n) if(c[i]) res.pb(i);
    rep(i,1,n) c[i] = 0, deg[i] = 0;
    return res;
}

void solve(){
    int m; cin >> n >> m;
    rep(i,2,n){
        int j; cin >> j;
        graf[i].pb(j);
        graf[j].pb(i);
    }
    vector<int> a,b;
    rep(i,1,m){
        int x; cin >> x;
        a.pb(x);
    }
    rep(i,1,m){
        int x; cin >> x;
        b.pb(x);
    }

    vector<int> ab = zablokowane(a);
    vector<int> bb = zablokowane(b);
    //dbg(ab);
    //dbg(bb);
    if(ab != bb) cout << "0\n";
    else{
        for(auto u : ab) {
            blo[u] = 1;
            for(auto v : graf[u]) blo[v] = 1;
        }
        bool ok = 1;
        for(auto u : a) c1[u] = 1;
        for(auto u : b) c2[u] = 1;
        rep(i,1,n) if(!vis[i] && !blo[i]) {
            dfs(i);
            if(cnt1 != cnt2) ok = 0;
            cnt1 = 0, cnt2 = 0;
        }
        cout << ok << "\n";
    }

    rep(i,1,n) graf[i].clear();
    rep(i,1,n) blo[i] = 0, c1[i] = 0, c2[i] = 0, vis[i] = 0;
}

int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t; cin >> t;
    while(t--) solve();
}