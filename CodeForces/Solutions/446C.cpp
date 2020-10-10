// #pragma GCC optimize("Ofast,unroll-loops")
// #pragma GCC target("avx,avx2,fma")

#include <bits/stdc++.h>
using namespace std;

#define ll int
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

#define LL long long

const ll sz = 3e5 + 10, block = sqrtl(sz), mod = 1e9 + 9;

ll ara[sz], fib[sz], fibSum[sz], n, m;
ll blockSum[sz/block + 5], now[sz/block + 5], prv[sz/block + 5];

void updFullBlock(ll b)
{
    if(now[b] == 0) return;

    ll f1 = prv[b], f2 = now[b];
    now[b] = prv[b] = 0;

    ll start = b * block, stop = min(n, (b+1)*block-1);

    for(ll i = start; i <= stop; i++) {
        ara[i] += f2;
        if(ara[i] >= mod) ara[i] -= mod;

        blockSum[b] += f2;
        if(blockSum[b] >= mod) blockSum[b] -= mod;

        ll tmp = f2;
        f2 = f1 + f2;
        if(f2 >= mod) f2 -= mod;
        f1 = tmp;
    }
}

void update(ll l, ll r)
{
    ll lb = l / block, rb = r / block;

    updFullBlock(lb), updFullBlock(rb);

    if(lb == rb) {

        for(ll i = l, j = 1; i <= r; i++, j++) {
            ara[i] += fib[j];
            if(ara[i] >= mod) ara[i] -= mod;

            blockSum[lb] += fib[j];
            if(blockSum[lb] >= mod) blockSum[lb] -= mod;
        }

        return;
    }

    for(ll i = l, j = 1; i < (lb+1)*block; i++, j++) {
        ara[i] += fib[j];
        if(ara[i] >= mod) ara[i] -= mod;

        blockSum[lb] += fib[j];
        if(blockSum[lb] >= mod) blockSum[lb] -= mod;
    }

    for(ll i = lb+1; i < rb; i++) {

        ll ptr = i*block - l + 1;

        now[i] += fib[ptr], prv[i] += fib[ptr-1];
        if(now[i] >= mod) now[i] -= mod;
        if(prv[i] >= mod) prv[i] -= mod;
    }

    for(ll i = rb*block, j = i-l+1; i <= r; i++, j++) {
        ara[i] += fib[j];
        if(ara[i] >= mod) ara[i] -= mod;

        blockSum[rb] += fib[j];
        if(blockSum[rb] >= mod) blockSum[rb] -= mod;
    }
}

ll query(ll l, ll r)
{
    ll lb = l / block, rb = r / block, ret = 0;

    updFullBlock(lb), updFullBlock(rb);

    if(lb == rb) {

        for(ll i = l; i <= r; i++) {
            ret += ara[i];
            if(ret >= mod) ret -= mod;
        }

        return ret;
    }

    for(ll i = l; i < (lb+1)*block; i++) {
        ret += ara[i];
        if(ret >= mod) ret -= mod;
    }

    for(ll i = lb+1; i < rb; i++) {

        int ad = ((LL)fibSum[block] * now[i]) % mod;
        ad += ((LL)fibSum[block-1] * prv[i]) % mod;
        if(ad >= mod) ad -= mod;

        ad += blockSum[i];
        if(ad >= mod) ad -= mod;

        ret += ad;
        if(ret >= mod) ret -= mod;
    }

    for(ll i = rb*block; i <= r; i++) {
        ret += ara[i];
        if(ret >= mod) ret -= mod;
    }

    return ret;
}

int main()
{
    fib[0] = 0, fib[1] = 1;
    for(ll i = 2; i < sz; i++) fib[i] = (fib[i-1] + fib[i-2]) % mod;

    for(ll i = 1; i < sz; i++) fibSum[i] = (fibSum[i-1] + fib[i]) % mod;

    cin >> n >> m;

    for0(i, n) {
        si(ara[i]);

        ll b = i / block;
        blockSum[b] += ara[i];
        if(blockSum[b] >= mod) blockSum[b] -= mod;
    }

    while(m--) {

        ll op, l, r;
        scanf("%d %d %d", &op, &l, &r);
        l--, r--;

        if(op == 1) update(l, r);
        else pf("%d\n", query(l, r));
    }

    return 0;
}