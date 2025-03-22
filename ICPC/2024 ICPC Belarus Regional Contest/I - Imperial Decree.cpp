//https://codeforces.com/gym/105535/problem/I
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
const int mxN = 1507, MOD = 1e9+7;
int a[mxN][mxN];

int inv(int p,int w=MOD-2){
    int res = 1;
    while(w){
        if(w&1) res = (res * p)%MOD;
        w /= 2;
        p = (p*p)%MOD;
    }
    return res;
}

int cnt(int x,int y, int z,int t){
    return a[z][t] - a[x-1][t] - a[z][y-1] + a[x-1][y-1];
}

int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n,m; cin >> n >> m;
    rep(i,1,n) rep(j,1,m) cin >> a[i][j];
    int sum = 0;
    rep(i,1,n) rep(j,1,m) sum += a[i][j];
    sum = inv(sum);
    rep(i,1,n) rep(j,1,m) a[i][j] += a[i-1][j] + a[i][j-1] - a[i-1][j-1];
    int res = 0;
    int i2 = inv(2);
    int i3 = inv(3);
    int i9 = inv(9);
    rep(i,1,n) rep(j,1,m){
        int lg = cnt(1,1,i-1,j-1);
        int ld = cnt(i+1,1,n,j-1);
        int pg = cnt(1,j+1,i-1,m);
        int pd = cnt(i+1,j+1,n,m);
        int l = cnt(i,1,i,j-1);
        int g = cnt(1,j,i-1,j);
        int p = cnt(i,j+1,i,m);
        int d = cnt(i+1,j,n,j);
        int s = cnt(i,j,i,j);
        res = (res + 2*lg*pd)%MOD;
        res = (res + 2*ld*pg)%MOD;
        res = (res + 2*i3*l%MOD*p)%MOD;
        res = (res + 2*i3*g%MOD*d)%MOD;
        res = (res + i2*l%MOD*g)%MOD;
        res = (res + i2*g%MOD*p)%MOD;
        res = (res + i2*p%MOD*d)%MOD;
        res = (res + i2*d%MOD*l)%MOD;

        res = (res + lg%MOD*p)%MOD;
        res = (res + lg%MOD*d)%MOD;
        res = (res + ld%MOD*p)%MOD;
        res = (res + ld%MOD*g)%MOD;
        res = (res + pg%MOD*l)%MOD;
        res = (res + pg%MOD*d)%MOD;
        res = (res + pd%MOD*l)%MOD;
        res = (res + pd%MOD*g)%MOD;

        res = (res + i2*lg%MOD*s)%MOD;
        res = (res + i2*ld%MOD*s)%MOD;
        res = (res + i2*pg%MOD*s)%MOD;
        res = (res + i2*pd%MOD*s)%MOD;
        res = (res + i3*g%MOD*s)%MOD;
        res = (res + i3*p%MOD*s)%MOD;
        res = (res + i3*d%MOD*s)%MOD;
        res = (res + i3*l%MOD*s)%MOD;
        res = (res + i9*s%MOD*s)%MOD;
    }
    res = (res*sum)%MOD;
    res = (res*sum)%MOD;
    cout << res << "\n";

}