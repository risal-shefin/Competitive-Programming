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
#define inf (1LL << 60)
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

multiset <int> alice, bob, both;

int main()
{
    ll n, k;
    cin >> n >> k;

    for1(i, n) {
        ll t, a, b;
        sl(t), sl(a), sl(b);

        if(a == 1 && b == 1) both.insert(t);
        else if(a == 1) alice.insert(t);
        else if(b == 1) bob.insert(t);
    }

    if(alice.size() + both.size() < k || bob.size() + both.size() < k) {
        pf("-1\n");
        return 0;
    }

    ll ka = 0, kb = 0, ans = 0;
    while(ka < k || kb < k) {
        ll a = inf, b = inf, bth = inf;

        if(ka < k && !alice.empty()) a = *alice.begin();
        if(kb < k && !bob.empty()) b = *bob.begin();
        if(!both.empty()) bth = *both.begin();

        ll mn = min({a, b, bth});

        if(ka < k && kb < k) {
            if(a+b >= bth) {
                ans += bth;
                assert(both.find(bth) != both.end());
                both.erase(both.find(bth));
            }
            else {
                ans += a + b;
                assert(alice.find(a) != alice.end());
                assert(bob.find(b) != bob.end());

                alice.erase(alice.find(a));
                bob.erase(bob.find(b));
            }
            ka++, kb++;
        }
        else {
            if(bth == mn) {
                ka++, kb++;
                ans += bth;
                both.erase(both.find(bth));
            }
            else if(a == mn) {
                ka++, ans += a;
                alice.erase(alice.find(a));
            }
            else if(b == mn) {
                kb++, ans += b;
                bob.erase(bob.find(b));
            }
        }
    }

    if(ka >= k && kb >= k) pf("%lld\n", ans);

    return 0;
}