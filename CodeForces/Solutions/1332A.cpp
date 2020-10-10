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

int main()
{
    ll t;
    cin >> t;
    while(t--) {
        ll a, b, c, d;
        scanf("%lld %lld %lld %lld", &a, &b, &c, &d);

        ll x,y, x1,y1, x2, y2;
        scanf("%lld %lld %lld %lld %lld %lld", &x, &y, &x1, &y1, &x2, &y2);

        if(abs(x1-x2) == 0 && (a!=0 || b != 0)) {
            pf("No\n");
            continue;
        }
        if(abs(y1-y2) == 0 && (c != 0 || d != 0)) {
            pf("No\n");
            continue;
        }

        ll mns = min(a, b);
        a -= mns;
        b -= mns;

        ll mnu = min(c, d);
        c -= mnu;
        d -= mnu;

        ll fx = x, fy = y;
        fx -= a;
        fx += b;

        fy -= c;
        fy += d;

        if(x1 <= min(x, fx) && max(x, fx) <= x2 && y1 <= min(y, fy) && max(y, fy) <= y2)
            pf("Yes\n");
        else
            pf("No\n");
    }

    return 0;
}