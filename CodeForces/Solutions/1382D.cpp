// #pragma GCC optimize("Ofast,unroll-loops")
// #pragma GCC target("avx,avx2,fma")

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long
#define dd double
#define ld long double
#define sl(n) scanf("%lld", &n)
#define si(n) scanf("%d", &n)
#define sd(n) scanf("%lf", &n)
#define pll pair <ll, ll>
#define pii pair <int, int>
#define mp make_pair
#define pb push_back
#define all(v) v.begin(), v.end()
#define inf (1LL << 62)
#define loop(i, start, stop, inc) for(ll i = start; i <= stop; i += inc)
#define for1(i, stop) for(ll i = 1; i <= stop; ++i)
#define for0(i, stop) for(ll i = 0; i < stop; ++i)
#define rep1(i, start) for(ll i = start; i >= 1; --i)
#define rep0(i, start) for(ll i = (start-1); i >= 0; --i)
#define ms(n, i) memset(n, i, sizeof(n))
#define casep(n) printf("Case %lld:", ++n)
#define pn printf("\n")
#define pf printf
#define EL '\n'
#define fastio std::ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

const ll sz = 2009;
ll ara[2*sz], n;
vector <int> lst;
bool vis[2*sz];

ll dp[2*sz][2*sz];

ll solve(ll pos, ll sum)
{
    if(pos == lst.size()) {
        return sum == n;
    }
    if(sum == n)
        return 1;
    if(sum > n)
        return 0;

    ll &ret = dp[pos][sum];
    if(ret != -1)
        return ret;

    ret = 0;
    ret |= solve(pos+1, sum);
    ret |= solve(pos+1, sum+lst[pos]);

    return ret;
}

int main()
{
    ll t;
    cin >> t;
    while(t--) {
        sl(n);

        ll tot = n+n;

        for1(i, tot) sl(ara[i]);

        ll mxx = tot;
        for(ll i = mxx; i >= 1; i--) {

            ll pos = -1;

            for1(j, tot) {
                if(vis[j])
                    continue;

                if(ara[j] == i) {
                    pos = j;
                    break;
                }
            }

            if(pos == -1)
                continue;

            ll cnt = 0;
            for(ll j = pos; j <= tot; j++) {
                if(vis[j])
                    continue;

                cnt++;
                vis[j] = 1;
            }

            lst.pb(cnt);
        }

//        for(int &num : lst) cout << num << " ";
//        cout << endl;

        for(ll i = 0; i <= tot; i++)
            for(ll j = 0; j <= tot; j++)
                dp[i][j] = -1;

        bool got = solve(0, 0);

        if(got) pf("YES\n");
        else pf("NO\n");

        lst.clear();
        for(ll i = 0; i <= tot; i++) vis[i] = 0;
    }

    return 0;
}