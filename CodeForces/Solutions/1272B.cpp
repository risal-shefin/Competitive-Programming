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
 
int main()
 
{
    ll n;
    sl(n);
    while(n--) {
        scanf("%s", s+1);
        ll len = strlen(s+1);
 
        ll cl = 0, cr = 0, cu = 0, cd = 0;
        for(ll i = 1; i <= len; i++) {
            if(s[i] == 'L')
                cl++;
            if(s[i] == 'R')
                cr++;
            if(s[i] == 'U')
                cu++;
            if(s[i] == 'D')
                cd++;
        }
 
        if(cl > cr)
            cl = cr;
        else
            cr = cl;
 
        if(cu > cd)
            cu = cd;
        else
            cd = cu;
 
        if(cl > 1 && cu+cd == 0) {
            pf("2\n");
            pf("LR\n");
        }
        else if(cd > 1 && cl+cr == 0) {
            pf("2\n");
            pf("DU\n");
        }
        else if(cl == 0 && cd == 0) {
            pf("0\n\n");
        }
        else {
            pf("%lld\n", cl+cr+cd+cu);
 
            forn(i, cl)
                pf("L");
            forn(i, cu)
                pf("U");
            forn(i, cr)
                pf("R");
            forn(i, cd)
                pf("D");
 
            pf("\n");
        }
    }
 
    return 0;
}