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

char s[55], ans[55];
ll b[55], cnt[150];
vector <ll> got;

int main()
{
    ll t;
    cin >> t;
    while(t--) {
        scanf("%s", s+1);
        ll m; sl(m);
        for1(i, m) sl(b[i]);

        for(ll i = 1; s[i] != '\0'; i++) cnt[s[i]]++;

        char now = 'z';
        while(1) {
            for1(i, m) if(b[i] == 0) got.pb(i);
            if(got.empty()) break;

            while(cnt[now] < got.size()) now--;

            for(ll &idx : got) {
                ans[idx] = now;

                for1(i, m) b[i] = b[i]==0? inf : b[i] - abs(i - idx);
            }
            now--;
            got.clear();
        }
        ans[m+1] = 0;
        pf("%s\n", ans+1);

        ms(cnt, 0);
    }

    return 0;
}