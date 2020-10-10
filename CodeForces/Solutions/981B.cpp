#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define inf 1e18

struct node {
    ll id;
    ll val;
}ara[200009];

bool cmp(node a, node b)

{
    return a.val > b.val;
}

int main()

{
    ll n, indx = 0;
    cin >> n;
    for(ll i = 0; i < n; i++) {
        scanf("%lld %lld", &ara[indx].id, &ara[indx].val);
        indx++;
    }
    ll m;
    cin >> m;
    for(ll i = 0; i < m; i++) {
        scanf("%lld %lld", &ara[indx].id, &ara[indx].val);
        indx++;
    }

    map <ll, bool> mark;
    ll ans = 0;
    sort(ara, ara + indx, cmp);

    for(ll i = 0; i < indx; i++) {
        if(mark[ ara[i].id] == 0) {
            mark[ ara[i].id ] = 1;
            ans += ara[i].val;
        }

    }

    cout << ans << endl;
    return 0;
}