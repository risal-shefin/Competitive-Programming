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

const ll sz = 1e5 + 10, ad = 1;

ll a[sz], b[sz];
bool check[5];

int main()
{
    ll t;
    cin >> t;
    while(t--) {
        ll n;
        sl(n);

        for1(i, n)
            sl(a[i]);

        bool chk = 1;
        for1(i, n) {
            sl(b[i]);

            ll d = b[i] - a[i];
            if(d < 0) {
                if(check[-1+ad] == false) chk = 0;
            }
            else if(d > 0) {
                if(check[1+ad] == false) chk = 0;
            }

            check[a[i] + ad] = 1;
        }

        if(!chk)
            pf("NO\n");
        else
            pf("YES\n");

        ms(check, 0);

    }

    return 0;
}