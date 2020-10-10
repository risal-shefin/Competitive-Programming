#include <bits/stdc++.h>
using namespace std;

#define ll int
#define pll pair <ll, ll>
#define inf 1000000000
long long ans = 0;

set <ll> lst;
set <ll> ::iterator it;
ll ara[1000009];

pll BIT[1000009];

pll getRes(ll index)
{
    pll ret = make_pair(inf, -inf); // Iniialize result

    // Traverse ancestors of BITree[index]
    while (index>0)
    {
        ret.first = min(ret.first, BIT[index].first);
        ret.second = max(ret.second, BIT[index].second);

        // Move index to parent node in getRes View
        index -= index & (-index);
    }
    return ret;
}

void updateBIT(ll index, pll val)

{
    // Traverse all ancestors
    while (index <= 1000000)
    {
        BIT[index].first = min(BIT[index].first, val.first);
        BIT[index].second = max(BIT[index].second, val.second);

       // Update index to that of parent in update View
       index += index & (-index);
    }
}

int main()

{
    ll n, x;
    scanf("%d %d", &n, &x);

    for(ll i = 0; i <= 1000000; i++) {
        BIT[i].first = inf;
        BIT[i].second = -inf;
    }


    ll last = 0;
    for(ll i = 1; i <= n; i++) {
        scanf("%d", &ara[i]);
        lst.insert(ara[i]);

        it = lst.upper_bound(ara[i]);
        if(it != lst.end()) {
            last = max(last, ara[i]);

            updateBIT(ara[i], make_pair(*it, *(--lst.end()) ) );
        }
    }

    ll minboro, maxboro, range;
    pll p;
    for(ll i = 1; i <= x; i++) {
        p = getRes(i - 1);
        //cout << i << "  " << minboro << endl;
        minboro = p.first;
        if(minboro < i)
            break;

        maxboro = p.second;
        range = max(maxboro, last);
        range = max(range, i);

        ans += (long long)(x - range + 1);
    }

    printf("%lld\n", ans);

    return 0;
}