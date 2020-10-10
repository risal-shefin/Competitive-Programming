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
#define inf (1LL << 62)
#define loop(i, start, stop, inc) for(ll i = start; i <= stop; i += inc)
#define for1(i, stop) for(ll i = 1; i <= stop; i++)
#define for0(i, stop) for(ll i = 0; i < stop; i++)
#define rep1(i, start) for(ll i = start; i >= 1; i--)
#define rep0(i, start) for(ll i = (start-1); i >= 0; i--)
#define ms(n, i) memset(n, i, sizeof(n))
#define casep(n) printf("Case %lld:", ++n)
#define pn printf("\n")
#define pf printf
#define fastio std::ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

ll n, m, x[200009], y[200009];
struct node {
    ll d, x;
    bool state;
};
const bool operator <(const node &a, const node &b) {
    if(a.d == b.d) {
        if(a.x==b.x)
            return a.state < b.state;
        return a.x < b.x;
    }
    return a.d < b.d;
}

set <node> st;
deque <node> rmv;

int main()

{
    cin >> n >> m;
    for1(i, n)
        sl(x[i]);

    sort(x+1, x+n+1);
    x[0] = -inf, x[n+1] = inf;

    for1(i, n) {
        ll d = x[i] - x[i-1] - 1;
        d /= 2;
        if(d != 0)
            st.insert({d, x[i], 0});

        d = x[i+1] - x[i] - 1;
        d /= 2;
        if((x[i+1] - x[i] - 1) & 1)
            d++;

        if(d != 0)
            st.insert({d, x[i], 1});
    }

    ll tot = 0, dist = 1, idy = 0;
    while(1) {
        for(node u: st) {

            tot += dist;
            if(u.state == 0)
                y[idy++] = u.x - dist;
            else
                y[idy++] = u.x + dist;

            if(idy >= m)    break;
            if(u.d == dist)
                rmv.pb(u);
        }

        if(idy >= m)    break;

        dist++;
        for(node u: rmv)
            st.erase(u);

        rmv.clear();
    }

    pf("%lld\n", tot);
    for0(i, m) {
        if(i != 0) pf(" ");
        pf("%lld", y[i]);
    }
    pn;

    return 0;
}