//https://codeforces.com/problemset/problem/2042/E
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
const int mxN = 2e5+7, LOG = 19;
vector<int> graf[2*mxN];
int cv[2*mxN], n;
vector<int> c[mxN]; 

int par[2*mxN], jp[LOG+1][2*mxN], dep[2*mxN];
void dfs_prep(int v,int pop){
    par[v] = pop;
    jp[0][v] = pop;
    dep[v] = dep[pop]+1;
    for(auto u : graf[v]) if(u != pop) dfs_prep(u, v);
}

int lca(int x,int y){
    if(x == y) return x;
    if(dep[x] < dep[y]) swap(x,y);

    for(int i=LOG;i>=0;i--) if(dep[jp[i][x]] >= dep[y]) x = jp[i][x];
    if(x == y) return x;
    for(int i=LOG;i>=0;i--) if(jp[i][x] != jp[i][y]) x = jp[i][x], y = jp[i][y];
    return jp[0][x];
}

int biore[2*mxN];
void wgore(int v){
    if(biore[v] == 1) return;
    biore[v] = 1;
    wgore(par[v]);
}

void wdol(int v){
    if(biore[v] == -1) return;
    biore[v] = -1;
    for(auto u : c[cv[v]]) if(u != v) wgore(u);
    for(auto u : graf[v]) if(u != par[v]) wdol(u);
}

vector<int> solve(int root){
    dfs_prep(root, 0);
    rep(j,1,LOG) rep(i,1,n){
        jp[j][i] = jp[j-1][jp[j-1][i]];
    }
    rep(i,1,n) biore[i] = 0;
    biore[root] = 1;
    rep(i,1,n/2) wgore(lca(c[i][0], c[i][1]));

    for(int i=n;i>=1;i--) if(biore[i] == 0) wdol(i);
    vector<int> res;
    for(int i=n;i>=1;i--) if(biore[i] == 1) res.pb(i);
    return res;
}

int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n; n *= 2;
    rep(i,1,n){
        cin >> cv[i];
        c[cv[i]].pb(i);
    }
    rep(i,2,n){
        int u,v; cin >> u >> v;
        graf[u].pb(v);
        graf[v].pb(u);
    }

    vector<int> r1 = solve(c[1][0]);
    vector<int> r2 = solve(c[1][1]);

    for(int i=0;i<min(SZ(r1), SZ(r2));i++){
        if(r1[i] < r2[i]){
            cout << SZ(r1) << "\n";
            for(auto u : r1) cout << u << " ";
                cout << "\n";
            return 0;
        }
        if(r1[i] > r2[i]){
            cout << SZ(r2) << "\n";
            for(auto u : r2) cout << u << " ";
                cout << "\n";
            return 0;
        }
    }
    if(SZ(r1) < SZ(r2)){
        cout << SZ(r1) << "\n";
        for(auto u : r1) cout << u << " ";
        cout << "\n";
    }else{
        cout << SZ(r2) << "\n";
        for(auto u : r2) cout << u << " ";
        cout << "\n";
    }
}