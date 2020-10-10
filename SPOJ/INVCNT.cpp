#include <bits/stdc++.h>
using namespace std;

#define siz 200009
#define ll int

vector <ll> tree[3 * siz];
ll ara[siz];
long long cnt = 0;

void build(ll lo, ll hi, ll node)

{
    if(lo == hi) {
        tree[node].push_back( ara[lo] );
        return;
    }

    ll mid = (lo + hi) / 2;

    build(lo, mid, 2 * node);
    build(mid + 1, hi, 2 * node + 1);

    merge(tree[2 * node].begin(), tree[2 * node].end(),
          tree[2 * node + 1].begin(), tree[2 * node + 1].end(),
          back_inserter(tree[node]) );

    for(ll i = 0; i < tree[2 * node + 1].size(); i++) {
        ll indx = upper_bound(tree[2 * node].begin(), tree[2 * node].end(), tree[2 * node + 1][i] ) - tree[2 * node].begin();
        //cout << indx << "  " << tree[2 * node][i] << endl;
        cnt += (tree[2 * node].size() - indx);
    }
}

int main()

{
    ll t;
    cin >> t;
    while(t--) {
        cnt = 0;
        ll n, in;
        scanf("%d", &n);

        for(ll i = 1; i <= n; i++) {
            scanf("%d", &ara[i]);
        }

        build(1, n, 1);

        printf("%lld\n", cnt);
        for(ll i = 0; i < 3 * siz; i++)
            tree[i].clear();
    }
    return 0;
}
