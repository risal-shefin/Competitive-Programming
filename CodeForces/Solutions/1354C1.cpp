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

#define pi acos(-1.0)

struct pt {
    double x, y;
};

pt rot(pt p, pt c, double a)
{
    p.x -= c.x, p.y -= c.y;
    pt ret = p;

    ret.x = p.x * cos(a) - p.y*sin(a);
    ret.y = p.x*sin(a) + p.y*cos(a);

    ret.x += c.x, ret.y += c.y;

    return ret;
}

int main()
{
    ll t;
    cin >> t;
    while(t--) {
        ll n;
        sl(n);
        ll v = 2 * n, extra = n/2 - 1;

        double angle = (v-2) * pi / v, ad = 0;

        pt a = {0, 0}, now = {0, 1};

        for1(i, extra) {
            pt tmp = now;
            now = rot(a, now, angle);
            //cout << now.x << " " << now.y << " " << angle << endl;
            a = tmp;
        }
        if(extra > 0) {
            ad = abs(now.y) - 1;
        }

        pf("%0.9f\n", 1 + 2*ad);
    }

    return 0;
}