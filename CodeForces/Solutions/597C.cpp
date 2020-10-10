#include <bits/stdc++.h>
using namespace std;

#define ll unsigned long long
#define block 317
ll cnt[100009][12], sum[320][12], n, k;

void update(ll num, ll len, ll v)

{
    ll b = num / block;
    cnt[num][len] += v;
    sum[b][len] += v;
}

ll query(ll l, ll r, ll len)

{
    if(l > r) return 0;
    ll lb = l / block, rb = r / block;
    ll ret = 0;

    if(lb == rb) {
        for(ll i = l; i <= r; i++)
            ret += cnt[i][len];;
        return ret;
    }
    for(ll i = l; i < (lb + 1) * block; i++)
        ret += cnt[i][len];
    for(ll i = lb + 1; i < rb; i++)
        ret += sum[i][len];
    for(ll i = rb * block; i <= r; i++)
        ret += cnt[i][len];

    return ret;
}

int main()

{
    ll ans = 0;
    cin >> n >> k;
    for(ll i = 1; i <= n; i++) {
        ll in;
        scanf("%lld", &in);

        for(ll j = 1; j <= k + 1; j++) {
            if(j == 1) {
                update(in, j, 1);
                continue;
            }

            ll q = query(1, in - 1, j - 1);
            update(in, j, q);

            //cout << in << "  " << q << " " << k << endl;;;

            if(j == k + 1)
                ans += q;
        }
    }

    if(k == 0)
        ans = n;

    cout << ans << endl;

    return 0;
}