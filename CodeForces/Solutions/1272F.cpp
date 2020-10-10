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
 
char s1[205], s2[205];
ll len1, len2, dp[209][209][409];
 
ll solve(ll i, ll j, ll diff) {
 
    ll &ret = dp[i][j][diff];
    if(i >= len1 && j >= len2) {
        return ret = diff;
    }
    if(ret != -1)
        return ret;
 
    ll rt = inf;
    if(i < len1) {
        if(s1[i] == '(')
           rt = min(rt, 1+solve(i+1, j, diff+1));
        else {
            if(diff - 1 >= 0)
                rt = min(rt, 1+solve(i+1, j, diff-1) );
            else
                rt = min(rt, 2+solve(i+1, j, 0) );
        }
    }
    if(j < len2) {
        if(s2[j] == '(')
           rt = min(rt, 1+solve(i, j+1, diff+1));
        else {
            if(diff - 1 >= 0)
                rt = min(rt, 1+solve(i, j+1, diff-1) );
            else
                rt = min(rt, 2+solve(i, j+1, 0) );
        }
    }
    if(i < len1 && j < len2) {
        if(s1[i] == s2[j]) {
            if(s2[j] == '(')
                rt = min(rt, 1+solve(i+1, j+1, diff+1));
            else {
                if(diff - 1 >= 0)
                    rt = min(rt, 1+solve(i+1, j+1, diff-1) );
                else
                    rt = min(rt, 2+solve(i+1, j+1, 0) );
            }
        }
    }
 
    return ret = rt;
}
 
void print(ll i, ll j, ll diff) {
 
    if(i >= len1 && j >= len2) {
        forn(i, diff)
            pf(")");
        pn;
        return;
    }
    ll &ret = dp[i][j][diff];
 
    if(i < len1) {
        if(s1[i] == '(') {
            if(ret - 1 == dp[i+1][j][diff+1]) {
                pf("(");
                print(i+1, j, diff+1);
                return;
            }
        }
        else {
            if(diff - 1 >= 0) {
                if(ret - 1 == dp[i+1][j][diff-1]) {
                    pf(")");
                    print(i+1, j, diff-1);
                    return;
                }
            }
            else {
                if(ret - 2 == dp[i+1][j][0]) {
                    pf("()");
                    print(i+1, j, 0);
                    return;
                }
            }
        }
    }
    if(j < len2) {
        if(s2[j] == '(') {
           if(ret - 1 == dp[i][j+1][diff+1]) {
                pf("(");
                print(i, j+1, diff+1);
                return;
            }
        }
        else {
            if(diff - 1 >= 0) {
                if(ret - 1 == dp[i][j+1][diff-1]) {
                    pf(")");
                    print(i, j+1, diff-1);
                    return;
                }
            }
            else {
                if(ret - 2 == dp[i][j+1][0]) {
                    pf("()");
                    print(i, j+1, 0);
                    return;
                }
            }
        }
    }
    if(i < len1 && j < len2) {
        if(s1[i] == s2[j]) {
            if(s2[j] == '(') {
                if(ret - 1 == dp[i+1][j+1][diff+1]) {
                    pf("(");
                    print(i+1, j+1, diff+1);
                    return;
                }
            }
            else {
                if(diff - 1 >= 0) {
                    if(ret - 1 == dp[i+1][j+1][diff-1]) {
                        pf(")");
                        print(i+1, j+1, diff-1);
                        return;
                    }
                }
                else {
                    if(ret - 2 == dp[i+1][j+1][0]) {
                        pf("()");
                        print(i+1, j+1, 0);
                        return;
                    }
                }
            }
        }
    }
 
    return;
}
 
int main()
 
{
    scanf("%s %s", s1, s2);
    len1 = strlen(s1);
    len2 = strlen(s2);
 
    ms(dp, -1);
    ll ret = solve(0, 0, 0);
    //cout << ret << endl;
    print(0, 0, 0);
 
    return 0;
}