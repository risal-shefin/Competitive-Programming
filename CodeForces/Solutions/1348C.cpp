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

const ll sz = 1e5 + 10;

string s, tmp[sz];
ll cnt[30];

int main()
{
    fastio;
    ll t;
    cin >> t;
    while(t--) {
        ll n, k;
        cin >> n >> k;
        cin >> s;

        for1(i, k) tmp[i] = "";

        ll last = 0, f = inf;
        for(char ch : s) {
            ll now = ch - 'a';
            cnt[now]++;

            last = max(last, now);
            f = min(f, now);
        }

        ll ptr1 = f, chk = 1;
        for1(i, k) {
            while(cnt[ptr1] == 0) ptr1++;

            tmp[i] = (ptr1 + 'a');
            cnt[ptr1]--;
            if(ptr1 != f) chk = 0;
        }

        ll chk2 = 1;
        for(ll i = 0; i < last; i++) {
            while(cnt[i] != 0) {
                tmp[1].pb(i + 'a');
                cnt[i]--;
                chk2 = 0;
            }
        }

        ll mxLen = tmp[1].length();
        ll ptr = 1;
        for(ll i = 1; i <= cnt[last]; i++) {
            tmp[ptr].pb(last + 'a');

            if(ptr == k) {
                ptr = 1;
                continue;
            }

            if(chk && chk2)
                ptr++;
        }

        string ans = tmp[1];
        for1(i, k) ans = max(ans, tmp[i]);

        cout << ans << EL;

        ms(cnt, 0);
    }

    return 0;
}