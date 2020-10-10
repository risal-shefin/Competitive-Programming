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

vector <pll> pos;
ll last = 3e16;
bool vis[100];

int main()

{
    ll x0, y0, ax, ay, bx, by;
    sl(x0), sl(y0), sl(ax), sl(ay), sl(bx), sl(by);

    ll xs, ys, t;
    sl(xs), sl(ys), sl(t);

    pos.pb(pll(x0, y0));
    ll xi = x0, yi = y0;
    while(1) {
        xi = ax * xi + bx;
        yi = ay * yi + by;

        if(xi >= last || yi >= last)
            break;

        pos.pb(mp(xi, yi));
    }

    ll ans = 0, nx = xs, ny = ys, rest;

    for(ll j = 0; j < pos.size(); j++) {

        memset(vis, 0, sizeof(vis));
        rest = t;
        ll cc = abs(pos[j].first - xs) + abs(pos[j].second - ys);
        if(cc > rest)
            continue;

        rest -= cc;
        vis[j] = 1;
        nx = pos[j].first, ny = pos[j].second;
        ll cnt = 1;

        while(1) {
            ll c = inf, idx = -1;
            for(ll i = 0; i < pos.size(); i++) {
                if(vis[i])
                    continue;

                ll tmp = abs(pos[i].first - nx) + abs(pos[i].second - ny);
                if(tmp < c) {
                    c = tmp;
                    idx = i;
                }
            }
            if(idx == -1 || c > rest)
                break;

            cnt++;
            rest -= c;
            nx = pos[idx].first, ny = pos[idx].second;
            vis[idx] = 1;

            if(rest == 0)
                break;
        }

        ans = max(ans, cnt);
    }

    cout << ans << endl;

    return 0;
}