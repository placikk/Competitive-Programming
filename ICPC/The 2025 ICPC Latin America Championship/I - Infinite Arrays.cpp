#pragma GCC optimize ("O3")
#include <bits/stdc++.h>
using namespace std;
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
const int mxN = 2e6+7;
int a[mxN];
int bft[mxN], nxt[mxN];

int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n; cin >> n;
    rep(i,1,n) cin >> a[i];
    rep(i,2,n) bft[a[i]] = a[i-1];
    rep(i,1,n-1) nxt[a[i]] = a[i+1];
    nxt[a[n]] = a[1];
    bft[a[1]] = a[n];



    int q; cin >> q;
    while(q--){
        char z; cin >> z;
        if(z == '-'){
            int b; cin >> b;
            int a = bft[b], c = nxt[b]; 
            nxt[a] = c;
            bft[c] = a;
            nxt[b] = 0;
            bft[b] = 0;
            n--;
        }
        if(z == '+'){
            int b,c; cin >> b >> c;
            int a = bft[c];
            nxt[a] = b;
            bft[c] = b;
            bft[b] = a;
            nxt[b] = c;
            n++;
        }

        if(z == '?'){
            int k; cin >> k;
            rep(i,1,k) cin >> a[i];
            rep(i,k+1,2*k) a[i] = a[i-k];
            if(k%n == 0){
                bool ok = 1;
                rep(i,1,k) if(!nxt[a[i]]) {
                    ok = 0;
                    break;
                }
                rep(i,1,k) if(nxt[a[i]] != a[i+1]) {
                    ok = 0;
                    break;
                }
                if(ok) {
                    cout << "*\n";
                    continue;
                }
            }
            k *= 2;
            int akt = 0, res = 0;
            int pop = 0;
            rep(i,1,k){
                if(!nxt[a[i]]) akt = 0;
                else{
                    if(a[i] == nxt[pop] || pop == 0) {
                        akt++;
                    }else akt = 1;
                    pop = a[i];
                    res = max(res, akt);
                }
            }
            cout << res << "\n";
        }
    }
}