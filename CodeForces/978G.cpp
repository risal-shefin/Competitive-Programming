#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define inf 1e18
#define sl(val) scanf("%lld", &val)
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
