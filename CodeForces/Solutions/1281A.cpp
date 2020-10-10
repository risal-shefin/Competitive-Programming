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

char s[1009];
char f[] = "op", j[] = "desu", j2[] = "masu", k[] = "adinm";
ll len;

bool cmp1() {
    if(len < 2)
        return 0;

    for(ll i = 0; i < 2; i++) {
        if(f[i] != s[i])
            return 0;
    }

    return 1;
}

bool cmp2() {
    if(len < 4)
        return 0;

    for(ll i = 0; i < 4; i++) {
        if(k[i] != s[i])
            return 0;
    }

    return 1;
}

int main()

{
    ll t;
    sl(t);
    while(t--) {
        scanf("%s", s);
        len = strlen(s);
        reverse(s, s + len);

        if(cmp1())
            printf("FILIPINO\n");
        else if(cmp2())
            printf("KOREAN\n");
        else
            printf("JAPANESE\n");
    }

    return 0;
}