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

ll n, k;

inline ll calc(ll num)
{
    if(num == 0) return 0;
    ll sum = 0;
    while(num) {
        sum += (num % 10);
        num /= 10;
    }
    return sum;
}

ll mark[170][12];

ll solve(ll x) {

    ll sum = 0, prv = 0;
    for(ll i = 0; i <= 9; i++) {
        sum += calc(x+i);

        if(sum <= 150) {
            if(i > 1 && mark[sum][i] == -1)
                mark[sum][i] = x;
        }
        else break;
    }
}

unordered_set <ll> lst;

void gen1()
{
    for(ll i = 1, j = 0; i <= 17; i += 2, j++) mark[i][1] = j, lst.insert(i);
    mark[10][1] = 9; lst.insert(10);

    ll now = 9, state = 1, cnt = 0, ad = 9, it = 0;
    while(lst.size() < 146) {
        if(state) {
            now += ad, cnt++;
            ll sum = calc(now) + calc(now+1);
            //cout << now << " " << sum << endl;
            if(sum <= 150 && mark[sum][1] == -1) {
                mark[sum][1] = now;
                lst.insert(sum);
            }
        }
        else {
            if(ad != 9) now += 9;
            else now++;

            ll sum = calc(now) + calc(now+1);
            if(sum <= 150 && mark[sum][1] == -1) {
                mark[sum][1] = now;
                lst.insert(sum);
            }
        }
        state ^= 1;
        if(cnt == 9) {
            if(ad == 9) ad = 91, state^=1;
            else {
                ad--;
                ad += 9;
                ad = ad*10 + 1;
            }
            cnt = 0;
        }
        //cout << lst.size() << " " << ad << endl;
        //it++;
        //assert(it == lst.size());
    }
}

string res;

int main()
{
    ms(mark, -1);
    for(ll i = 0; i <= 1000000; i++) solve(i);
    gen1();

    ll t;
    cin >> t;
    while(t--) {
        sl(n), sl(k);

        if(k >= 1) pf("%lld\n", mark[n][k]);
        else {
            res = "";
            ll tot = n;
            if(tot == 0) res = "0";
            while(tot) {
                ll mn = min(tot, (ll)9);
                tot -= mn;
                res.pb(mn + '0');
            }
            reverse(all(res));
            cout << res << EL;
        }
    }

    return 0;
}