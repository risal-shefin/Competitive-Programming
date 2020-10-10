#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define mod 1000000007

#define ll long long
typedef pair<ll, ll> pii;
#define x first
#define y second

pii extendedEuclid(ll a, ll b)   // returns x, y for ax + by = gcd(a,b)
{
    if(b == 0) return pii(1, 0);
    else
    {
        pii d = extendedEuclid(b, a % b);
        return pii(d.y, d.x - d.y * (a / b));
    }
}

ll modularInverse(ll a, ll m)
{
    pii ret = extendedEuclid(a, m);
    return ((ret.x % m) + m) % m;
}


ll grid[1009][1009], row[1009], col[1009], r, c, fact[1000009];
ll pr[1009], pc[1009];

bool checkRow()

{
    for(ll i = 1; i <= r; i++) {
        ll sum = 0;
        for(ll j = 1; j <= c; j++) {
            if(grid[i][j] == 0)
                break;
            sum++;
        }

        if(sum != row[i])
            return 0;
    }

    return 1;
}

bool checkCol()

{
    for(ll i = 1; i <= c; i++) {
        ll sum = 0;
        for(ll j = 1; j <= r; j++) {
            if(grid[j][i] == 0)
                break;
            sum++;
        }

        if(sum != col[i])
            return 0;
    }

    return 1;
}

int main()

{
    cin >> r >> c;
    for(ll i = 1; i <= r; i++) {
        scanf("%lld", &row[i]);

        for(ll j = 1; j <= row[i]; j++)
            grid[i][j] = 1;

        pr[i] = row[i] + 2;
        //cout << i << "ii " << pr[i] << " " << row[i] << endl;
    }
    for(ll i = 1; i <= c; i++) {
        scanf("%lld", &col[i]);

        for(ll j = 1; j <= col[i]; j++)
            grid[j][i] = 1;

        pc[i] = col[i] + 2;
    }

    if(!checkRow()) {
        cout << 0 << endl;
        return 0;
    }
    if(!checkCol()) {
        cout << 0 << endl;
        return 0;
    }

    ll cnt = 0;
    for(ll i = 2; i <= r; i++) {
        for(ll j = 2; j <= c; j++) {
            if(j >= pr[i] && i >= pc[j] && grid[i][j] != 1) {
                cnt++;
                //-cout << i << " " << j << endl;
                //cout << row[i] << " hh "  << pr[i] << endl;
            }
        }
    }

    //cout << cnt << endl;

    fact[0] = 1;
    for(ll i = 1; i <= 1000002; i++) {
        fact[i] = (fact[i - 1] * i) % mod;
    }

    ll ans = 0;
    for(ll i = 1; i <= cnt; i++) {
        ll n = cnt, r = i, nr = cnt - i;

        ll rnr = (fact[r] * fact[nr]) % mod;
        rnr = modularInverse(rnr, mod);

        ans = (ans + ((fact[n] * rnr) % mod)) % mod;

        //cout << fact[cnt] << " " << (fact[r] * fact[nr]) << endl;
    }
    ans++;

    cout << ans << endl;

    return 0;
}