#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define inf 1e18
#define sl(val) scanf("%lld", &val)
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


ll b[100009], n;

ll solve(ll num, ll indx, ll dif)

{
    if(indx > n)
        return 0;
    ll state = 0, s1 = inf, s2 = inf, s3 = inf;
    if(indx == 2) {
        s1 = solve( b[indx], indx + 1, b[indx] - num);
        s2 = solve( b[indx] + 1, indx + 1, b[indx] + 1 - num);
        s3 = solve( b[indx] - 1, indx + 1, b[indx] - 1 - num);
    }
    else {
        if(b[indx] - num == dif)
            s1 = solve( b[indx], indx + 1, b[indx] - num);
        if(b[indx] + 1 - num == dif)
            s2 = solve( b[indx] + 1, indx + 1, b[indx] + 1 - num);
        if(b[indx] - 1 - num == dif)
            s3 = solve( b[indx] - 1, indx + 1, b[indx] - 1 - num);
    }


    //cout << indx + 1 << "  " << dif << endl;
    s2++, s3++;
    state = min(s1, s2);
    state = min(state, s3);
    return state;
}

int main()

{
    cin >> n;
    ll dif;
    bool chk = 1;
    for(ll i = 1; i <= n; i++) {
        sl(b[i]);
        if(i == 2)
            dif = b[2] - b[1];
        if(i > 2) {
            if(dif != b[i] - b[i - 1])
                chk = 0;
        }
    }

    if(n <= 2 || chk) {
        printf("0\n");
        return 0;
    }


    ll ans = 0;
    ll a1 = solve(b[1] + 1, 2, 0);
    ll a2 = solve(b[1], 2, 0);
    ll a3 = solve(b[1] - 1, 2, 0);

    a1++, a3++;
    ans = min(a1, a2);
    ans = min(ans, a3);
    //ans = a1;

    if(ans >= inf) {
        printf("-1\n");
        return 0;
    }

    else
        printf("%lld\n", ans);

    return 0;
}