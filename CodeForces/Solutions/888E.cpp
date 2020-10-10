#include <bits/stdc++.h>
using namespace std;

#define ll long long

vector <ll> v;
ll n, m, ans = 0, ara[40];

void allsum1(ll pos, ll sum)

{
    if(sum != 0)
        v.push_back(sum);

    if(pos > n || pos > 17)
        return;

    allsum1(pos + 1, sum);
    allsum1(pos + 1, (sum + ara[pos]) % m);
}

void allsum2(ll pos, ll sum)

{
    if(sum != 0) {
        ll tof = m - 1 - sum;
        ll indx = lower_bound(v.begin(), v.end(), tof) - v.begin();
        if(indx == v.size() || v[indx] > tof)
            indx--;

        if(indx >= 0)
            ans = max(ans, sum + v[indx]);

        ans = max(ans, sum);
    }

    if(pos > n)
        return;

    allsum2(pos + 1, sum);
    allsum2(pos + 1, (sum + ara[pos]) % m);
}

int main()

{
    cin >> n >> m;
    for(ll i = 1; i <= n; i++) {
        scanf("%lld", &ara[i]);
    }

    allsum1(1, 0);
    sort(v.begin(), v.end());
    allsum2(18, 0);

    ans = max(ans, v.size() > 0? v[v.size() - 1]: 0LL);

    cout << ans << endl;

    return 0;
}