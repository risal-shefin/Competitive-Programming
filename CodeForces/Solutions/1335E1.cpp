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

const ll sz = 2e5 + 10;
int ara[sz], cnt[205], tmp[205];

int main()
{
    ll t;
    cin >> t;
    while(t--) {
        ms(cnt, 0);

        int n, ans = 1;
        si(n);
        for1(i, n) {
            si(ara[i]);
            cnt[ ara[i] ]++;
            ans = max(ans, cnt[ ara[i] ]);
        }

        for1(i, 200) {
            memcpy(tmp, cnt, sizeof(cnt));

            int ptr1 = 1, ptr2 = n, len = 0;
            while(ptr1 < ptr2) {

                ll v1 = ara[ptr1], v2 = ara[ptr2];

                if(v1 != i && v2 != i)  {
                    tmp[v1]--, tmp[v2]--;
                    ptr1++, ptr2--;
                }
                else if(v2 != i) {
                    tmp[v2]--;
                    ptr2--;
                }
                else if(v1 != i) {
                    tmp[v1]--;
                    ptr1++;
                }
                else {
                    len += 2;
                    int mx = 0;
                    for1(j, 200) if(j != i) mx = max(mx, tmp[j]);
                    ans = max(ans, len + mx);

                    ptr1++, ptr2--;
                }
            }
        }

        pf("%d\n", ans);
    }

    return 0;
}