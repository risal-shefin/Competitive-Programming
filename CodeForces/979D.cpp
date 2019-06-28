#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define ll int
#define mx 100009
vector <int> divi[mx];
bool mark[100009];
struct node {
    ll mn;
    node *bt[2];
    node() {
        bt[0] = nullptr;
        bt[1] = nullptr;
        mn = mx;
    }
} *divitrie[mx];
void init()
{
    for(ll i = 1; i < mx; i++) {
        for(ll j = i; j < mx; j += i) {
            divi[j].pb(i);
        }
        divitrie[i] = new node();
    }
}
void add(ll d, ll num)
{
    node *cur = divitrie[d];
    cur -> mn = min(cur -> mn, num);
    for(ll i = 20; i >= 0; i--) {
        ll state = (num >> i) & 1;
        if(cur -> bt[ state ] == nullptr)
            cur -> bt[state] = new node();
        cur = cur -> bt[state];
        cur -> mn = min(cur -> mn, num);
    }
}
ll query(ll x, ll k, ll s)
{
    node *cur = divitrie[k];
    if(x % k != 0 || cur -> mn + x > s)
        return -1;
    ll ret = 0;
    for(ll i = 20; i >= 0; i--) {
        ll state = (x >> i) & 1;
        if(cur -> bt[state ^ 1] != nullptr && cur -> bt[state ^ 1] -> mn + x <= s) {
            ret += ( (state ^ 1) << i);
            cur = cur -> bt[state ^ 1];
        }
        else {
            if(cur -> bt[state] == nullptr && i != 0)
                return -1;
            if(i != 0)
                if(cur -> bt[state] -> mn + x > s)
                    return -1;
            ret += (state << i);
            cur = cur -> bt[state];
        }
    }
    return ret;
}
int main()
{
    init();
    ll n, t, x, k, s;
    cin >> n;
    for(ll i = 1; i <= n; i++) {
        scanf("%d", &t);
        if(t == 1) {
            ll in;
            scanf("%d", &in);
            if(mark[in])
                continue;
            else {
                mark[in] = 1;
                for(ll j = 0; j < divi[in].size(); j++) {
                    add(divi[in][j], in);
                }
            }
        }
        else {
            scanf("%d %d %d", &x, &k, &s);
            printf("%d\n", query(x, k, s));
        }
    }
    return 0;
}
