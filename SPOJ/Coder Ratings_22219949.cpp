#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll ans[300009], tree[400009];
struct node {
    ll a, h, id;
} ara[300009];
bool cmp(node a, node b)
 {
    if(a.a != b.a)
        return a.a < b.a;
    return a.h < b.h;
}
void update(ll lo, ll hi, ll indx, ll node)
 {
    if(lo > indx || hi < indx)
        return;
    if(lo == hi) {
        tree[node]++;
        return;
    }
     ll mid = (lo + hi) / 2;
    update(lo, mid, indx, 2 * node);
    update(mid + 1, hi, indx, 2 * node + 1);
     tree[node] = tree[ 2 * node] + tree[ 2 * node + 1];
}
ll query(ll lo, ll hi, ll left, ll right, ll node)
 {
    if(left > right)
        return 0;
    if(lo > right || hi < left)
        return 0;
    if(lo >= left && hi <= right)
        return tree[node];
     ll mid = (lo + hi) / 2;
    ll p1 = query(lo, mid, left, right, 2 * node);
    ll p2 = query(mid + 1, hi, left, right, 2 * node + 1);
     return p1 + p2;
}
int main()
 {
    ll n;
    cin >> n;
    for(ll i = 1; i <= n; i++) {
        scanf("%lld %lld", &ara[i].a, &ara[i].h);
        ara[i].id = i;
    }
     sort(ara + 1, ara + n + 1, cmp);
     for(ll i = 1; i <= n; i++) {
         ll ret = query(1, 100000, 1, ara[i].h, 1);
        ll rata = ara[i].a, rath = ara[i].h;
        ll j = i;
         while(ara[j].a == rata && ara[j].h == rath && j <= n) {
            ans[ ara[j].id ] = ret;
            update(1, 100000, ara[i].h, 1);
            j++;
        }
        i = j - 1;
    }
     for(ll i = 1; i <= n; i++)
        printf("%lld\n", ans[i]);
     return 0;
}
