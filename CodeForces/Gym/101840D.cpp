#include <bits/stdc++.h>
using namespace std;

#define ll long long

vector <ll> divv[100009], mul[100009];
ll ara[100009], n, par[100009], lst[100009];
bool check[100009];

bool cmp(ll a, ll b)

{
    return a > b;
}

ll findr(ll u)

{
    if(par[u] == u) return u;
    return par[u] = findr(par[u]);
}

int main()

{
    freopen("dream.in","r",stdin);
    for(ll i = 1; i <= 100000; i++) {
        for(ll j = i; j <= 100000; j += i) {
            divv[j].push_back(i);
        }
    }

    ll t, caseno = 0, prv;
    cin >> t;
    while(t--) {

        for(ll i = 0; i <= 100000; i++) {
            mul[i].clear();
            check[i] = 0;
        }

        vector <ll> num;
        scanf("%lld", &n);
        for(ll i = 0; i < n; i++) {
            scanf("%lld", &ara[i]);
            par[ i ] = i;
        }

        for(ll i = 0; i < n; i++) {
            ll x = ara[i];

            for(ll j = 0; j < divv[x].size(); j++) {
                ll y = divv[x][j];
                mul[ y ].push_back(i);
                if(check[y] == 0) {
                    check[y] = 1;
                    num.push_back(y);
                }
            }

        }

        sort(num.begin(), num.end(), cmp);

        ll ans = 0;
        for(ll i = 0; i < num.size(); i++) {
            ll cnt = 0, indx = 0;
            ll y = num[i];

            for(ll j = 0; j < mul[y].size(); j++) {
                lst[indx++] = mul[y][j];
            }

            if(indx < 2)
                continue;

            ll pu = findr(lst[0]);
            for(ll j = 1; j < indx; j++) {
                ll pv = findr(lst[j]);
                if(pu != pv) {
                    ans += y;
                    par[pv] = pu;
                }
            }

        }

        printf("Case %lld: %lld\n", ++caseno, ans);
    }

    return 0;
}