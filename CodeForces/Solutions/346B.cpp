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

const ll sz = 105;
ll dp[sz][sz][sz], len1, len2, len3;
ll prefMatch[sz][26];

char s1[sz], s2[sz], s3[sz];
string ans;

ll solve(ll pos1, ll pos2, ll pos3)
{
    if(pos3 > len3)
        return -inf;

    if(pos1 > len1 || pos2 > len2)
        return 0;

    ll &ret = dp[pos1][pos2][pos3];
    if(ret != -1)
        return ret;

    ret = solve(pos1+1, pos2, pos3);
    ret = max(ret, solve(pos1, pos2+1, pos3));

    if(s1[pos1] == s2[pos2]) {

        if(s3[pos3] == s1[pos1])
            ret = max(ret, 1 + solve(pos1+1, pos2+1, pos3+1));
        else {

            ll mx = (s3[1] == s1[pos1]) ? 1 : 0, ch = s1[pos1] - 'A';;

            mx = max(mx, prefMatch[pos3-1][ch]);

            ret = max(ret, 1 + solve(pos1+1, pos2+1, mx+1));
        }
    }

    return ret;
}

void make_ans(ll pos1, ll pos2, ll pos3, ll res)
{
    if(pos1 > len1 || pos2 > len2)
        return;

    if(solve(pos1+1, pos2, pos3) == res) make_ans(pos1+1, pos2, pos3, res);
    else if(solve(pos1, pos2+1, pos3) == res) make_ans(pos1, pos2+1, pos3, res);
    else {
        ans.pb(s1[pos1]);

        if(s3[pos3] == s1[pos1])
            make_ans(pos1+1, pos2+1, pos3+1, res-1);
        else {

            ll mx = (s3[1] == s1[pos1]) ? 1 : 0, ch = s1[pos1] - 'A';

            mx = max(mx, prefMatch[pos3-1][ch]);

            make_ans(pos1+1, pos2+1, mx+1, res-1);
        }
    }
}

int main()
{
    scanf("%s %s %s", s1+1, s2+1, s3+1);

    len1 = strlen(s1+1);
    len2 = strlen(s2+1);
    len3 = strlen(s3+1);

    for1(i, len3) {
        for(ll j = i, k = 1; j <= len3; j++, k++) {
            if(s3[j] != s3[k])
                break;

            if(k+1 <= len3) {
                ll ch = s3[k+1] - 'A';
                prefMatch[j][ch] = max(prefMatch[j][ch], k+1);
            }
        }
    }

    ms(dp, -1);
    ll got = solve(1, 1, 1);

    if(got == 0) {
        cout << 0 << EL;
        return 0;
    }

    make_ans(1, 1, 1, got);

    cout << ans << EL;

    return 0;
}