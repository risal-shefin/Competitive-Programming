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
#define inf (1LL << 62)
#define loop(i, start, stop, inc) for(ll i = start; i <= stop; i += inc)
#define for1(i, stop) for(ll i = 1; i <= stop; i++)
#define for0(i, stop) for(ll i = 0; i < stop; i++)
#define rep1(i, start) for(ll i = start; i >= 1; i--)
#define rep0(i, start) for(ll i = (start-1); i >= 0; i--)
#define ms(n, i) memset(n, i, sizeof(n))
#define casep(n) printf("Case %lld:", ++n)
#define pn printf("\n")
#define pf printf
#define fastio std::ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

ll ara[509], dp[509];
bool pos[509][509];

bool check(ll l, ll r)
{
    stack <ll> now;
    for(ll i = l; i <= r; i++) {
        ll v = ara[i];
        while(!now.empty() && now.top() == v) {
            now.pop();
            v++;
        }
        now.push(v);
    }
    return now.size() == 1;
}

int main()
{
    ll n;
    cin >> n;
    for1(i, n)
        sl(ara[i]);

    for1(i, n) {
        for(ll j = i; j <= n; j++)
            pos[i][j] = check(i, j);
    }

    dp[n+1] = 0;
    rep1(i, n) {
        dp[i] = inf;
        for(ll j = i; j <= n; j++) {
            if(pos[i][j])
                dp[i] = min(dp[i], 1 + dp[j+1]);
        }
    }

    cout << dp[1] << endl;

    return 0;
}