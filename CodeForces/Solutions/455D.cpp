#include <bits/stdc++.h>
using namespace std;

#define ll int
#define block 320
deque <ll> v[block + 5];
ll cnt[block + 5][100005];

void update(ll l, ll r)

{
    ll leftBlock = l / block;
    ll rightBlock = r / block;

    ll rightPos = r % block, leftPos = l % block;
    ll num = v[rightBlock][rightPos];

    cnt[rightBlock][num]--;
    v[rightBlock].erase(v[rightBlock].begin() + rightPos);

    cnt[leftBlock][num]++;
    v[leftBlock].insert(v[leftBlock].begin() + leftPos, num);

    for(ll i = leftBlock + 1; i <= rightBlock; i++) {
        num = v[i - 1].back();
        cnt[i - 1][num]--;
        v[i - 1].pop_back();

        cnt[i][num]++;
        v[i].push_front(num);
    }
}

ll query(ll l, ll r, ll k)

{
    ll leftBlock = l / block;
    ll rightBlock = r / block;

    ll leftPos = l % block, rightPos = r % block;
    ll ret = 0;

    if(leftBlock == rightBlock) {
        for(ll i = leftPos; i <= rightPos; i++)
            if(v[leftBlock][i] == k)
                ret++;
        return ret;
    }

    for(ll i = leftPos; i < v[leftBlock].size(); i++)
        if(v[leftBlock][i] == k)
            ret++;

    for(ll i = 0; i <= rightPos; i++)
        if(v[rightBlock][i] == k)
            ret++;

    for(ll i = leftBlock + 1; i < rightBlock; i++)
        ret += cnt[i][k];

    return ret;
}

int main()

{
    ll n;
    cin >> n;
    for(ll i = 0; i < n; i++) {
        ll in;
        scanf("%d", &in);

        v[i / block].push_back(in);
        cnt[i / block][in]++;
    }

    ll q, lastans = 0;
    cin >> q;
    while(q--) {
        ll t;
        scanf("%d", &t);
        if(t == 1) {
            ll l, r;
            scanf("%d %d", &l, &r);
            l = (l + lastans - 1) % n + 1, r = (r + lastans - 1) % n + 1;
            if(l > r) swap(l, r);
            update(l - 1, r - 1);
        }
        else {
            ll l, r, k;
            scanf("%d %d %d", &l, &r, &k);
            l = (l + lastans - 1) % n + 1, r = (r + lastans - 1) % n + 1, k = (k + lastans - 1) % n + 1;
            if(l > r) swap(l, r);

            lastans = query(l - 1, r - 1, k);
            printf("%d\n", lastans);
        }
    }

    return 0;
}