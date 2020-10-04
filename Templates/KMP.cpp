#define ll long long
const ll MAX_N = 1e5+10;

char s[MAX_N], pat[MAX_N];  // 1-indexed
ll lps[MAX_N];     // lps[i] = longest proper prefix-suffix in i length's prefix

void gen_lps(ll plen)
{
    ll now;
    lps[0] = lps[1] = now = 0;

    for(ll i = 2; i <= plen; i++) {

        while(now != 0 && pat[now+1] != pat[i])
            now = lps[now];

        if(pat[now+1] == pat[i]) lps[i] = ++now;
        else lps[i] = now = 0;
    }
}

ll KMP(ll slen, ll plen)
{
    ll now = 0;

    for(ll i = 1; i <= slen; i++) {

        while(now != 0 && pat[now+1] != s[i])
            now = lps[now];

        if(pat[now+1] == s[i]) ++now;
        else now = 0;

        // now is the length of the longest prefix of pat, which
        // ends as a substring of s in index i.

        if(now == plen) return 1;
    }

    return 0;
}

// slen = length of s, plen = length of pat
// call gen_lps(plen); to generate LPS (failure) array
// call KMP(slen, plen) to find pat in s
