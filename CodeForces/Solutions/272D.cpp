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

const ll sz = 1e5 + 10;
pll ara[2*sz];

int main()
{
    ll n, m, ans = 1;
    sl(n);

    for1(i, n) sl(ara[i].first), ara[i].second = i;

    for(ll i = n+1; i <= 2*n; i++) sl(ara[i].first), ara[i].second = i-n;

    sl(m);

    sort(ara+1, ara+2*n+1);

    for1(i, 2*n) {

        ll start = i, stop = i, same = 0;
        pll prv = ara[i];

        for(ll j = i+1; j <= 2*n; j++) {

            if(ara[j].first != ara[i].first)
                break;

            if(ara[j] == prv) same++;
            else prv = ara[j];

            stop = j;
        }

        ll fact = 1;
        for(ll k = 1, j = start; j <= stop; k++, j++) {

            if(same == 0) {
                fact = (fact * k) % m;
                continue;
            }

            if(k % 2 == 0) fact = (fact * (k/2)) % m, same--;
            else fact = (fact * k) % m;
        }

        ans = (ans * fact) % m;

        i = stop;
    }

    cout << ans << EL;

    return 0;
}