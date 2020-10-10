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

const ll MAXN = 1e6 + 10, sz = 1e5 + 10;

struct node {
    int num;
    bool used;
};
const bool operator <(const node &a, const node &b) {
    if(a.used == b.used)
        return a.num > b.num;

    return a.used > b.used;
}

ll cnt[MAXN], a[sz], b[sz];
set <int> lst;
vector <int> sob;

int main()
{
    ll n;
    cin >> n;
    for1(i, n) {
        sl(a[i]);
        cnt[a[i]]++;
    }

    priority_queue <node> pq;
    sob.resize(MAXN);
    for0(i, MAXN) {
        if(cnt[i] == 0) pq.push({i, 0});
        sob[i] = i;
    }
    lst.insert(all(sob));

    for1(i, n) {
        node u = pq.top();
        pq.pop();

        b[i] = u.num;
        cnt[a[i]]--;

        pq.push({u.num, 1});
        if(cnt[a[i]] == 0)
            pq.push({a[i], 0});
    }

    for1(i, n) {
        auto it = lst.find(b[i]);
        if(it != lst.end())
            lst.erase(it);

        int mex = *lst.begin();

        if(mex != a[i]) {
            pf("-1\n");
            return 0;
        }
    }

    for1(i, n) {
        if(i != 1) pf(" ");
        pf("%d", b[i]);
    }
    pn;

    return 0;
}