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

const ll sz = 609;
ll dp[sz][sz];

struct node {
    ll dl, dr;
} info[sz];

bool solve(ll opFirst, ll opLast)
{
    if(opFirst > opLast)
        return 1;

    if(opFirst == opLast)
        return info[opFirst].dl == 1;

    ll &ret = dp[opFirst][opLast];
    if(ret != -1)
        return ret;

    ll seqLen = (opLast - opFirst) * 2, rt = 0;
    for(ll d = info[opFirst].dl; d <= info[opFirst].dr; d++) {

        if(d > seqLen + 1)
            break;
        if(d % 2 == 0)
            continue;

        ll opCnt = (d - 1) / 2;

        bool part1 = solve(opFirst + 1, opFirst + opCnt);
        bool part2 = solve(opFirst + opCnt + 1, opLast);

        if(part1 && part2) {
            rt = 1;
            break;
        }
    }

    return ret = rt;
}

void print(ll opFirst, ll opLast)
{
    if(opFirst > opLast)
        return;

    if(opFirst == opLast) {
        pf("()");
        return;
    }

    ll seqLen = (opLast - opFirst) * 2, rt = 0;
    for(ll d = info[opFirst].dl; d <= info[opFirst].dr; d++) {

        if(d > seqLen + 1)
            break;
        if(d % 2 == 0)
            continue;

        ll opCnt = (d - 1) / 2;

        bool part1 = solve(opFirst + 1, opFirst + opCnt);
        bool part2 = solve(opFirst + opCnt + 1, opLast);

        if(part1 && part2) {
            pf("(");
            print(opFirst + 1, opFirst + opCnt);
            pf(")");
            print(opFirst + opCnt + 1, opLast);
            return;
        }
    }
}

int main()
{
    ll n;
    cin >> n;
    for1(i, n)
        sl(info[i].dl), sl(info[i].dr);

    ms(dp, -1);
    bool got = solve(1, n);

    if(!got) {
        cout << "IMPOSSIBLE" << EL;
        return 0;
    }

    print(1, n);
    pn;

    return 0;
}