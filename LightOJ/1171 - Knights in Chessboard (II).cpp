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

// === Debug macro starts here ===
#ifndef ONLINE_JUDGE
#define DEBUG
#define SYS_COL system("COLOR")
#endif

int recur_depth = 0;
#ifdef DEBUG
#define dbg(x) {++recur_depth; auto x_=x; --recur_depth; SYS_COL; \
                cerr<<string(recur_depth, '\t')<<"\e[91m"<<__func__<<":" \
                <<__LINE__<<"\t"<<#x<<" = "<<x_<<"\e[39m"<<endl;}

template<typename Ostream, typename Cont>
typename enable_if<is_same<Ostream,ostream>::value,
            Ostream&>::type operator<<(Ostream& os,  const Cont& v) {
	os<<"[";
	for(auto& x:v){os<<x<<", ";}
	return os<<"]";
}
template<typename Ostream, typename ...Ts>
Ostream& operator<<(Ostream& os,  const pair<Ts...>& p){
	return os<<"{"<<p.first<<", "<<p.second<<"}";
}
#else
#define dbg(x)
#endif
// === Debug macro ends here ===

#define ff first
#define ss second

const ll sz = 201, hsz = sz*sz/2;
bool mat[sz][sz];
ll num[sz][sz];

// Max Bipartite Matching
ll n, k; // n = left part size, k = right part size;
vector <int> g[hsz];
ll lft[hsz], rgt[hsz];
bitset <hsz> used, used1;

bool try_kuhn(ll v)
{
    for (int &to : g[v]) {
        if(used[to]) continue;
        used[to] = 1;

        if(rgt[to]==-1 || try_kuhn(rgt[to])) {
            lft[v] = to, rgt[to] = v;
            return true;
        }
    }
    return false;
}
ll kuhn()
{
    ll ret = 0;
    for0(i, max(n,k)) lft[i] = rgt[i] = -1;

    bool new_mat = 1;

    while(new_mat) {
        used.reset();
        new_mat = 0;

        for(ll v=0; v<n; ++v) {
            if(lft[v] != -1)
                continue;

            bool got = try_kuhn(v);
            ret += got, new_mat |= got;
        }
    }

    return ret;
}

const ll dr[] = {2, 2, -2, -2, 1, 1, -1, -1};
const ll dc[] = {1, -1, 1, -1, 2, -2, 2, -2};

int main()
{
    ll t, cs = 0;
    cin >> t;

    while(t--) {
        ll nn, m, b;
        sl(nn), sl(m), sl(b);

        ll half = nn*m/2 + ((nn*m) & 1), odd = 0, even = 0;

        for0(i, half) g[i].clear();
        ms(mat, 0), ms(num, -1);

        for1(i, b) {
            ll r, c;
            sl(r), sl(c);
            r--, c--;
            mat[r][c] = 1;
        }

        for0(i, nn) {
            for0(j, m) {
                if(mat[i][j] || (i+j)%2 == 0) continue;

                for0(k, 8) {
                    int nr = i+dr[k], nc = j+dc[k];

                    if(nr < 0 || nc < 0 || nr >= nn || nc >= m || mat[nr][nc])
                        continue;

                    if(num[nr][nc] == -1) num[nr][nc] = even++;

                    g[odd].pb(num[nr][nc]);
                }

                odd++;
            }
        }

        n = odd, k = even;
        ll bad = kuhn();

        casep(cs); pf(" %lld\n", nn*m-b - bad);
    }

    return 0;
}
