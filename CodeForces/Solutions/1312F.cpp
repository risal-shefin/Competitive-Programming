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

const ll sz = 3e5 + 10;
ll ara[sz], n, x, y, z;
vector < vector <int> > mex;
map <vector<int>, int> vis;
map <vector<int>, int> :: iterator it;

ll calc_mex(const set <int> &lst)
{
    ll m = 0;
    for(auto &v: lst) {
        if(m == v)
            m++;
        else
            break;
    }
    return m;
}

pll cycle_grundy()
{
    vector <int> num;
    mex.pb(vector<int>(3));
    mex[0][0] = mex[0][1] = mex[0][2] = 0;
    for(ll i = 1; ; i++)
    {
        ll prv0 = max(0LL, i-x), prv1 = max(0LL, i-y), prv2 = max(0LL, i-z);

        mex.pb(vector<int>(3));
        mex[i][0] = calc_mex({mex[prv0][0], mex[prv1][1], mex[prv2][2]});

        mex[i][1] = calc_mex({mex[prv0][0], mex[prv2][2]});

        mex[i][2] = calc_mex({mex[prv0][0], mex[prv1][1]});

        num.pb(mex[i][0]), num.pb(mex[i][1]), num.pb(mex[i][2]);

        if(i == 5) vis[num] = i;
        if(i > 5) {
            num.erase(num.begin()), num.erase(num.begin()), num.erase(num.begin());

            it = vis.find(num);
            if(it != vis.end()) {
                ll id = it->second;
                ll cycle_len = i - id, cycle_start = id+1;
                return mp(cycle_start, cycle_len);
            }
            vis[num] = i;
        }
    }
}

ll grundy(ll n, ll last, pll &cyc)
{
    if(n <= 0) return 0;
    if(n < cyc.first) return mex[n][last];
    ll d = (n - cyc.first) % cyc.second;
    return mex[cyc.first + d][last];
}

int main()
{
    ll t;
    cin >> t;
    while(t--) {
        scanf("%lld %lld %lld %lld", &n, &x, &y, &z);
        for1(i, n)
            sl(ara[i]);

        pll cyc = cycle_grundy();

        ll xr = 0;
        for1(i, n)
            xr ^= grundy(ara[i], 0, cyc);

        if(xr == 0) {
            pf("0\n");
            continue;
        }
        ll ans = 0;
        for1(i, n) {

            xr ^= grundy(ara[i], 0, cyc);

            ll g = grundy(ara[i] - x, 0, cyc);
            if((xr ^ g) == 0) ans++;

            g = grundy(ara[i] - y, 1, cyc);
            if((xr ^ g) == 0) ans++;

            g = grundy(ara[i] - z, 2, cyc);
            if((xr ^ g) == 0) ans++;

            xr ^= grundy(ara[i], 0, cyc);
        }

        pf("%lld\n", ans);

        vis.clear();
    }

    return 0;
}