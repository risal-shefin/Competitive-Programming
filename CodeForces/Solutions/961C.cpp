#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define inf 2e18
/***template***/
#define ___                  ios_base::sync_with_stdio(false);cin.tie(NULL);
#define dd                   double
#define scl(n)               scanf("%lld",&n)
#define scd(n)               scanf("%lf",&n)
#define pi                   pair<ll,ll>
#define pb                   push_back
#define mp                   make_pair
#define uu                   first
#define vv                   second
#define FOR(i,n)             for(ll i=1;i<=n;i++)
#define LOOP(i,n)            for(ll i=0;i<n;i++)
#define FOOR(i,a,b)          for(ll i=a;i<=b;i++)
#define LOP(i,a,b)           for(ll i=a;i<b;i++)
#define sorted(s)            sort(s.begin(),s.end())
#define sortedd(s)           sort(s.begin(),s.end(),cmp)
#define reversed(s)          reverse(s.begin(),s.end())
#define contains(a,b)        (find((a).begin(), (a).end(), (b)) != (a).end())
#define MAXN                 100005
#define pii                  3.1415926536
#define mod                  1000000007
#define eps                  0.0000000001
#define inf                  1e18
#define INF                  (1LL<<62)
#define mstt(a,b)            memset((a),(b),sizeof (a))
#define sz(x)                (ll)x.size()
#define uniquee(x)            x.erase(unique(x.begin(), x.end()),x.end())
/****only for priority queue******/
/**struct node
{
    ll nod,d;
    node(ll a,ll b)
    {
        nod=a;
        d=b;
    }
    bool operator<(const node &p)const
    {
        return p.d<d;
    }
};**/

ll Set(ll n,ll pos)
{
    return n=n|(1LL<<pos);
}
ll reset(ll n,ll pos)
{
    return n=n&~(1LL<<pos);
}
bool check(ll n,ll pos)
{
    return (bool)(n&(1LL<<pos));
}
ll mul(ll a,ll b)
{
    ll c;
    c = (a%mod * b%mod)%mod;
    return c;
}
ll add(ll a,ll b)
{
    ll c;
    c = (a%mod + b%mod)%mod;
    return c;
}
ll sub(ll a,ll b)
{
    ll c;
    c = ((a%mod - b%mod)%mod + mod)%mod;
    return c;
}
ll power(ll x,ll y)
{
    ll res = 1;
    x = x;
    while (y > 0)
    {
        if (y & 1)
            res = (res*x);
        y = y>>1;
        x = (x*x);
    }
    return res;
}
long long exgcd(long long x, long long y, long long &a, long long &b)
{
    // ax + by = gcd(x,y)
    int flag = 0;
    long long t, la = 1, lb = 0, ra = 0, rb = 1;
    while(x%y)
    {
        if(flag == 0)
            la -= x/y*ra, lb -= x/y*rb;
        else
            ra -= x/y*la, rb -= x/y*lb;
        t = x, x = y, y = t%y;
        flag = 1 - flag;
    }
    if(flag == 0)
        a = ra, b = rb;
    else
        a = la, b = lb;
    return y;
}
/***template***/

char a[6][109][109], chess[300][300];
ll row[] = {0, 0, 1, -1};
ll col[] = {1, -1, 0, 0};
ll cnt1 = 0, cnt2 = 0, cnt3 = 0, cnt4 = 0;
ll perm[] = {1, 2, 3, 4};
bool vis[500][500];

int main()

{
    ll n;
    cin >> n;
    ll tot = 2 * n * 2 * n;
    for(ll i = 0; i < n; i++) {
        scanf(" %s", a[1][i]);
    }
    for(ll i = 0; i < n; i++) {
        scanf(" %s", a[2][i]);
    }
    for(ll i = 0; i < n; i++) {
        scanf(" %s", a[3][i]);
    }
    for(ll i = 0; i < n; i++) {
        scanf(" %s", a[4][i]);
    }

    ll ans = inf;

    do {
        memset(vis, 0, sizeof(vis));
        ll one = perm[0], two = perm[1], thr = perm[2], four = perm[3];
        //cout << one << two << thr << four << endl;
        ll ii = 0, jj = 0;
        for(ll i = 0; i < n; i++, ii++) {
            jj = 0;
            for(ll j = 0; j < n; j++, jj++) {
                chess[ii][jj] = a[one][i][j];
            }
        }

        ii = 0;
        for(ll i = 0; i < n; i++, ii++) {
            jj = n;
            for(ll j = 0; j < n; j++, jj++) {
                chess[ii][jj] = a[two][i][j];
            }
        }

        for(ll i = 0; i < n; i++, ii++) {
            jj = 0;
            for(ll j = 0; j < n; j++, jj++) {
                chess[ii][jj] = a[thr][i][j];
            }
        }

        ii = n;
        for(ll i = 0; i < n; i++, ii++) {
            jj = n;
            for(ll j = 0; j < n; j++, jj++) {
                chess[ii][jj] = a[four][i][j];
            }
        }

        ii = 2 * n, jj = 2 * n;
        cnt1 = 0;

        /*for(ll i = 0; i < ii; i++) {
            for(ll j = 0; j < jj; j++) {
                cout << chess[i][j];
            }
            cout << endl;
        }
        cout << endl << endl;*/
        for(ll i = 0; i < ii; i++) {
            for(ll j = 0; j < jj; j++) {
                vis[i][j] = 1;
                for(ll k = 0; k < 4; k++) {
                    ll tr = i + row[k];
                    ll tc = j + col[k];
                    if(tr < 0 || tc < 0 || tr >= ii || tc >= jj)
                        continue;
                    if(vis[tr][tc])
                        continue;
                    vis[tr][tc] = 1;
                    if(chess[tr][tc] == chess[i][j]) {
                        chess[tr][tc] = ( (chess[i][j] - '0') ^ 1) + '0';
                        cnt1++;
                    }
                }
            }
        }

        ll tmp = tot - cnt1;
        cnt1 = min(tmp, cnt1);
        ans = min(cnt1, ans);

    } while( next_permutation(perm, perm + 4));

    cout << ans << endl;

    return 0;
}