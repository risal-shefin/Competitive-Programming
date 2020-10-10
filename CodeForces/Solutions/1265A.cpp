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
 
char s[100009];
 
bool ase[200];
 
int main()
 
{
    ll t;
    sl(t);
    while(t--) {
        scanf("%s", s);
        ll len = strlen(s);
 
        bool chk = 1;
        for(ll i = 0; i < len; i++) {
            if(s[i] == s[i+1] && s[i] != '?') {
                chk = 0;
                break;
            }
            if(s[i] != '?')
                continue;
 
            memset(ase, 0, sizeof(ase));
            if(i != 0)
                ase[s[i-1] - 'a'] = 1;
            if(i != len - 1)
                ase[s[i+1] - 'a'] = 1;
 
            for(ll j = 0; j < 3; j++) {
                if(!ase[j]) {
                    s[i] = j + 'a';
                    break;
                }
            }
        }
 
        if(!chk) {
            pf("-1\n");
            continue;
        }
        printf("%s\n", s);
    }
 
    return 0;
}