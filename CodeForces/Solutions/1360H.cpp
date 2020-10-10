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

ll n, m;
string inp[105];

inline ll toDecimal(string &s)
{
    ll num = 0;
    for(char &ch: s) {
        num = num * 2 + (ch-'0');
    }
    return num;
}

vector <ll> num;
string ret;

int main()
{
    fastio;
    ll t;
    cin >> t;
    while(t--) {
        cin >> n >> m;
        for1(i, n) cin >> inp[i];

        for1(i, n) num.pb(toDecimal(inp[i]));

        sort(num.begin(), num.end());

        ll ase = (1LL << m) - n;
        ll k = ase / 2;
        if(ase & 1) k++;

        ll lo = 0, hi = (1LL << m) - 1, ans;
        while(lo <= hi) {
            ll mid = lo+hi >> 1;

            ll got = mid - (upper_bound(all(num), mid) - num.begin()) + 1;

            //cout << mid << " " << got << endl;
            if(got < k)
                lo = mid + 1;
            else if(got >= k) {
                ans = mid;
                hi = mid - 1;
            }
        }

        ret = "";
        if(ans == 0) ret = "0";
        while(ans) {
            ret.pb(ans%2 + '0');
            ans /= 2;
        }
        while(ret.length() < m) ret.pb('0');
        reverse(all(ret));

        cout << ret << EL;

        num.clear();
    }

    return 0;
}