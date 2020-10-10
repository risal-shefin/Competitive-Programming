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

const ll sz = 80;
ll dp[sz][sz][sz], n, k, ans[sz], ida;
bool take[sz];

struct info {
    ll a, b, id;
} ara[sz];
const bool operator <(const info &a, const info &b) {
    return a.b < b.b;
}

ll solve(ll pos, ll last, ll taken)
{
    if(pos > n) {
        if(taken < k) return -inf;
        return 0;
    }

    ll &ret = dp[pos][last][taken];
    if(ret != -1)
        return ret;

    if(pos == last) return ret = solve(pos+1, last, taken);

    ll notTakeAdd = k*ara[pos].b, takeAdd = ara[pos].a + taken*ara[pos].b;

    ll rt = notTakeAdd + solve(pos+1, last, taken);
    if(taken < k)
        rt = max(rt, takeAdd + solve(pos+1, last, taken+1));

    return ret = rt;
}

void assign_ans(ll pos, ll last, ll taken, ll sum)
{
    if(pos > n) return;

    ll notTakeAdd = k*ara[pos].b, takeAdd = ara[pos].a + taken*ara[pos].b;
    ll rest1 = sum - notTakeAdd, rest2 = sum - takeAdd;

    if(pos == last || solve(pos+1, last, taken) == rest1) {
        assign_ans(pos+1, last, taken, pos==last? sum : rest1);
        return;
    }

    ans[++ida] = ara[pos].id, take[pos] = 1;
    assign_ans(pos+1, last, taken+1, rest2);
}

int main()
{
    ll t;
    cin >> t;
    while(t--) {
        sl(n), sl(k);
        k--;
        for1(i, n) {
            sl(ara[i].a), sl(ara[i].b);
            ara[i].id = i;
        }
        sort(ara+1, ara+n+1);

        ll last, mx = -inf;
        ms(dp, -1);
        for1(i, n) {
            ll got = solve(1, i, 0) + ara[i].a + k*ara[i].b;
            if(got > mx) {
                mx = got;
                last = i;
            }
        }

        ida = 0;
        ms(take, 0);
        assign_ans(1, last, 0, mx - (ara[last].a + k*ara[last].b) );

        for1(i, n) {
            if(take[i] || last == i) continue;
            ans[++ida] = ara[i].id;
            ans[++ida] = -ara[i].id;
        }
        ans[++ida] = ara[last].id;

        pf("%lld\n", ida);
        for1(i, ida) {
            if(i != 1) pf(" ");
            pf("%lld", ans[i]);
        }
        pn;
    }

    return 0;
}