#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll ara[30009], n;
ll tree[90009];
void init(ll lo, ll hi, ll node)
{
    if(lo == hi) {
        tree[node] = lo;
        return;
    }
      ll mid = (lo + hi) / 2;
    init(lo, mid, 2 * node);
    init(mid + 1, hi, 2 * node + 1);
      if(ara[ tree[2 * node] ] < ara[ tree[2 * node + 1] ])
        tree[node] = tree[2 * node];
    else
        tree[node] = tree[2 * node + 1];
}
ll query(ll lo, ll hi, ll left, ll right, ll node)
{
    if(lo > right || hi < left)
        return -1;
    if(lo >= left && hi <= right)
        return tree[node];
      int mid = (lo + hi) / 2;
    ll p1 = query(lo, mid, left, right, 2 * node);
    ll p2 = query(mid + 1, hi, left, right, 2 * node + 1);
      if(p1 == -1)
        return p2;
    if(p2 == -1)
        return p1;
    if(ara[p1] < ara[p2])
        return p1;
    return p2;
}
ll area(ll start, ll stop)
{
    if(start > stop)
        return 0;
    if(start == stop)
        return ara[start];
      ll indx = query(0, n - 1, start, stop, 1);
    //cout << 6;
    ll ans = max(area(start, indx - 1), area(indx + 1, stop) );
    //cout << 5;
    return max(ans, (stop - start + 1) * ara[indx]);
}
int main()
{
    ll t, caseno = 0;
    cin >> t;
    while(t--) {
        scanf("%d", &n);
        for(ll i = 0; i < n; i++)
            scanf("%d", &ara[i]);
          init(0, n - 1, 1);
        printf("Case %lld: %lld\n", ++caseno, area(0, n - 1));
    }
      return 0;
}
 
