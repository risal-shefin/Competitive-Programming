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

const ll sz = 2e5 + 10;
bool check1[sz], check2[sz];
bool valid1[sz], valid2[sz];
ll ara[sz];
vector <pll> ans;

int main()
{
    ll t;
    cin >> t;
    while(t--) {
        ll n;
        sl(n);

        for1(i, n)
            sl(ara[i]);

        ll mx = 0;
        for(ll i = 1; i <= n; i++) {
            ll now = ara[i];
            if(check1[now])
                break;

            check1[now] = 1;
            mx = max(mx, now);

            if(i == mx)
                valid1[i] = 1;
        }

        mx = 0;
        for(ll i = n; i >= 1; i--) {
            ll now = ara[i];
            if(check2[now])
                break;

            check2[now] = 1;
            mx = max(mx, now);

            ll ase = n-i+1;
            if(ase == mx)
                valid2[i] = 1;
        }

        for(ll i = 1; i < n; i++) {
            if(valid1[i] && valid2[i+1])
                ans.pb(mp(i, n-i));
        }

        pf("%lld\n", (ll)ans.size());
        for(pll p : ans)
            pf("%lld %lld\n", p.first, p.second);

        ans.clear();

        for1(i, n) {
            check1[i] = check2[i] = valid1[i] = valid2[i] = 0;
        }
    }

    return 0;
}