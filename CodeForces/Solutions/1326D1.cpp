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

const ll MAX_N = 1e6+10, mod = 2e9+63, base1 = 1e9+21, base2 = 1e9+181;
char s[MAX_N];  // 1-indexed
ll pw1[MAX_N], pw2[MAX_N], slen;

void pw_calc() {
    pw1[0] = pw2[0] = 1;
    for(int i = 1; i < MAX_N; i++) {
        pw1[i] = (pw1[i-1] * base1) % mod;
        pw2[i] = (pw2[i-1] * base2) % mod;
    }
}

struct Hash {
    ll h1[MAX_N], h2[MAX_N];

    void init() {
        h1[0] = h2[0] = 0;
        for(int i = 1; i <= slen; i++) {
            h1[i] = (h1[i-1] * base1 + s[i]) % mod;
            h2[i] = (h2[i-1] * base2 + s[i]) % mod;
        }
    }

    inline ll hashVal(int l, int r) {
        ll hsh1 = (h1[r] - h1[l-1] * pw1[r-l+1]) % mod;
        if(hsh1 < 0) hsh1 += mod;
        ll hsh2 = (h2[r] - h2[l-1] * pw2[r-l+1]) % mod;
        if(hsh2 < 0) hsh2 += mod;
        return (hsh1 << 32) | hsh2;
    }

    inline ll hashOne(int l, int r) {
        ll hsh1 = (h1[r] - h1[l-1] * pw1[r-l+1]) % mod;
        if(hsh1 < 0) hsh1 += mod;
        return hsh1;
    }

    inline ll hashTwo(int l, int r) {
        ll hsh2 = (h2[r] - h2[l-1] * pw2[r-l+1]) % mod;
        if(hsh2 < 0) hsh2 += mod;
        return hsh2;
    }
} fw, bw;

/* call pw_calc() for calculating powers less than MAX_N
 * slen = strlen(s+1);   --> string length
 * fw.init() will calculate the double hashes
 * fw.hashVal(l,r) will return [l,,r] merged double hash value
 * fw.hashOne(l, r) will return [l,,r] base1 hash
 * fw.hashTwo(l, r) will return [l,,r] base2 hash
*/

bool checkPal(int pref, int suf) {
    ll h1 = (fw.hashOne(1, pref) * pw1[slen-suf+1] + fw.hashOne(suf, slen)) % mod;
    ll h2 = (fw.hashTwo(1, pref) * pw2[slen-suf+1] + fw.hashTwo(suf, slen)) % mod;
    h1 = (h1 << 32) | h2;

    ll rh1 = (bw.hashOne(1, slen-suf+1) * pw1[pref] + bw.hashOne(slen-pref+1, slen)) % mod;
    ll rh2 = (bw.hashTwo(1, slen-suf+1) * pw2[pref] + bw.hashTwo(slen-pref+1, slen)) % mod;
    rh1 = (rh1 << 32) | rh2;

    return h1 == rh1;
}

int main()
{
    pw_calc();

    ll t;
    cin >> t;
    while(t--) {
        scanf("%s", s+1);
        slen = strlen(s+1);

        fw.init();
        reverse(s+1, s+slen+1);
        bw.init();
        reverse(s+1, s+slen+1);

        ll chk = 1, mat = 0, p = -1, sf = -1, mx = 0;
        for(ll i = 1, j = slen; i <= slen; i++, j--) {
            if(chk && s[i] == s[j]) mat++;
            else    chk = 0;

            ll h = fw.hashVal(1, i);
            ll rh = bw.hashVal(slen-i+1, slen);
            if(h == rh && i > mx)
                mx = i, p = i, sf = -1;

            h = fw.hashVal(j, slen);
            rh = bw.hashVal(1, slen-j+1);
            if(h == rh && i > mx)
                mx = i, p = -1, sf = j;

            if(mat > 0 && i+mat <= slen) {

                if(checkPal(i, slen-mat+1))
                    mx = i+mat, p = i, sf = slen-mat+1;

                if(checkPal(mat, j))
                    mx = slen-j+1 + mat, p = mat, sf = j;
            }
        }

        if(p == -1) {
            for(ll i = sf; i <= slen; i++)
                pf("%c", s[i]);
        }
        else if(sf == -1) {
            for(ll i = 1; i <= p; i++)
                pf("%c", s[i]);
        }
        else {
            for(ll i = 1; i <= p; i++)
                pf("%c", s[i]);
            for(ll i = sf; i <= slen; i++)
                pf("%c", s[i]);
        }
        pn;
    }

    return 0;
}