#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
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

struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        // http://xorshift.di.unimi.it/splitmix64.c
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};

ll n, m, x[200009], y[200009];
queue <pll> q;
gp_hash_table <int, bool, custom_hash> vis;

ll dx[] = {1, -1};

int main()

{
    cin >> n >> m;
    for1(i, n) {
        sl(x[i]);
        q.push(mp(x[i],0));
        vis[x[i]] = 1;
    }

    ll idy = 0, tot=0;
    while(idy < m) {
        pll u = q.front();
        q.pop();

        for0(i, 2) {
            ll nxt = u.first + dx[i];
            if(vis.find(nxt) != vis.end())
                continue;

            vis[nxt] = 1;
            y[idy++] = nxt;
            tot += (u.second + 1);
            q.push(mp(nxt, u.second + 1));

            if(idy >= m) break;
        }
    }

    pf("%lld\n", tot);
    for0(i, m) {
        if(i != 0) pf(" ");
        pf("%lld", y[i]);
    }
    pn;

    return 0;
}