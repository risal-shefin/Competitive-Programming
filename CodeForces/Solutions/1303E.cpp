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

ll dp[405][405], nxt[405][26];
string s1, s2;

bool check(ll lena)
{
    ll lenb = s2.length() - lena;
    for(ll i = 0; i <= lena; i++)
        for(ll j = 0; j <= lenb; j++)
            dp[i][j] = inf;

    dp[0][0] = 0;

    for(ll i = 0; i <= lena; i++) {
        for(ll j = 0; j <= lenb; j++) {
            if(dp[i][j] == inf)
                continue;

            ll lens = dp[i][j], cha = (ll)s2[i]-'a', chb = (ll)s2[lena+j]-'a';

            if(i < lena)    dp[i+1][j] = min(dp[i+1][j], nxt[lens][cha] + 1);

            if(j < lenb)    dp[i][j+1] = min(dp[i][j+1], nxt[lens][chb] + 1);
        }
    }

    return dp[lena][lenb] != inf;
}

int main()
{
    fastio;
    ll t;
    cin >> t;
    while(t--) {
        cin >> s1 >> s2;

        for(ll i = 1; i <= s1.length(); i++) {
            for0(j, 26)
                nxt[i][j] = inf;
        }

        rep0(i, s1.length()) {
            for0(j, 26)
                nxt[i][j] = nxt[i+1][j];

            nxt[i][ s1[i]-'a' ] = i;
        }

        bool chk = 0;
        for(ll i = 0; i < s2.length(); i++) {
            if(check(i+1)) {
                chk = 1;
                break;
            }
        }

        if(chk)
            pf("YES\n");
        else
            pf("NO\n");
    }

    return 0;
}