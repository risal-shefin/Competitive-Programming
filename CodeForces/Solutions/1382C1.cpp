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
char s1[sz], s2[sz];
vector <int> ans;

int main()
{
    ll t;
    cin >> t;
    while(t--) {
        ll n;
        sl(n);

        scanf("%s", s1+1);
        scanf("%s", s2+1);

        ans.reserve(2*n);
        bool rev = 0;

        ll ptr1 = 1, ptr2 = n;

        rep1(i, n) {
            if(!rev) {
                if(s1[ptr1] == s2[i])
                    ans.pb(1);

                ans.pb(i);
                ptr1++;

            }
            else {
                if(s1[ptr2] != s2[i])
                    ans.pb(1);

                ans.pb(i);
                ptr2--;
            }

            rev ^= 1;
        }

        pf("%lld", (ll)ans.size());
        for(int &p : ans) pf(" %d", p);
        pn;

        ans.clear();
    }

    return 0;
}