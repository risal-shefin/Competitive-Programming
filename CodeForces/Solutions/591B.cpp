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

const ll sz = 2e5 + 10;
char s1[sz], s2[sz];
vector <ll> pos[30];
ll now[30];

int main()
{
    ms(now, -1);
    ll n, m;
    cin >> n >> m;
    scanf("%s", s1);

    for0(i, n) {
        ll c = s1[i] - 'a';
        pos[c].pb(i);
        now[c] = c;
    }

    while(m--) {
        char aa, bb;
        scanf(" %c %c", &aa, &bb);

        ll a = aa - 'a', b = bb - 'a';

        ll tmp = now[b];
        now[b] = now[a];
        now[a] = tmp;
    }

    for(ll i = 0; i < 26; i++) {
        char ch = i + 'a';
        if(now[i] == -1) continue;
        ll p = now[i];

        for(ll j = 0; j < pos[p].size(); j++) s2[ pos[p][j] ] = ch;
    }
    s2[n] = '\0';
    pf("%s\n", s2);

    return 0;
}