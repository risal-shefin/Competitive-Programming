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
#define inf (1LL << 62)
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

const ll N = 4e5+10;
int tree[N][130], idx;
char s[2*N], s2[N];
ll len[N], link[N], cnt[N], t, cnt1[N];

void add(ll p) {

    while(s[p - len[t] - 1] != s[p]) t = link[t];   // searching node for creating pTp type palindrome.
    ll x = link[t], c = s[p];
    while(s[p - len[x] - 1] != s[p]) x = link[x];   // searching node to link pXp type palindrome, where pXp is a proper suffix.
    if(!tree[t][c]) {
        tree[t][c] = ++idx;
        len[idx] = len[t] + 2;
        link[idx] = len[idx] == 1 ? 2 : tree[x][c];
    }
    t = tree[t][c];
    cnt[t]++;
}

/* node 1 and node 2 are the two roots.
 * idx-2 is the number of total distinct palindromes in the string s.
 * Let, a node is i,
 * len[i] represents the length of the palindrome represented by node i.
 * link[i] represents the node containing the palindrome which is the largest proper suffix
 * of the palindrome of node i.
*/

void init_palTree()
{
    for(ll i = 0; i <= idx; i++) {
        cnt[i] = 0;

        for0(j, 130)
            tree[i][j] = 0;
    }

    len[1] = -1, link[1] = 1;
    len[2] = 0, link[2] = 1;
    idx = t = 2;
}

int main()
{
    ll t, cs = 0;
    cin >> t;
    while(t--) {
        scanf("%s", s+1);
        ll len = strlen(s+1), len1 = len;
        s[++len] = '$';

        scanf("%s", s2+1);
        for(ll i = 1; s2[i] != '\0'; i++)
            s[++len] = s2[i];

        init_palTree();
        for1(i, len1) add(i);

        for(ll i = idx; i > 2; i--) {
            cnt[ link[i] ] += cnt[i];
            cnt1[i] = cnt[i];
        }

        init_palTree();
        for1(i, len) add(i);

        ll ans = 0;
        for(ll i = idx; i > 2; i--) {
            cnt[ link[i] ] += cnt[i];

            ll cnt2 = cnt[i] - cnt1[i];
            ans += (cnt1[i] * cnt2);
        }

        pf("Case #%lld: %lld\n", ++cs, ans);

        for(ll i = 0; i <= idx; i++) cnt1[i] = 0;
    }

    return 0;
}