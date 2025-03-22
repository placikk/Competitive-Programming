//https://codeforces.com/gym/105535/problem/G
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
const int mxN = 1e5+7, mxA = 200;
int a[mxN], n;


int s[mxN], r[2*mxN];
void Manacher() {
    for (int i = 0, m = 0, k = 0, p = 0; i < 2 * n - 1; m = i++ - 1) {
        while (p < k and i / 2 + r[m] != k)
            r[i++] = min(r[m--], (k + 1 - p++) / 2);
        while (k + 1 < n and p > 0 and s[k + 1] == s[p - 1]) k++, p--;
        r[i] = (k + 1 - p++) / 2;
    }
}
int cnt[mxA+7];
int mob[mxA+7];

void mobius(){
    rep(i,1,mxA) mob[i] = 1;
    rep(i,2,mxA){
        bool ok = 1;
        rep(j,2,i-1) if(i%j == 0) ok = 0;
        if(ok){
            for(int j=i;j<=mxA;j+=i){
                if(j%(i*i) == 0) mob[j] = 0;
                else mob[j] *= -1;
            }
        } 
    }
}

int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    rep(i,1,n) cin >> a[i];
    
    rep(d,1,mxA){
        rep(i,1,n) s[i-1] = (i%2 ? (a[i]%d + d)%d : ((-a[i])%d+d)%d);
        Manacher();
        for(int i=1;i<=2*n-2;i+=2) cnt[d] += r[i];
    }
    

    mobius();
    int res = 0;
    rep(d,1,mxA){
        int akt = 0;
        rep(m,1,mxA/d) akt += mob[m]*cnt[d*m];
        res += d*akt;
    }
    cout << res << "\n";
}