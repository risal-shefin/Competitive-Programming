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

const ll sz = 1e5 + 10;
char s[sz], s2[sz];

int main()
{
    ll t;
    cin >> t;
    while(t--) {
        ll n;
        sl(n);

        scanf("%s", s+1);
        scanf("%s", s2+1);

        ll cnt = 0;
        for(char ch = 'a'; ch <= 'z'; ch++) {

            char need = 123;
            for1(i, n) {
                if(s[i] != ch)
                    continue;

                if(s2[i] == s[i])
                    continue;

                if(s2[i] < s[i]) {
                    cnt = -1;
                    break;
                }

                need = min(need, s2[i]);
            }

            if(cnt == -1) break;
            if(need == 123) continue;

            cnt++;
            for1(i, n) {
                if(s[i] != ch)
                    continue;

                if(s2[i] == s[i])
                    continue;

                s[i] = need;
            }
        }

        pf("%lld\n", cnt);
    }

    return 0;
}