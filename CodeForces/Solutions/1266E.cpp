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
#define forn(i, stop) for(ll i = 1; i <= stop; i++)
#define rep(i, start) for(ll i = start; i >= 1; i--)
#define ms(n, i) memset(n, i, sizeof(n))
#define casep(n) printf("Case %lld:", ++n)
#define pn printf("\n")
#define pf printf
#define fastio std::ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

ll ara[200009], fre[200009];
unordered_map <ll, ll> check[200009];

int main()

{
    ll n, tim = 0;
    sl(n);
    forn(i, n) {
        sl(ara[i]);
        tim += ara[i];
    }

    ll q;
    sl(q);
    while(q--) {
        ll s, t, u;
        sl(s), sl(t), sl(u);

        auto it = check[s].find(t);
        if(it != check[s].end()) {

            if(fre[ it -> second ] <= ara[ it->second ])
                tim++;

            fre[ it -> second ]--;
            check[s].erase(it);
        }

        if(u != 0) {
            check[s][t] = u;
            fre[u]++;
            if(fre[u] <= ara[u])
                tim--;
        }

        pf("%lld\n", tim);
    }

    return 0;
}