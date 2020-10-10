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

ll cnt[60], pw[60];
const ll stop = 1e16;

int main()
{
    ll t;
    cin >> t;
    while(t--) {
        ms(cnt, 0);
        ll n, k, mx = 0;
        sl(n), sl(k);

        pw[0] = 1;
        for(ll i = 1; ;i++) {
            if(pw[i-1]*k > stop)
                break;

            mx = i;
            pw[i] = pw[i-1] * k;
        }

        bool chk = 1;
        for1(i, n) {
            ll inp;
            sl(inp);

            for(ll j = mx; j >= 0; j--) {
                if(inp < pw[j]) continue;
                inp -= pw[j];
                cnt[j]++;
            }
            if(inp != 0) chk = 0;
        }
        for0(j, 60) {
            if(cnt[j] > 1) {
                chk = 0;
                break;
            }
        }

        if(chk)
            pf("YES\n");
        else
            pf("NO\n");
    }
    return 0;
}