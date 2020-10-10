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


struct node {
    ll s;
    ll d;
    ll c;
    ll id;
} ara[109];

bool check[109], ch2 = 0, cm[109];

bool cmp(node a, node b)

{
    return a.d < b.d;
}

ll ans[109];

int main()

{
    ll n, m;
    cin >> n >> m;
    for(ll i = 1; i <= m; i++) {
        sl(ara[i].s), sl(ara[i].d), sl(ara[i].c);
        ara[i].id = i;
        if( check[ ara[i].d ] )
            ch2 = 1;

        check[ ara[i].d ] = 1;
    }

    if(ch2) {
        printf("-1\n");
        return 0;
    }

    sort(ara + 1, ara + m + 1, cmp);

    bool chk = 1;
    for(ll i = 1; i <= n; i++) {
        for(ll j = 1; j <= m; j++) {
            if(i == ara[j].d) {
                ans[i] = m + 1;
                break;
            }
            if(i >= ara[j].s && !cm[j] && i < ara[j].d) {
                ans[i] = ara[j].id;
                ara[j].c--;
                if(ara[j].c == 0)
                    cm[j] = 1;
                break;
            }
        }
    }

    for(ll j = 1; j <= m; j++) {
        if(!cm[j])
            chk = 0;
    }

    if(!chk) {
        printf("-1\n");
        return 0;
    }
    else {
        for(ll i = 1; i <= n; i++) {
            if(i != 1)
                printf(" ");
            printf("%lld", ans[i]);
        }
    }

    cout << endl;
    return 0;
}