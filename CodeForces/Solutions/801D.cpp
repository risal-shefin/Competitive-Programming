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
#define forn(i, stop) for(ll i = 1; i <= stop; i++)
#define rep(i, start) for(ll i = start; i >= 1; i--)
#define ms(n, i) memset(n, i, sizeof(n))
#define casep(n) printf("Case %lld:", ++n)
#define pn printf("\n")
#define pf printf
#define fastio std::ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

#define x first
#define y second
#define pld pair <ld, ld>

pll point[1009];

ld dot(pll a, pll b) {return a.x*b.x + a.y*b.y;}
ld norm_sq(pll a) { return a.x*a.x + a.y*a.y;}

pll toVec(pll a, pll b) {
    return mp(b.x-a.x, b.y-a.y);
}

pld scale(pll a, ld s) {
    return mp(a.x*s, a.y*s);
}

pld translate(pll p, pld v) {
    return mp(p.x+v.x, p.y+v.y);
}

ld dist(pll a, pld b) {
    return sqrtl((a.x-b.x)*(a.x-b.x) + (a.y-b.y)*(a.y-b.y));
}

ld distToLine(pll p, pll a, pll b) {
    pll ap = toVec(a, p), ab = toVec(a, b);
    ld u = dot(ap, ab) / norm_sq(ab);
    pld c = translate(a, scale(ab, u));

    return dist(p, c);
}

int main()

{
    ll n;
    sl(n);
    forn(i, n) {
        sl(point[i].x), sl(point[i].y);
    }

    ld ans = inf;
    forn(i, n) {
        ll l = i, m = i+1, r = i+2;
        if(m > n)
            m -= n;
        if(r > n)
            r -= n;

        ans = min(ans, distToLine(point[m], point[l], point[r])/2);
    }

    cout << setprecision(9) << fixed << ans << endl;

    return 0;
}