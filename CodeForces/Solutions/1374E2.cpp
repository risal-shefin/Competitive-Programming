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

vector <pii> alice, bob, both, none;
ll n, m, k;

ll solve(ll take)
{
    if(take + alice.size() < k || take + bob.size() < k)
        return inf;

    ll more = k - take, ret = 0;
    if(take + 2*more > m) return inf;

    for0(i, take) ret += both[i].first;
    for0(i, more) ret += alice[i].first, ret += bob[i].first;

    ll id1 = more, id2 = more, id3 = take, id4 = 0, tot = take + 2*more;
    while(tot < m) {
        ll a = inf, b = inf, bth = inf, non = inf;

        if(id1 < alice.size()) a = alice[id1].first;
        if(id2 < bob.size()) b = bob[id2].first;
        if(id3 < both.size()) bth = both[id3].first;
        if(id4 < none.size()) non = none[id4].first;

        ll mn = min({a, b, bth, non});

        if(bth == mn) ret += bth, tot++, id3++;
        else if(a == mn) ret += a, tot++, id1++;
        else if(b == mn) ret += b, tot++, id2++;
        else ret += non, tot++, id4++;
    }

    return ret;
}

vector <int> ans;
void make_ans(ll take)
{
    ll more = k - take;
    for0(i, take) ans.pb(both[i].second);
    for0(i, more) ans.pb(alice[i].second), ans.pb(bob[i].second);

    ll id1 = more, id2 = more, id3 = take, id4 = 0, tot = take + 2*more;
    while(tot < m) {
        ll a = inf, b = inf, bth = inf, non = inf;

        if(id1 < alice.size()) a = alice[id1].first;
        if(id2 < bob.size()) b = bob[id2].first;
        if(id3 < both.size()) bth = both[id3].first;
        if(id4 < none.size()) non = none[id4].first;

        ll mn = min({a, b, bth, non});

        if(bth == mn) ans.pb(both[id3].second), tot++, id3++;
        else if(a == mn) ans.pb(alice[id1].second), tot++, id1++;
        else if(b == mn) ans.pb(bob[id2].second), tot++, id2++;
        else ans.pb(none[id4].second), tot++, id4++;
    }
}

int main()
{
    cin >> n >> m >> k;

    for1(i, n) {
        ll t, a, b;
        sl(t), sl(a), sl(b);

        if(a == 1 && b == 1) both.pb({t, i});
        else if(a == 1) alice.pb({t, i});
        else if(b == 1) bob.pb({t, i});
        else    none.pb({t, i});
    }

    sort(all(alice)); sort(all(bob)); sort(all(both)); sort(all(none));

    ll lo = 0, hi = min(k, (ll)both.size()), ret = -1, tim = inf;
    while(lo < hi) {
        ll mid = lo + hi >> 1;

        ll got1 = solve(mid), got2 = solve(mid+1);

        if(got1 < got2) {
            hi = mid;
            if(got1 < tim) tim = got1, ret = mid;
        }
        else {
            lo = mid + 1;
            if(got2 < tim) tim = got2, ret = mid+1;
        }
    }

    ll got = solve(lo);
    if(got < tim) tim = got, ret = lo;

    if(ret == -1) pf("-1\n");
    else {
        pf("%lld\n", tim);
        make_ans(ret);

        for(ll i = 0; i < ans.size(); i++) {
            if(i != 0) pf(" ");
            pf("%lld", ans[i]);
        }
        pn;
    }

    return 0;
}