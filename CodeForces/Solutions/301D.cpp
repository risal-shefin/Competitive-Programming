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

const int sz = 2e5 + 10;
int ara[sz], pos[sz], ans[sz], BITree[sz];
vector <int> dv[sz], lft[sz];

struct node {
    int l, index;
};
vector <node> qry[sz];

int getSum(int index)
{
    int sum = 0;
    while (index>0) {
        sum += BITree[index];
        index -= index & (-index);
    }
    return sum;
}

void updateBIT(int n, int index) {
    while (index <= n)
    {
       ++BITree[index];
       index += index & (-index);
    }
}

int main()
{
    for(int i = 1; i < sz; i++) {
        for(ll j = i; j < sz; j += i)
            dv[j].pb(i);
    }

    int n, q;
    cin >> n >> q;
    for1(i, n) {
        si(ara[i]);
        pos[ ara[i] ] = i;
    }

    for(int i = 1; i <= n; i++)
        for(int &num : dv[ ara[i] ]) lft[max(pos[num], i)].pb(min(pos[num], i));

    int l, r;
    for1(i, q) {
        si(l), si(r);
        qry[r].pb({l, i});
    }

    for1(i, n) {
        for(int &idx : lft[i]) updateBIT(n, idx);

        for(node &qr : qry[i]) ans[qr.index] = getSum(n) - getSum(qr.l-1);
    }

    for1(i, q) pf("%d\n", ans[i]);

    return 0;
}