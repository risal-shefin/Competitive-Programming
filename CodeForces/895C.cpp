#include <bits/stdc++.h>
using namespace std;
#define ll int
#define lo long long
#define mod 1000000007
ll ara[100009], cnt[100], dp[1 << 19][80], maskOf[100];
ll pow2[100009], numOf[100];
bool check[100];
ll solve(ll msk, ll num)
{
    if(num > 70)
        return msk == 0;
    ll &ret = dp[msk][num];
    if(ret != -1)
        return ret;
    if(cnt[num] == 0)
        return solve(msk, num + 1) % mod;
    ll oddComb = pow2[ cnt[num] - 1], evenComb = pow2[ cnt[num] - 1];
    ret = ((lo)oddComb * solve(msk ^ maskOf[num], num + 1) ) % mod;
    ret = (ret + ((lo)evenComb * solve(msk, num + 1) ) % mod) % mod;
//    cout << num << "  " << ret << endl;
//    cout << bitset<4>(msk) << "  " << bitset <4> (maskOf[num]) << endl;
    return ret;
}
int main()
{
    memset(dp, -1, sizeof(dp));
    pow2[0] = 1;
    for(ll i = 1; i <= 100005; i++)
        pow2[i] = (pow2[i - 1] * 2) % mod;
    ll indx = 0;
    for(ll i = 2; i <= 70; i++) {
        if(!check[i]) {
            numOf[i] = indx++;
            for(ll j = i * i; j <= 70; j += i)
                check[j] = 1;
        }
    }
    ll n;
    cin >> n;
    for(ll i = 1; i <= n; i++) {
        scanf("%d", &ara[i]);
        cnt[ ara[i] ]++;
        ll num = ara[i], bt = 0, ase;
        for(ll k = 2; k * k <= num; k++) {
            if(num % k == 0) {
                ase = 0;
                while(num % k == 0) {
                    num /= k;
                    ase++;
                }
                if(ase % 2 != 0)
                    bt |= (1LL << numOf[k]);
            }
        }
        if(num > 1)
            bt |= (1LL << numOf[num]);
        maskOf[ara[i]] = bt;
    }
    ll ans = ( (solve(0, 1) - 1) + mod) % mod;
    cout << ans << endl;
    return 0;
}
