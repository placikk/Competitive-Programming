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
const int mxN = 1507;
bitset<mxN> baza[mxN];
bitset<mxN> ktore[mxN];

int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n,k; cin >> n >> k;
    bitset<mxN> akt, sub;
    string s;

    bitset<mxN> res;

    rep(i,1,n){
        cin >> s;
        rep(j,0,k-1) if(s[j] == '1') akt[j+1] = 1; 
        
        sub[i] = 1;
        rep(j,1,k) if(akt[j]){
            if(baza[j][j]){
                sub ^= ktore[j];
                akt ^= baza[j];
            }else{
                baza[j] = akt;
                ktore[j] = sub;
                break;
            }
        }
        if(akt.count() == 0){
            if(sub.count()%2 == 0) res = sub;
            else res ^= sub;
            if(res.count()%2 == 0){
                int c = res.count()/2;
                int ile = 0;
                rep(j,1,n){
                    if(!res[j]) cout << 0;
                    else{
                        if(ile < c) cout << 1;
                        else cout << 2;
                        ile++;
                    }
                }
                cout << "\n";
                return 0;
            }
        }

        sub.reset();
        akt.reset();
    }
    cout << "*\n";
}