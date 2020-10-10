// #pragma GCC optimize("Ofast,unroll-loops")
// #pragma GCC target("avx,avx2,fma")

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long
#define dd double
#define ld long double
#define sl(n) scanf("%lld", &n)
#define si(n) scanf("%d", &n)
#define sd(n) scanf("%lf", &n)
#define pll pair <ll, ll>
#define pii pair <int, int>
#define mp make_pair
#define pb push_back
#define all(v) v.begin(), v.end()
#define inf (1LL << 62)
#define loop(i, start, stop, inc) for(ll i = start; i <= stop; i += inc)
#define for1(i, stop) for(ll i = 1; i <= stop; ++i)
#define for0(i, stop) for(ll i = 0; i < stop; ++i)
#define rep1(i, start) for(ll i = start; i >= 1; --i)
#define rep0(i, start) for(ll i = (start-1); i >= 0; --i)
#define ms(n, i) memset(n, i, sizeof(n))
#define casep(n) printf("Case %lld:", ++n)
#define pn printf("\n")
#define pf printf
#define EL '\n'
#define fastio std::ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

struct node {
    int food, diff;
};
const bool operator <(const node &a, const node &b) {
    if(a.diff != b.diff)
        return a.diff > b.diff;
    return a.food > b.food;
}

const ll sz = 2e5 + 10;
ll w[sz], x[sz], y[sz];

unordered_set <int> frnd[sz];
set <node> lst;
vector <int> ans;

int main()
{
    ll n, m;
    cin >> n >> m;
    for1(i, n) sl(w[i]);

    for1(i, m) {
        sl(x[i]), sl(y[i]);
        frnd[ x[i] ].insert(i);
        frnd[ y[i] ].insert(i);
    }

    for1(i, n) lst.insert({i, w[i] - frnd[i].size()});

    bool ok = 1;
    while(!lst.empty()) {
        if(lst.begin()->diff < 0) {
            ok = 0;
            break;
        }

        node info = *lst.begin();
        lst.erase(lst.begin());

        for(const int &f : frnd[info.food]) {
            ll other;
            if(x[f] != info.food) other = x[f];
            else other = y[f];

            lst.erase({other, w[other] - frnd[other].size()});
            frnd[other].erase(f);
            lst.insert({other, w[other] - frnd[other].size()});

            ans.pb(f);
        }
    }

    if(!ok) {
        cout << "DEAD" << EL;
        return 0;
    }

    cout << "ALIVE" << EL;
    reverse(all(ans));
    for(ll i = 0; i < ans.size(); i++) {
        if(i != 0) pf(" ");
        pf("%d", ans[i]);
    }
    pn;

    return 0;
}