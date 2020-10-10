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
#define EL '\n'
#define fastio std::ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

const ll sz = 1e4 + 10;
bool vis[sz][1009];

ll land[sz];

struct node {
    ll pos, tim, tot;
};

int main()
{
    ll n, m;
    cin >> n >> m;

    for1(i, m) sl(land[i]);
    sort(land + 1, land + m+1);

    ll g, r;
    cin >> g >> r;

    ll f = land[1];
    if(f > g) {
        //cout << g << " " << f << endl;
        cout << -1 << endl;
        return 0;
    }

    deque <node> q;
    q.push_front({1, f, f});
    vis[1][f] = 1;

    ll ans = inf;
    while(!q.empty()) {
        node u = q.front();
        q.pop_front();

        //cout << u.pos << " " << u.tim << endl;
        if(land[u.pos] == n) {
            ans = min(ans, u.tot);
            continue;
        }

        ll baki = g - u.tim;
        if(baki == 0) {
            u.tot += r, u.tim = 0;
            if(!vis[u.pos][u.tim]) {
                vis[u.pos][u.tim] = 1;
                q.pb({u.pos, u.tim, u.tot});
            }
            continue;
        }
        ll lagbe = n - land[u.pos];
        if(lagbe <= baki) {
            ans = min(ans, u.tot + lagbe);
        }

        ll lft = u.pos - 1, rgt = u.pos + 1;

        if(lft >= 1) {
            ll rest = g - u.tim;
            ll need = abs(land[u.pos] - land[lft]);
            if(need <= rest) {
                ll now = u.tim + need;
                ll tot = u.tot + need;

                if(!vis[lft][now]) {
                    vis[lft][now] = 1;
                    q.push_front({lft, now, tot});
                }
            }
        }
        if(rgt <= n) {

            ll rest = g - u.tim;
            ll need = abs(land[u.pos] - land[rgt]);
            if(need <= rest) {
                ll now = u.tim + need;
                ll tot = u.tot + need;

                if(!vis[rgt][now]) {
                    vis[rgt][now] = 1;
                    q.push_front({rgt, now, tot});
                }
            }
        }
    }

    if(ans == inf)
        cout << -1 << endl;
    else
        cout << ans << endl;

    return 0;
}