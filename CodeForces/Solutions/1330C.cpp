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

const ll sz = 1e5 + 10;
ll ara[sz], ans[sz];

int main()
{
    ll n, m, sum = 0;
    cin >> n >> m;
    for1(i, m) {
        sl(ara[i]);
        sum += ara[i];
    }
    if(sum < n) {
        pf("-1\n");
        return 0;
    }

    ll cellRest = n, colRest = sum;
    ll start = 1;
    for(ll i = m; i >= 1; i--) {
        ll si = n - ara[i] + 1;

//        if(si < lessStart) {
//            pf("-1\n");
//            return 0;
//        }

        if(colRest == cellRest) {
            ans[i] = start;
            cellRest -= ara[i];
            colRest -= ara[i];

            //lessStart = start + ara[i];
            start = start + ara[i];

            continue;
        }

        //cout << start << endl;
        ll x = cellRest - colRest + ara[i];
        x = max(x, 1LL);

        ll last = start + x - 1;

        ll nowStart = last - ara[i] + 1;
        nowStart = max(nowStart, 1LL);
        ans[i] = nowStart;
        ll nowLast = nowStart + ara[i] - 1;

        if(nowLast > n) {
            pf("-1\n");
            return 0;
        }

        ll len = nowLast - start + 1;

        //lessStart = start + 1;
        start = nowLast + 1;

        colRest -= ara[i];
        cellRest -= len;

        //cout << i << "  " << colRest << " " << cellRest << " " << nowStart << "  "<< nowLast << endl;

        if(cellRest > colRest) {
            pf("-1\n");
            return 0;
        }
    }

    for1(i, m) {
        if(i != 1)
            pf(" ");
        pf("%lld", ans[i]);
    }
    pn;

    return 0;
}