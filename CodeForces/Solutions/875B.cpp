#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("avx,avx2,fma")

#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;

template <typename T>  using orderedSet =
	tree<T, null_type, less<T>,   /// greater<T> for sorting decreasingly
	rb_tree_tag, tree_order_statistics_node_update>;


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

orderedSet <ll> z, x;

int main()
{
    ll n;
    cin >> n;
    for1(i, n) z.insert(i);

    pf("1");
    for1(i, n) {
        ll pos;
        sl(pos);

        z.erase(pos);
        x.insert(pos);

        if(z.empty())
            pf(" 1");
        else {
            ll last = *(--z.end());

            auto it = x.lower_bound(last);
            ll ase = x.order_of_key(*it);

            pf(" %lld", ase+1);
        }
    }
    pn;

    return 0;
}