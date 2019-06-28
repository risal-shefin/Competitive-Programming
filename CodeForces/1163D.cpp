#include <bits/stdc++.h>
using namespace std;
#define ll long long
string s, a, b;
ll lps1[1009], lps2[1009], nxt1[55][30], nxt2[55][30];
ll dp[1009][55][55];
bool vis[1009][55][55];
void computeLPS1()
{
    lps1[0] = 0;
    ll len = 0, i = 1;
    while(i < a.length()) {
        if(a[i] == a[len]) {
            len++;
            lps1[i] = len;
            i++;
        }
        else {
            if(len != 0)
                len = lps1[len - 1];
            else {
                lps1[i] = 0;
                i++;
            }
        }
    }
}
void computeLPS2()
{
    lps2[0] = 0;
    ll len = 0, i = 1;
    while(i < b.length()) {
        if(b[i] == b[len]) {
            len++;
            lps2[i] = len;
            i++;
        }
        else {
            if(len != 0)
                len = lps2[len - 1];
            else {
                lps2[i] = 0;
                i++;
            }
        }
    }
}
void preprocess()
{
    for(ll i = 0; i < a.length(); i++) {
        for(char ch = 'a'; ch <= 'z'; ch++) {
            ll cur = i;
            while(cur > 0) {
                if(a[cur] == ch) break;
                cur = lps1[cur - 1];
            }
            if(a[cur] == ch) cur++;
            nxt1[i][ch - 'a'] = cur;
        }
    }
    for(ll i = 0; i < b.length(); i++) {
        for(char ch = 'a'; ch <= 'z'; ch++) {
            ll cur = i;
            while(cur > 0) {
                if(b[cur] == ch) break;
                cur = lps2[cur - 1];
            }
            if(b[cur] == ch) cur++;
            nxt2[i][ch - 'a'] = cur;
        }
    }
}
ll solve(ll pos, ll posa, ll posb)
{
    if(pos == s.length()) {
        ll rt = (posa == a.length()) - (posb == b.length());
        return rt;
    }
    ll &ret = dp[pos][posa][posb];
    if(vis[pos][posa][posb])
        return ret;
    //cout << posa << "  " << posb << "  " << pos << endl;
    ll val = (posa == a.length()) - (posb == b.length());
    if(posa == a.length()) posa = lps1[a.length() - 1];
    if(posb == b.length()) posb = lps2[b.length() - 1];
    ret = -1e18;
    if(s[pos] == '*') {
        for(char ch = 'a'; ch <= 'z'; ch++) {
            ll rt = solve(pos+1, nxt1[posa][ch-'a'], nxt2[posb][ch-'a']);
            ret = max(ret, val + rt);
        }
    }
    else {
        ll rt = solve(pos+1, nxt1[posa][s[pos] - 'a'], nxt2[posb][s[pos] - 'a']);
        ret = max(ret, val + rt);
    }
    vis[pos][posa][posb] = 1;
    return ret;
}
int main()
{
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> s >> a >> b;
    computeLPS1(), computeLPS2();
    preprocess();
    cout << solve(0, 0, 0) << endl;
    return 0;
}
