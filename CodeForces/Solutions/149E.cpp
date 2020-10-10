// #pragma GCC optimize("Ofast,unroll-loops")
// #pragma GCC target("avx,avx2,fma")

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
#define all(v) v.begin(), v.end()
#define inf (1LL << 61)
#define loop(i, start, stop, inc) for(ll i = start; i <= stop; i += inc)
#define for1(i, stop) for(ll i = 1; i <= stop; ++i)
#define for0(i, stop) for(ll i = 0; i < stop; ++i)
#define rep1(i, start) for(ll i = start; i >= 1; --i)
#define rep0(i, start) for(ll i = (start-1); i >= 0; --i)
#define ms(n, i) memset(n, i, sizeof(n))
#define casep(n) printf("Case %lld:", ++n)
#define pn printf("\n")
#define pf printf
#define EL '\n'
#define fastio std::ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

const ll MAX_N = 1e5+10, MAX_N2 = 1e3 + 10;
char s[MAX_N], revs[MAX_N], s2[MAX_N2];  // 1-indexed
ll prefEnd[MAX_N2], lps[MAX_N2];

void gen_lps(ll len)
{
    ll now;
    lps[0] = lps[1] = now = 0;

    for(ll i = 2; i <= len; i++) {

        while(now != 0 && s2[now+1] != s2[i])
            now = lps[now];

        if(s2[now+1] == s2[i]) lps[i] = ++now;
        else lps[i] = now = 0;
    }
}

ll KMP(ll slen, ll len)
{
    for(ll i = 0; i <= len; i++) prefEnd[i] = inf;

    ll now = 0;

    for1(i, slen) {

        while(now != 0 && s2[now+1] != s[i])
            now = lps[now];

        if(s2[now+1] == s[i]) ++now;
        else now = 0;

        prefEnd[now] = min(prefEnd[now], i);

        if(now == len) return 1;
    }
    return 0;
}

ll find_with_KMP(ll slen, ll len)
{
    ll now = 0;

    for1(i, slen) {

        while(now != 0 && s2[now+1] != revs[i])
            now = lps[now];

        if(s2[now+1] == revs[i]) {
            ++now;

            ll realIndex = slen - i + 1, prefLen = len - now;

            if(prefEnd[prefLen] < realIndex) return 1;
        }
        else now = 0;
    }

    return 0;
}

int main()
{
    scanf("%s", s+1);
    ll slen = strlen(s+1);

    strcpy(revs+1, s+1);
    reverse(revs+1, revs+slen+1);

    ll ans = 0, m;
    cin >> m;

    while(m--) {
        scanf("%s", s2+1);
        ll len = strlen(s2+1);

        if(len == 1) continue;

        gen_lps(len);
        ll got = KMP(slen, len);

        if(got) {
            ans++;
            continue;
        }

        reverse(s2+1, s2+len+1);

        gen_lps(len);

        got = find_with_KMP(slen, len);
        if(got) ans++;
    }

    cout << ans << EL;

    return 0;
}