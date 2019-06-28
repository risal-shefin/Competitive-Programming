#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define x first
#define y second
ll temp[800009], tree[4000009];
pair <ll, ll> ara[200009];
unordered_map <ll, bool> check;
ll cs[800009];
void build(ll lo, ll hi, ll node)
{
    if(lo == hi) {
        tree[node] = cs[lo];
        //cout << tree[node] << " " << lo << endl;
        return;
    }
    ll mid = (lo + hi) / 2;
    build(lo, mid, 2 * node);
    build(mid + 1, hi, 2 * node + 1);
    tree[node] = min(tree[2 * node], tree[2 * node + 1]);
}
ll query(ll lo, ll hi, ll left, ll right, ll node)
{
    if(lo > right || hi < left)
        return 1e18;
    if(lo >= left && hi <= right)
        return tree[node];
    ll mid = (lo + hi) / 2;
    ll p1 = query(lo, mid, left, right, 2 * node);
    ll p2 = query(mid + 1, hi, left, right, 2 * node + 1);
    return min(p1, p2);
}
int main()
{
    ll n, indx = 1;
    cin >> n;
    for(ll i = 1; i <= n; i++) {
        scanf("%lld %lld", &ara[i].first, &ara[i].second);
        if(check.find(ara[i].x) == check.end()) {
            temp[indx++] = ara[i].first;
            check[ara[i].x] = 1;
        }
        if(check.find(ara[i].y) == check.end()) {
            temp[indx++] = ara[i].y;
            check[ara[i].y] = 1;
        }
    }
    sort(temp + 1, temp + indx);
    ll sz = indx;
    for(ll i = 2; i < sz; i++) {
        if(temp[i] != temp[i - 1] + 1)
            temp[indx++] = temp[i - 1] + 1;
    }
    sort(temp + 1, temp + indx);
    ll mn = 1, mx =0;
    for(ll i = 1; i <= n; i++) {
        ara[i].x = lower_bound(temp + 1, temp + indx, ara[i].x) - temp;
        ara[i].y = lower_bound(temp + 1, temp + indx, ara[i].y) - temp;
        mx = max(mx, ara[i].y);
    }
    mx++;
    //cout << indx << " " << mx << endl;
    for(ll i = 1; i <= n; i++)
        cs[ara[i].x] += 1, cs[ara[i].y + 1] += -1;
    for(ll i = 1; i <= mx; i++)
        cs[i] += cs[i - 1];
    build(1, mx, 1);
    for(ll i = 1; i <= n; i++) {
        ll p = query(1, mx, ara[i].x, ara[i].y, 1);
        if(p > 1) {
            cout << i << endl;
            return 0;
        }
    }
    cout << -1 << endl;
    return 0;
}
