#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("avx,avx2,fma")

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

const ll sz = 1e5 + 10;
ll pos[sz], cnt[sz];
set <ll> unoc, watch[sz];
multiset <ll> lst;

int main()
{
    ll t;
    cin >> t;
    while(t--) {
        ll n;
        sl(n);

        for1(i, n) {
            ll inp;
            sl(inp);

            pos[inp] = i;

            unoc.insert(i), cnt[i] = 1;
            watch[1].insert(i);
            lst.insert(1);
        }

        bool chk = 1;
        for1(i, n) {
            ll p = pos[i];
            ll mx = *(--lst.end());
            if(watch[mx].find(p) == watch[mx].end()) {
                chk = 0;
                break;
            }


            ll p1 = 1;
            auto it = unoc.find(p);
            if(it != unoc.begin()) {
                auto it2 = it;
                it2--;
                p1 = (*it2) + 1;
            }

            it++;
            if(it != unoc.end()) {
                ll p2 = *it;
                ll d = (p2 - p1 + 1);

                ll ase = cnt[p2];
                lst.erase(lst.find(ase));
                watch[ase].erase(p2);

                ase = d;
                lst.insert(ase);
                watch[ase].insert(p2);
                cnt[p2] = d;
            }

            unoc.erase(p);
            watch[mx].erase(p);
            lst.erase(lst.find(mx));
        }

        if(chk) pf("Yes\n");
        else pf("No\n");

        unoc.clear(), lst.clear();
        for1(i, sz) watch[i].clear();
    }

    return 0;
}