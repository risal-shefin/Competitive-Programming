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
 
ll cs = 0;
char s[200009];
ll v[30], len, dp[150009][8];
ll check[150009][8];
bool f = 0;
 
ll solve(ll pos, ll prv) {
    if(pos >= len)
        return dp[pos][prv] = 0;
 
    ll &ret = dp[pos][prv];
    if(check[pos][prv] == cs)
        return ret;
 
    check[pos][prv] = cs;
 
    ll rt2 = 1 + solve(pos + 1, prv), rt = inf;
    if(s[pos] == 'o') {
        if(prv != 5)
            rt = solve(pos + 1, 1);
    }
    else if(s[pos] == 'n') {
        if(prv != 1)
            rt = solve(pos + 1, 0);
        else
            rt = solve(pos + 1, 2);
    }
    else if(s[pos] == 'e') {
        if(prv != 2)
            rt = solve(pos + 1, 0);
    }
    else if(s[pos] == 't')
        rt = solve(pos + 1, 4);
    else if(s[pos] == 'w') {
        if(prv != 4)
            rt = solve(pos + 1, 0);
        else
            rt = solve(pos + 1, 5);
    }
    else
        rt = solve(pos + 1, 0);
 
    return ret = min(rt, rt2);
}
 
void print(ll pos, ll prv) {
    if(pos >= len)
        return;
 
    ll &ret = dp[pos][prv];
 
    if(ret - 1 == dp[pos+1][prv]) {
        if(f)
            pf(" ");
        f = 1;
        pf("%lld", pos+1);
        print(pos + 1, prv);
        return;
    }
 
    if(s[pos] == 'o') {
        if(prv != 5) {
            if(ret == dp[pos+1][1]) {
                print(pos+1, 1);
                return;
            }
        }
    }
    else if(s[pos] == 'n') {
        if(prv != 1) {
            if(ret == dp[pos+1][0]) {
                print(pos+1, 0);
                return;
            }
        }
        else {
            if(ret == dp[pos+1][2]) {
                print(pos+1, 2);
                return;
            }
        }
    }
    else if(s[pos] == 'e') {
        if(prv != 2) {
            if(ret == dp[pos+1][0]) {
                print(pos+1, 0);
                return;
            }
        }
    }
    else if(s[pos] == 't') {
        if(ret == dp[pos+1][4]) {
            print(pos+1, 4);
            return;
        }
    }
    else if(s[pos] == 'w') {
        if(prv != 4) {
            if(ret == dp[pos+1][0]) {
                print(pos+1, 0);
                return;
            }
        }
        else {
            if(ret == dp[pos+1][5]) {
                print(pos+1, 5);
                return;
            }
        }
    }
    else {
        if(ret == dp[pos+1][0]) {
            print(pos+1, 0);
            return;
        }
    }
 
    return;
}
 
int main()
 
{
    v['o' - 'a'] = 1, v['n' - 'a'] = 2, v['e' -  - 'a'] = 3;
    v['t' - 'a'] = 4, v['w' - 'a'] = 5;
 
    ll t;
    sl(t);
    while(t--) {
        cs++;
        scanf("%s", s);
        len = strlen(s);
 
        ll ans = solve(0, 0);
 
        pf("%lld\n", ans);
 
        f = 0;
        print(0, 0);
        pn;
    }
 
    return 0;
}