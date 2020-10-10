#include<bits/stdc++.h>

using namespace std;

/***template***/
#define ll                   long long
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
#define reversed(s)          reverse(s.begin(),s.end())
#define contains(a,b)        (find((a).begin(), (a).end(), (b)) != (a).end())
#define MAXN                 10004
#define pii                  3.1415926536
#define mod                  1000000007
#define eps                  0.0000000001
#define inf                  9000000000000000
#define mstt(a,b)            memset((a),(b),sizeof (a))

//priority_queue<ll, vector<ll>, greater<ll> >q

int main()
{
    ll test;
    scl(test);
    while(test--)
    {
        ll n;
        scl(n);
        ll ara[20];
        ll tot = 0;
        FOR(i,7)
        {
            scl(ara[i]);
            ara[i+7] = ara[i];
            tot += ara[i];
        }

        ll out = 99999999999999999;
        ///pos = 1;
        for(ll pos = 1; pos <= 7; pos++)
        {
            if(ara[pos] == 1)
            {
                ll day = (n / tot) ;
                if(n % tot == 0)
                    day--;
                ll ase = day * tot;
                day *= 7;
                for(ll i = pos; i < pos + 7; i++)
                {
                    ase += ara[i];
                    day++;
                    if(ase == n)
                        break;
                }
                out = min( out, day);
            }
        }

        printf("%lld\n",out);
    }
}