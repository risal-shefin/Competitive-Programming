#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define all(v) v.begin(), v.end()
ll ara[1100000], ans[25], revans[25];
vector <ll> tree[3145780];
bool state[25];
void build(ll lo, ll hi, ll node, ll level)
{
    if(lo == hi) {
        tree[node].push_back(ara[lo]);
        return;
    }
    ll mid = (lo + hi) / 2;
    build(lo, mid, 2 * node, level + 1);
    build(mid + 1, hi, 2 * node + 1, level + 1);
    merge(all(tree[2 * node]), all(tree[2 * node + 1]), back_inserter(tree[node]) );
    for(ll i = 0; i < tree[2 * node].size(); i++) {
        ll pos = lower_bound( all(tree[2 * node + 1]), tree[2 * node][i]) - tree[2 * node + 1].begin();
        ans[level] += pos;
    }
    for(ll i = 0; i < tree[2 * node + 1].size(); i++) {
        ll pos = lower_bound( all(tree[2 * node]), tree[2 * node + 1][i]) - tree[2 * node].begin();
        revans[level] += pos;
    }
}
int main()
{
    ll n, siz, in, level, res = 0;
    scanf("%lld", &n);
    siz = (1 << n);
    for(ll i = 1; i <= siz; i++)
        scanf("%lld", &ara[i]);
    build(1, siz, 1, 0);
    ll q;
    scanf("%lld", &q);
    //cout << ans[0] << endl;
    while(q--) {
        res = 0;
        scanf("%lld", &in);
        level = n - in;
        for(ll i = level; i <= n; i++)
            state[i] ^= 1;
        for(ll i = 0; i <= n; i++) {
            if(!state[i])
                res += ans[i];
            else
                res += revans[i];
        }
        printf("%lld\n", res);
    }
    return 0;
}
