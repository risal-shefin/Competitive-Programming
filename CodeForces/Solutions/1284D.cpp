#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long
#define dd double
#define ld long double
#define sl(n) scanf("%lld", &n)
#define si(n) scanf("%d", &n)
#define sd(n) scanf("%lf", &n)
#define pll pair <ll, ll>
#define pii pair <int, int>
#define mp make_pair
#define pb push_back
#define inf (1LL << 62)
#define loop(i, start, stop, inc) for(ll i = start; i <= stop; i += inc)
#define for1(i, stop) for(ll i = 1; i <= stop; i++)
#define for0(i, stop) for(ll i = 0; i < stop; i++)
#define rep1(i, start) for(ll i = start; i >= 1; i--)
#define rep0(i, start) for(ll i = (start-1); i >= 0; i--)
#define ms(n, i) memset(n, i, sizeof(n))
#define casep(n) printf("Case %lld:", ++n)
#define pn printf("\n")
#define pf printf
#define fastio std::ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

#define sz 100009
ll n;

struct lect {
    ll sa, ea, sb, eb;
} ara[sz];
bool operator <(const lect &a, const lect &b) {
    if(a.sa != b.sa)
        return a.sa < b.sa;
    return a.ea > b.ea;
}

struct node{
    node *left, *right;
    int val;
    node(int a = 0, node *b = NULL, node *c = NULL) :
    val(a), left(b), right(c) {} // ** Constructor

    void build(int l, int r) {
        if(l == r) return;
        left = new node();
        right = new node();
        int mid = l + r >> 1;
        left -> build(l, mid);
        right -> build(mid+1, r);
    }

    node *update(int l, int r, int idx, int v) {
        if(r < idx || l > idx) return this;
        if(l == r) {
            node *ret = new node(val, left, right);
            ret -> val += v;
            return ret;
        }
        int mid = l + r >> 1;
        node *ret = new node(val);
        ret -> left = left -> update(l, mid, idx, v);
        ret -> right = right -> update(mid+1, r, idx, v);

        ret -> val = ret -> left -> val + ret -> right -> val;
        return ret;
    }

} *roots[sz], *roote[sz];

ll query(ll lo, ll hi, ll lft, ll rgt, node *rng1, node *rng2)
{
    if(lo > rgt || hi < lft || lft > rgt)
        return 0;
    if(lo >= lft && hi <= rgt)
        return rng2->val - rng1->val;

    ll mid = lo+hi >> 1;
    return query(lo, mid, lft, rgt, rng1->left, rng2->left) +
            query(mid+1, hi, lft, rgt, rng1->right, rng2->right);
}

ll findInter(ll idx)
{
    ll lo = idx+1, hi = n, ret = idx;
    while(lo <= hi) {
        ll mid = (lo+hi)/2;

        if(ara[mid].sa <= ara[idx].ea) {
            ret = mid;
            lo = mid+1;
        }
        else
            hi = mid-1;
    }
    return ret;
}

vector <ll> num;

int main()

{
    sl(n);
    for1(i, n) {
        sl(ara[i].sa), sl(ara[i].ea), sl(ara[i].sb), sl(ara[i].eb);

        num.pb(ara[i].sa), num.pb(ara[i].ea), num.pb(ara[i].sb), num.pb(ara[i].eb);
    }
    sort(num.begin(), num.end());
    sort(ara+1, ara+n+1);
    roots[0] = new node();
    roots[0] -> build(0, 4*n);
    roote[0] = new node();
    roote[0] -> build(0, 4*n);

    for1(i, n) {
        ara[i].sa = lower_bound(num.begin(), num.end(), ara[i].sa) - num.begin();
        ara[i].ea = lower_bound(num.begin(), num.end(), ara[i].ea) - num.begin();
        ara[i].sb = lower_bound(num.begin(), num.end(), ara[i].sb) - num.begin();
        ara[i].eb = lower_bound(num.begin(), num.end(), ara[i].eb) - num.begin();

        roots[i] = roots[i-1]->update(0, 4*n, ara[i].sb, 1);
        roote[i] = roote[i-1]->update(0, 4*n, ara[i].eb, 1);
    }

    bool chk = 0;
    for1(i, n) {
        ll lastInter = findInter(i);

        ll aInter = lastInter - i;
        ll bInter = query(0, 4*n, 0, ara[i].eb, roots[i], roots[lastInter]) -
                    query(0, 4*n, 0, ara[i].sb-1, roote[i], roote[lastInter]);

        if(bInter != aInter) {
            chk = 1;
            break;
        }

        ll bextra = query(0, 4*n, 0, ara[i].eb, roots[lastInter], roots[n]) -
                    query(0, 4*n, 0, ara[i].sb-1, roote[lastInter], roote[n]);
        if(bextra != 0) {
            chk = 1;
            break;
        }
    }

    chk==0 ? pf("YES\n") : pf("NO\n");

    return 0;
}