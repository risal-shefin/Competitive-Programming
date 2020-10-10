#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
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

string s;

int main()

{
    fastio;
    ll t;
    cin >> t;
    while(t--) {
        ll n, b;
        cin >> n >> b;
        cin >> s;

        ll c0 = 0, c1 = 0, chk1 = 0, chk2 = 0, ans = b==0? 1 : 0;
        for(ll i = 0; i < s.length(); i++) {
            if(s[i] == '0') c0++;
            else            c1++;

            if(c0 - c1 == b) {
                chk1 = 1;
                ans++;
            }
        }

        ll diff = c0 - c1;
        if(diff == 0) {
            if(chk1)    cout << -1 << endl;
            else        cout << 0 << endl;
            continue;
        }

        c0 = 0, c1 = 0;
        for(ll i = 0; i < s.length(); i++) {
            if(s[i] == '0') c0++;
            else            c1++;

            ll d = c0 - c1;
            if( (b - d) % diff == 0) {
                if( (b-d) / diff > 0)
                    ans++;
            }
        }

        cout << ans << endl;
    }

    return 0;
}