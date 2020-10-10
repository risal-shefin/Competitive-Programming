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

const ll sz = 1e5 + 10;
ll pre[sz], preTim[sz], dp[2][sz];
int t2[sz], pnt[sz], d[sz];

struct Line {
    int m; ll c;
} tree[sz];

int exist[sz], state;

inline ll f(Line &line, int &x) {
    return (ll)line.m*x + line.c;
}

void add(int lo, int hi, Line line)
{
    int mid, lpnt, mpnt;

    while(lo <= hi) {
        mid = lo+hi >> 1, lpnt = pnt[lo], mpnt = pnt[mid];

        if(exist[mid] != state) tree[mid] = {0, inf};
        exist[mid] = state;

        bool l = f(line, lpnt) < f(tree[mid], lpnt);
        bool m = f(line, mpnt) < f(tree[mid], mpnt);

        if(m) swap(tree[mid], line);

        if(l != m)
            hi = mid - 1;
        else
            lo = mid + 1;
    }
}

ll query(int lo, int hi, int &idx)
{
    ll ret = inf;
    int mid, p = pnt[idx];

    while(lo <= hi) {
        mid = lo+hi >> 1;

        if(exist[mid] != state) break;

        ret = min(ret, f(tree[mid], p));

        if(idx < mid)
            hi = mid - 1;
        else if(idx > mid)
            lo = mid + 1;
        else
            break;
    }

    return ret;
}

int main()
{
    ll n, m, p;
    cin >> n >> m >> p;

    for(ll i = 2; i <= n; i++) {
        si(d[i]);
        pre[i] = pre[i-1] + d[i];
    }

    for1(i, m) {
        int h, t;
        si(h), si(t);

        t2[i] = t - pre[h];
    }
    sort(t2+1, t2+m+1);

    bool now = 0;
    for1(i, m) {
        preTim[i] = preTim[i-1] + t2[i];

        dp[now][i] = i * t2[i] - preTim[i];
        //cout << dp[now][i] << " || " << ara[i].h << " " << ara[i].t << " " << ara[i].t2 << endl;

        pnt[i] = t2[i];
    }

    for(int i = 2; i <= p; i++) {
        now ^= 1, state++;

        add(1, m, {0, 0});

        for(int j = 1; j <= m; j++) {
            dp[now][j] = query(1, m, j) + (ll)j*t2[j] - preTim[j];

            //cout << dp[now][j] << " || " << j << " " << pnt[j] << " " << preTim[j-1] << endl;

            add(1, m, {-j, preTim[j]+dp[now^1][j]});
        }
    }

    cout << dp[now][m] << EL;

    return 0;
}