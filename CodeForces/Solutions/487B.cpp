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
multiset <ll> lst;
ll ara[sz], lvl[sz];

int main()
{
    ll n, s, l;
    cin >> n >> s >> l;

    for1(i, n) sl(ara[i]);

    ms(lvl, -1);
    lvl[n+1] = 0;
    ll ptr = n;
    lst.insert(ara[ptr]);

    for(ll i = n; i >= 1; i--) {
        while(ptr > i) {
            lst.insert(ara[--ptr]);
        }

        if(lvl[i+1] == -1) {
            lst.erase(lst.find(ara[i]));
            continue;
        }

        ll mn = *lst.begin(), mx = *lst.rbegin();
        if(mx-mn > s) {
            lst.erase(lst.find(ara[i]));
            continue;
        }

        if(i-ptr+1 >= l && lvl[ptr] == -1) lvl[ptr] = lvl[i+1] + 1;

        while(ptr > 1) {
            lst.insert(ara[--ptr]);
            mn = *lst.begin(), mx = *lst.rbegin();
            if(mx-mn > s) break;

            if(i-ptr+1 >= l) lvl[ptr] = lvl[i+1] + 1;
            //cout << i << " " << ptr << endl;
        }

        lst.erase(lst.find(ara[i]));
    }

    cout << lvl[1] << endl;

    return 0;
}