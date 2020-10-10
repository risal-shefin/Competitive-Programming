#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define inf (1LL << 62)
#define mp make_pair
#define pb push_back
#define pll pair <ll, ll>

char ara[2009];
vector <pll> ans;

int main()

{
    ll t;
    cin >> t;
    while(t--) {
        ll n, k;
        scanf("%lld %lld", &n, &k);

        scanf("%s", ara+1);

        ll start = 1;
        for(ll i = 1; i < k; i++) {

            ll idx = 0;
            for(ll j = start; j <= n; j++) {
                if(ara[j] == '(') {
                    idx = j;
                    break;
                }
            }
            reverse(ara + start, ara + idx + 1);
            ans.pb(mp(start, idx));
            start++;

            idx = 0;
            for(ll j = start; j <= n; j++) {
                if(ara[j] == ')') {
                    idx = j;
                    break;
                }
            }
            reverse(ara + start, ara + idx + 1);
            ans.pb(mp(start, idx));
            start++;
        }

        ll baki = (n - start + 1);
        ll lagbe = baki / 2;
        for(ll i = 1; i <= lagbe; i++) {
            ll idx = 0;
            for(ll j = start; j <= n; j++) {
                if(ara[j] == '(') {
                    idx = j;
                    break;
                }
            }
            reverse(ara + start, ara + idx + 1);
            ans.pb(mp(start, idx));
            start++;
        }
        for(ll i = 1; i <= lagbe; i++) {
            ll idx = 0;
            for(ll j = start; j <= n; j++) {
                if(ara[j] == ')') {
                    idx = j;
                    break;
                }
            }
            reverse(ara + start, ara + idx + 1);
            ans.pb(mp(start, idx));
            start++;
        }

        printf("%lld\n", (ll)ans.size());
        for(pll p: ans) {
            printf("%lld %lld\n", p.first, p.second);
        }
        //cout << (ara + 1) << endl;

        ans.clear();
    }

    return 0;
}