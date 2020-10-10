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
 
ll ara[200009], lft[200009], rgt[200009];
 
int main()
 
{
    ll n;
    sl(n);
    forn(i, n)
        sl(ara[i]);
 
    ara[n+1] = inf;
    ll ans = 1, last = 1;
    forn(i, n) {
        if(ara[i-1] < ara[i]) {
            lft[i] = last;
            ans = max(ans, i - last + 1);
        }
        else {
            lft[i] = i;
            last = i;
        }
    }
 
    last = n;
    for(ll i = n; i >= 1; i--) {
        if(ara[i] < ara[i+1]) {
            rgt[i] = last;
            ans = max(ans, last - i + 1);
        }
        else {
            rgt[i] = i;
            last = i;
        }
    }
 
    forn(i, n) {
        ll l, r;
        if(ara[i - 1] >= ara[i+1])
            continue;
 
        if(i == 1)
            l = 0;
        else
            l = (i-1) - lft[i-1] + 1;
 
        if(i == n)
            r = 0;
        else
            r = rgt[i+1] - (i+1) + 1;
 
        ans = max(ans, l + r);
    }
 
    cout << ans << endl;
 
    return 0;
}