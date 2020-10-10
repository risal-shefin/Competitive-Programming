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

inline pt rot(pt c, pt p, double a)
{
    p.x -= c.x, p.y -= c.y;
    pt ret = p;

    ret.x = p.x * cos(a) - p.y*sin(a);
    ret.y = p.x*sin(a) + p.y*cos(a);

    ret.x += c.x, ret.y += c.y;

    return ret;
}

ll n, v;
double angle;

double solve(pt now, pt b)
{
    double minx = min(b.x, now.x), maxx = max(b.x,now.x), miny = min(b.y,now.y), maxy = max(b.y,now.y);

    for(ll i = 1; i <= v-2; i++) {
        pt tmp = now;
        now = rot(now, b, angle);
        b = tmp;

        minx = min(minx, now.x), maxx = max(maxx, now.x);
        miny = min(miny, now.y), maxy = max(maxy, now.y);
    }

    return max(abs(minx-maxx), abs(miny-maxy));
}

int main()
{
    ll t, cnt;
    cin >> t;
    while(t--) {
        sl(n);
        v = 2*n, angle = (v-2) * pi / v, cnt = 100;

        pt now = {0, 0}, b = {1, 0}, newb;

        double lo = 0, hi = pi - angle, ans = inf;
        while(cnt--) {
            double mid1 = (2*lo + hi) / 3, mid2 = (lo + 2*hi) / 3;

            newb = rot(now, b, mid1);
            double ans1 = solve(now, newb);

            newb = rot(now, b, mid2);
            double ans2 = solve(now, newb);

            if(ans1 < ans2) {
                ans = min(ans, ans1);
                hi = mid2;
            }
            else {
                ans = min(ans, ans2);
                lo = mid1;
            }
        }

        pf("%0.9f\n", ans);
    }

    return 0;
}