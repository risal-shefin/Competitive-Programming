#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pi first
#define mi second
#define pll pair <ll, ll>
pll r[100009];

int main()

{
    ll t;
    cin >> t;
    while(t--)
    {
        ll n, m;
        cin >> n >> m;
        for(ll i = 1; i <= n; i++)
        {
            scanf("%lld %lld", &r[i].pi, &r[i].mi);
        }

        ll lo = 1, hi = 1e18, ans;
        while(lo <= hi)
        {
            ll mid = lo / 2 + hi / 2;
            if(lo&1 && hi&1) mid++;

            ll b = 0, chk = 0;
            for(ll i = 1; i <= n; i++)
            {
                if(r[i].pi >= mid)
                    continue;

                ll maxPossible = m / r[i].mi;
                if((mid - r[i].pi) > maxPossible) {
                    b = 1e18;
                    break;
                }

                b += (mid - r[i].pi) * r[i].mi;
            }

            if(b > m)
                hi = mid - 1;
            else
            {
                ans = mid;
                lo = mid + 1;
            }
        }

        cout << ans << endl;
    }

    return 0;
