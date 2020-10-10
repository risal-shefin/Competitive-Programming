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

const ll sz = 105, tsz = sz*sz;

int trie[tsz][sz], idx[tsz], root = 0, node = 0;
unordered_map <string, int> check[tsz];

void solvePath(string &path, vector <string> &v)
{
    string now = "";
    for(char &ch : path) {

        if(ch == '\\') {
            v.pb(now);
            now = "";
        }
        else
            now.pb(ch);
    }
    v.pb(now);
}

void add(string &path)
{
    vector <string> pathCut;
    solvePath(path, pathCut);

    int cur = root;

    for(string &s : pathCut) {
        int id;
        if(check[cur].find(s) == check[cur].end())
            check[cur][s] = id = ++idx[cur];
        else
            id = check[cur][s];

        if(trie[cur][id] == -1)
            trie[cur][id] = ++node;

        cur = trie[cur][id];
    }
}

pii query(int cur, int lev)
{
    int leaf = 1;
    pii ret = mp(0, 0);

    for(ll i = 1; trie[cur][i] != -1; i++) {

        pii got = query(trie[cur][i], lev+1);
        leaf = 0;

        if(lev >= 1) ret.first += got.first, ret.second += got.second;
        else ret = max(ret, got);
    }

    if(leaf) return mp(0, 1);

    if(lev > 1) ret.first++;
    return ret;
}

int main()
{
    fastio;

    ms(trie, -1);

    string s;
    while(cin >> s) {
        add(s);
    }

    pii ans = mp(0,0);
    for(int i = 1; trie[root][i] != -1; i++) {
        ans = max(ans, query(trie[root][i], 0));
    }

    cout << ans.first << " " << ans.second << EL;

    return 0;
}