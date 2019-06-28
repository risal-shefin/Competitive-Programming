#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
#define ll long long
struct node {
    ll p, val;
    node(ll _p, ll _v) {
        p = _p;
        val = _v;
    }
    node() {
    }  
} ara[100009];
bool cmp(node a, node b)
{
     if(a.p == b.p)
          return a.val > b.val;
     return a.p < b.p;
}
int main()
{
    ll t, caseno = 0;
    cin >> t;
    while(t--) {
        ll n;
        scanf("%lld", &n);
                ll indx = 0;
        for(ll i = 0; i < n; i++) {
            ll s, t;
            scanf("%lld %lld", &s, &t);
            ara[indx++] = node(s, 1);
            ara[indx++] = node(t, -1);
        }
                sort(ara, ara + indx, cmp);
        ll sum = 0, ans = 0;
        for(ll i = 0; i < indx; i++) {
            sum += ara[i].val;
            ans = max(ans, sum);
        }
                printf("Case %lld: %lld\n", ++caseno, ans);
    }
    return 0;
}
