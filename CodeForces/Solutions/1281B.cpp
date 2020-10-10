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
#define forn(i, stop) for(ll i = 1; i <= stop; i++)
#define rep(i, start) for(ll i = start; i >= 1; i--)
#define ms(n, i) memset(n, i, sizeof(n))
#define casep(n) printf("Case %lld:", ++n)
#define pn printf("\n")
#define pf printf
#define fastio std::ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

string s, c;

int main()

{
    fastio;
    ll t;
    cin >> t;
    while(t--) {
        cin >> s >> c;
        for(ll i = 0; i < s.length(); i++) {
            ll id = -1;
            char ch = 120;
            for(ll j = i+1; j < s.length(); j++) {
                if(s[j] <= ch) {
                    ch = s[j];
                    id = j;
                }
            }

            if(ch < s[i]) {
                swap(s[i], s[id]);
                break;
            }
        }


        if(s < c)
            cout << s << endl;
        else
            cout << "---" << endl;
    }
    return 0;
}