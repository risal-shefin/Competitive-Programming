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
#define inf (1LL << 61)
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

ll diff[sz], mxSuf[sz];

int main()
{
    scanf("%s", s+1);

    ll len = strlen(s+1);

    ll v = 0, c = 0, ans = 0, g = 0;

    for1(i, len) {
        char ch = tolower(s[i]);

        if(ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u')
            v++;
        else
            c++;

        diff[i] = 2*c - v;
    }

    mxSuf[len] = diff[len];
    rep1(i, len-1) mxSuf[i] = max(mxSuf[i+1], diff[i]);

    for1(i, len) {

        ll lo = i, hi = len, ret = -1, prv = diff[i-1];

        while(lo <= hi) {
            ll mid = lo+hi >> 1;

            if(mxSuf[mid] - prv >= 0) {
                ret = mid;
                lo = mid+1;
            }
            else
                hi = mid-1;
        }

        if(ret != -1) {
            if(ret-i+1 > ans) {
                ans = ret-i+1;
                g = 1;
            }
            else if(ret-i+1 == ans)
                g++;
        }
    }

    if(ans == 0) cout << "No solution" << EL;
    else cout << ans << " " << g << EL;

    return 0;
}