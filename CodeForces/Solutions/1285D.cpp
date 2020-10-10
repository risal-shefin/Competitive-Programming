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

ll ara[100009];
struct trie {
    trie *nxt[2];
    trie() {
        nxt[0] = nxt[1] = nullptr;
    }
};
trie *start;

void add(ll num)
{
    trie *cur = start;
    for(ll i = 32; i >= 0; i--) {
        bool bit = (num >> i) & 1;
        if(cur -> nxt[bit] == nullptr)
            cur->nxt[bit] = new trie();

        cur = cur->nxt[bit];
    }
}

ll solve(ll bit, trie *cur)
{
    if(bit < 0)
        return 0;

    if(cur->nxt[0] != nullptr && cur->nxt[1] != nullptr)
        return (1LL << bit) + min(solve(bit-1, cur->nxt[0]), solve(bit-1, cur->nxt[1]));

    if(cur->nxt[0] != nullptr)
        return solve(bit-1, cur->nxt[0]);

    else if(cur->nxt[1] != nullptr)
        return solve(bit-1, cur->nxt[1]);
}

int main()

{
    start = new trie();
    ll n;
    sl(n);
    for1(i, n) {
        sl(ara[i]);
        add(ara[i]);
    }

    ll ans = solve(32, start);
    cout << ans << endl;

    return 0;
}