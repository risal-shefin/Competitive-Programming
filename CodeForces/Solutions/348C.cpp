#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define block 316

ll ara[100009];
vector <ll> heavy, st[100009];
ll sum[100009], incr[100009];

struct node {
    ll no;
    ll cnt;

    node(ll _no, ll _cnt) {
        no = _no;
        cnt = _cnt;
    }
};
vector <node> inter[100009];

int main()

{
    ll n, k, q;
    cin >> n >> k >> q;
    for(ll i = 1; i <= n; i++)
        scanf("%lld", &ara[i]);

    for(ll i = 1; i <= k; i++) {
        ll sz;
        scanf("%lld", &sz);
        if(sz > block)
            heavy.pb(i);

        for(ll j = 0; j < sz; j++) {
            ll in;
            scanf("%lld", &in);
            st[i].pb(in);
            sum[i] += ara[in];
        }

        sort(st[i].begin(), st[i].end());
    }

    ll pos, x, cnt;
    for(ll i = 0; i < heavy.size(); i++) {

        for(ll j = 1; j <= k; j++) {

            if(j == heavy[i])
                continue;

            cnt = 0;
            for(ll m = 0; m < st[j].size(); m++) {
                x = st[j][m];
                pos = lower_bound(st[ heavy[i] ].begin(), st[ heavy[i] ].end(), x) - st[ heavy[i] ].begin();
                if(pos != st[ heavy[i] ].size()) {
                    if(st[ heavy[i] ][pos] == x)
                        cnt++;
                }
            }

            inter[j].pb( node(heavy[i], cnt) );
        }
    }

    char ch;
    for(ll i = 1; i <= q; i++) {
        scanf(" %c", &ch);
        if(ch == '+') {
            ll no, ad;
            scanf("%lld %lld", &no, &ad);

            if(st[no].size() <= block) {
                for(ll j = 0; j < st[no].size(); j++)
                    ara[ st[no][j] ] += ad;

                for(ll j = 0; j < inter[no].size(); j++)
                    sum[ inter[no][j].no ] += inter[no][j].cnt * ad;
            }

            else {
                incr[no] += ad;
                for(ll j = 0; j < inter[no].size(); j++)
                    sum[ inter[no][j].no ] += inter[no][j].cnt * ad;
            }
        }
        else {
            ll no, ans = 0;
            scanf("%lld", &no);

            if(st[no].size() <= block) {
                for(ll j = 0; j < st[no].size(); j++)
                    ans += ara[ st[no][j] ];

                for(ll j = 0; j < inter[no].size(); j++)
                    ans += inter[no][j].cnt * incr[ inter[no][j].no ];

                printf("%lld\n", ans);
            }
            else {
                ans = sum[no] + incr[no] * st[no].size();
                printf("%lld\n", ans);
            }
        }

    }

    return 0;
}