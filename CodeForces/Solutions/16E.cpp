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

const ll sz = 18;

double dp[sz][(1<<sz)], mat[sz][sz], eaten[(1<<sz)][sz];
bool check[sz][(1<<sz)];
ll n;

double solve(ll fish, ll msk)
{
    if(msk == (1<<n)-1)
        return 1;

    double &ret = dp[fish][msk];
    bool &exist = check[fish][msk];

    if(exist)
        return ret;

    ll tot = 1;
    for0(i, n) {
        if((msk >> i) & 1)
            continue;

        tot++;
    }

    ll opt = (tot*(tot-1)) / 2;

    ret = 0, exist = 1;
    for0(i, n) {
        if((msk >> i) & 1)
            continue;

        ret += (double)1/opt * mat[fish][i] * solve(fish, msk|(1<<i));
        ret += (double)1/opt * eaten[msk][i] * solve(fish, msk|(1<<i));
    }

    return ret;
}

int main()
{
    cin >> n;
    for0(i, n)
        for0(j, n)
            sd(mat[i][j]);


    ll lim = 1 << n;
    for0(msk, lim) {

        for0(i, n) {
            if((msk>> i) & 1)
                continue;

            eaten[msk][i] = 0;

            for0(j, n) {
                if((msk >> j) & 1)
                    continue;

                eaten[msk][i] += mat[j][i];
            }
        }
    }

    for0(i, n) {
        if(i != 0) pf(" ");

        ms(check, 0);
        pf("%0.6f", solve(i, 1<<i));
    }
    pn;

    return 0;
}