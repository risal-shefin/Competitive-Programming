#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define inf 100001
struct point {
    ll x, y;
      point(ll _x = 0, ll _y = 0) {
        x = _x;
        y = _y;
    }
} ara[105];
ll det(point a, point b, point c)
{
    ll val = (a.x * b.y + b.x * c.y + c.x * a.y) - (a.y * b.x + b.y * c.x + c.y * a.x);
    if(val == 0)
        return 0;
      return (val > 0)? 1 : 2;
}
bool onSegment(point a, point b, point c)
{
    if(c.x <= max(a.x, b.x) && c.x >= min(a.x, b.x) && c.y <= max(a.y, b.y) && c.y >= min(a.y, b.y) )
        return true;
    return false;
}
ll intersect(point a, point b, point p)
{
    point q = point(p.x + inf, p.y + inf + 9);
      ll o1 = det(a, b, p);
    ll o2 = det(a, b, q);
    ll o3 = det(p, q, a);
    ll o4 = det(p, q, b);
      if(o1 != o2 && o3 != o4)
        return 1;
      if(o1 == 0 && onSegment(a, b, p))
        return 2;
    if(o2 == 0 && onSegment(a, b, q))
        return 1;
    if(o3 == 0 && onSegment(p, q, a))
        return 1;
    if(o3 == 0 && onSegment(p, q, b))
        return 1;
      return 0;
}
bool isInside(ll n, point p)
{
    ll cnt = 0;
      for(ll i = 1; i <= n; i++) {
        ll j = i + 1;
        if(j > n)  j = 1;
        ll ret = intersect(ara[i], ara[j], p);
          if(ret) {
            if(ret == 2) return 1;
            if(det(ara[i], ara[j], p) == 0)
                return onSegment(ara[i], ara[j], p);
              cnt++;
        }
    }
      return cnt & 1;
}
int main()
{
    ll t, caseno = 0;
    cin >> t;
    while(t--) {
        ll n;
        scanf("%lld", &n);
        for(ll i = 1; i <= n; i++)
            scanf("%lld %lld", &ara[i].x, &ara[i].y);
          ll q;
        scanf("%lld", &q);
        printf("Case %lld:\n", ++caseno);
        while(q--) {
            ll x, y, cnt = 0, tmp;
            scanf("%lld %lld", &x, &y);
              if(isInside(n, point(x, y)) )
                printf("Yes\n");
            else
                printf("No\n");
        }
      }
}
