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
 
ll cnt[30], cnt2[30];
char s[106];
 
int main()
 
{
    ll t;
    sl(t);
    while(t--) {
        scanf("%s", s);
        ms(cnt, 0);
        for(ll i = 0; s[i] != '\0'; i++) {
            ll now = s[i] - 'a';
            cnt[now]++;
        }
 
        ll len = strlen(s);
        bool check = 0;
        scanf("%s", s);
        for(ll i = 0; s[i] != '\0'; i++) {
            ll last = i + len - 1;
 
            ms(cnt2, 0);
            for(ll j = i; j <= last && s[j] != '\0'; j++) {
                ll now = s[j] - 'a';
                cnt2[now]++;
            }
 
            check = 1;
            for(ll j = 0; j < 26; j++) {
                if(cnt[j] != cnt2[j]) {
                    check = 0;
                    break;
                }
            }
 
            if(check)
                break;
        }
 
        if(check)
            pf("YES\n");
        else
            pf("NO\n");
    }
 
    return 0;
}