#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define siz 250000
ll lazya[5 * siz], cnta[5 * siz], lazyb[5 * siz], cntb[5 * siz], lazyc[5 * siz], tree[5 * siz];
bool chk[5 * siz];
void propa(ll lo, ll hi, ll node)
{
    ll m = (lo + hi) / 2;
    cnta[ 2 *node] += cnta[node];
    cnta[2 * node + 1] += cnta[node];
    lazya[2 * node] += lazya[node];
    lazya[2 * node + 1] += (lazya[node] + (m - lo + 1) * cnta[node]);
    //cout << endl << lo << "  " << hi << "  " << ( ( ( 2 * lazya[node] + (hi - lo) * cnta[node] ) * (hi - lo + 1) ) / 2) << endl;
    tree[2 * node] += ( ( 2 * lazya[node] + (m - lo) * cnta[node] ) * (m - lo + 1) ) / 2;
    tree[2 * node + 1] += ( (2 * lazya[node] + (hi - lo + m - lo + 1) * cnta[node] ) * (hi - m) ) / 2;
    lazya[node] = 0;
    cnta[node] = 0;
}
void propb(ll lo, ll hi, ll node)
{
    ll m = (lo + hi) / 2;
    cntb[2 * node] += cntb[node];
    cntb[2 * node + 1] += cntb[node];
    lazyb[2 * node] += (lazyb[node] + (hi - m) * cntb[node]);
    lazyb[2 * node + 1] += lazyb[node];
    //cout << lazyb[node] << "  parent " << lo << "  " << hi << endl;
    //cout << lazyb[2 * node] << " ggg " << lazyb[2 * node + 1] << endl;
    tree[2 * node] += ( (2 * lazyb[node] + (hi - lo + hi - m) * cntb[node]) * (m - lo + 1)) / 2;
    tree[2 * node + 1] += ( ( 2 * lazyb[node] + (hi - m - 1) * cntb[node] ) * (hi - m) ) / 2;
    //cout << lo << "  " << hi << "  " << tree[node] << "  " << lazyb[node] <<  endl;
    lazyb[node] = 0;
    cntb[node] = 0;
}
void propc(ll lo, ll hi, ll node)
{
    ll m = (lo + hi) / 2;
    lazyc[2 * node] = lazyc[node];
    lazyc[2 * node + 1] = lazyc[node];
    chk[2 * node] = chk[2 * node + 1] = 1;
    lazya[2 * node] = lazyb[2 * node] = cnta[2 * node] = cntb[2 * node] = 0;
    lazya[2 * node + 1] = lazyb[2 * node + 1] = cnta[2 * node + 1] = cntb[2 * node + 1] = 0;
    tree[2 * node] = (m - lo + 1) * lazyc[node];
    tree[2 * node + 1] = (hi - m) * lazyc[node];
    lazyc[node] = 0;
    chk[node] = 0;
}
void updatea(ll lo, ll hi, ll left, ll right, ll node)
{
    if(chk[node]) propc(lo, hi, node);
    if(lazya[node]) propa(lo, hi, node);
    if(lazyb[node]) propb(lo, hi, node);
    if(lo > right || hi < left)
        return;
    if(lo >= left && hi <= right)
    {
        lazya[node] += lo - left + 1, cnta[node]++;
        tree[node] += ( ( 2 * (lo - left + 1) + hi - lo) * (hi - lo + 1) ) / 2;
        return;
    }
    ll mid = (lo + hi) / 2;
    updatea(lo, mid, left, right, 2 * node);
    updatea(mid + 1, hi, left, right, 2* node + 1);
    //cout << lo << "  " << hi << "  " << tree[2 * node] << "  " << tree[2 * node + 1] << " " << tree[node] << endl;
    tree[node] = tree[2 * node] + tree[2 * node + 1];
}
void updateb(ll lo, ll hi, ll left, ll right, ll node)
{
    if(chk[node]) propc(lo, hi, node);
    if(lazya[node]) propa(lo, hi, node);
    if(lazyb[node]) propb(lo, hi, node);
    if(lo > right || hi < left)
        return;
    if(lo >= left && hi <= right)
    {
        lazyb[node] += right - hi + 1, cntb[node]++;
        tree[node] += ( ( 2 * (right - hi + 1) + hi - lo) * (hi - lo + 1) ) / 2;
        return;
    }
    ll mid = (lo + hi) / 2;
    updateb(lo, mid, left, right, 2 * node);
    updateb(mid + 1, hi, left, right, 2* node + 1);
    tree[node] = tree[2 * node] + tree[2 * node + 1];
}
void updatec(ll lo, ll hi, ll left, ll right, ll x, ll node)
{
    if(chk[node]) propc(lo, hi, node);
    if(lazya[node]) propa(lo, hi, node);
    if(lazyb[node]) propb(lo, hi, node);
    if(lo > right || hi < left)
        return;
    if(lo >= left && hi <= right)
    {
        lazyc[node] = x, chk[node] = 1;
        tree[node] = (hi - lo + 1) * x;
        lazya[node] = 0, lazyb[node] = 0, cnta[node] = 0, cntb[node] = 0;
        return;
    }
    ll mid = (lo + hi) / 2;
    updatec(lo, mid, left, right, x,  2 * node);
    updatec(mid + 1, hi, left, right, x, 2* node + 1);
    tree[node] = tree[2 * node] + tree[2 * node + 1];
}
ll query(ll lo, ll hi, ll left, ll right, ll node)
{
    if(chk[node]) propc(lo, hi, node);
    if(lazya[node]) propa(lo, hi, node);
    if(lazyb[node]) propb(lo, hi, node);
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
    //freopen("out.txt", "w", stdout);
    ll t, caseno = 0, l, r, x;
    cin >> t;
    while(t--)
    {
        memset(tree, 0, sizeof(tree));
        memset(lazya, 0, sizeof(lazya));
        memset(lazyb, 0, sizeof(lazyb));
        memset(lazyc, 0, sizeof(lazyc));
        memset(cnta, 0, sizeof(cnta));
        memset(cntb, 0, sizeof(cntb));
        memset(chk, 0, sizeof(chk));
        ll q;
        printf("Case %lld:\n", ++caseno);
        scanf("%lld", &q);
        for(ll i = 1; i <= q; i++)
        {
            char ch;
            scanf(" %c", &ch);
            scanf("%lld %lld", &l, &r);
            if(ch == 'A')
            {
                updatea(1, siz, l, r, 1);
            }
            else if(ch == 'B')
            {
                updateb(1, siz, l, r, 1);
            }
            else if(ch == 'C')
            {
                scanf("%lld", &x);
                updatec(1, siz, l, r, x, 1);
            }
            else
            {
                printf("%lld\n", query(1, siz, l, r, 1));
            }
        }
    }
    return 0;
}

