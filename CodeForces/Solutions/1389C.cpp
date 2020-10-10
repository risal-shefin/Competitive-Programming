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
#define for1(i, stop) for(ll i = 1; i <= stop; ++i)
#define for0(i, stop) for(ll i = 0; i < stop; ++i)
#define rep1(i, start) for(ll i = start; i >= 1; --i)
#define rep0(i, start) for(ll i = (start-1); i >= 0; --i)
#define ms(n, i) memset(n, i, sizeof(n))
#define casep(n) printf("Case %lld:", ++n)
#define pn printf("\n")
#define pf printf
#define EL '\n'
#define fastio std::ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

const ll sz = 2e5 + 10;
char s[sz];
ll cnt[10];

int main()
{
    ll t;
    cin >> t;
    while(t--) {
        scanf("%s", s+1);

        ll len = strlen(s+1);

        ll mx = 0;
        for1(i, len) {
            ll now = s[i] - '0';
            cnt[now]++;

            mx = max(mx, cnt[now]);
        }

        ll ans = len-mx;

        for(char d1 = '0'; d1 <= '9'; d1++) {
            for(char d2 = '0'; d2 <= '9'; d2++) {

                ll f = 1, exist = 0;

                for(ll i = 1; i <= len; i++) {

                    for(ll j = i; j <= len; j++) {
                        i = j;

                        if(f && s[j] == d1) {
                            exist++;
                            break;
                        }

                        if(!f && s[j] == d2) {
                            exist++;
                            break;
                        }
                    }

                    f ^= 1;
                }

                if(exist & 1) exist--;
                mx = max(mx, exist);
            }
        }

        ans = len - mx;
        pf("%lld\n", ans);

        ms(cnt, 0);
    }

    return 0;
}