#include <bits/stdc++.h>
using namespace std;

#define ll long long

vector <ll> mon[100009];
ll joke[100009], cnt[100009];
set <ll> lst;

int main()

{
    ll t;
    cin >> t;
    while(t--) {
        memset(cnt, 0, sizeof(cnt));
        ll n, j;
        scanf("%lld %lld", &n, &j);

        for(ll i = 1; i <= j; i++) {
            ll x, l, k;
            scanf("%lld %lld %lld", &x, &l, &k);
            ll start = max(1LL, x - k);
            ll stop = min(n, x + k);

            mon[start].push_back(i);
            mon[stop + 1].push_back(-i);
            joke[i] = l;
        }

        ll ans = 0;
        for(ll i = 1; i <= n; i++) {
            for(ll j = 0; j < mon[i].size(); j++) {
                ll no = mon[i][j];
                if(no > 0) {
                    lst.insert(no);
                    cnt[ joke[no] ]++;
                }
                else {
                    lst.erase(-no);
                    cnt[ joke[-no] ]--;
                }
            }

            if(lst.empty())
                ans++;
            else if(cnt[ joke[*(--lst.end())] ] > 1)
                ans++;
        }

        printf("%lld\n", ans);
        lst.clear();
        for(ll i = 0; i <= 100005; i++)
            mon[i].clear();
    }

    return 0;
}