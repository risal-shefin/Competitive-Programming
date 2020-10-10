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

ll a, b, c, d;

void imp() {
    pf("NO\n");
    exit(0);
}

deque <ll> ans1, ans2, ans3;

int main()

{
    cin >> a >> b >> c >> d;

    if(a == 1 && b+c+d == 0) {
        pf("YES\n");
        pf("0\n");
        return 0;
    }
    if(b == 1 && a+c+d == 0) {
        pf("YES\n");
        pf("1\n");
        return 0;
    }
    if(c == 1 && a+b+d == 0) {
        pf("YES\n");
        pf("2\n");
        return 0;
    }
    if(d == 1 && a+b+c == 0) {
        pf("YES\n");
        pf("3\n");
        return 0;
    }

    if(a > b+1)
        imp();
    if(a > b && c+d != 0)
        imp();

    if(d > c+1)
        imp();
    if(d > c && a+b != 0)
        imp();

    if(a > 0) {
        ans1.pb(0);
        b = b - (a - 1);
        forn(i, (a-1))
            ans1.pb(1), ans1.pb(0);

        if(c+d != 0)
            b--, ans1.pb(1);
    }

    if(d > 0) {
        ans3.push_front(3);
        c = c - (d - 1);
        forn(i, (d-1))
            ans3.push_front(2), ans3.push_front(3);
        if(a+b != 0)
            c--, ans3.push_front(2);
    }

    ll mn = min(b, c);
    b -= mn;
    c -= mn;
    forn(i, mn)
        ans2.pb(2), ans2.pb(1);

    if(b > 0 && a > 0) b--, ans1.push_front(1);
    if(c > 0 && d > 0) c--, ans3.push_back(2);

    if(b != 0 || c != 0)
        imp();

    pf("YES\n");
    bool flag = 0;
    for(ll i = 0; i < ans1.size(); i++) {
        if(flag)
            pf(" ");
        pf("%lld", ans1[i]);
        flag = 1;
    }
    for(ll i = 0; i < ans2.size(); i++) {
        if(flag)
            pf(" ");
        pf("%lld", ans2[i]);
        flag = 1;
    }
    for(ll i = 0; i < ans3.size(); i++) {
        if(flag)
            pf(" ");
        pf("%lld", ans3[i]);
        flag = 1;
    }
    pn;

    return 0;
}