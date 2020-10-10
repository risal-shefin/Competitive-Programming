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

char a[200009], b[200009];

int main()

{
    ll n, k;
    cin >> n >> k;
    scanf("%s", a+1);

    ll lim = 1 + k, last;
    for(ll i = 1; i + k <= n; i++) {
        if(i < lim) {
            b[i] = a[i];
            b[i + k] = b[i];
            //cout << i + k << " " << i << " " << b[i] << endl;
        }
        else {
            b[i+k] = b[i];
        }
        last = i;
    }
    for(ll i = last + 1; i < lim; i++)
        b[i] = a[i];
    b[n+1] = '\0';

    ll cmp = strcmp(b+1, a+1);
    if(cmp >= 0) {
        pf("%lld\n", n);
        pf("%s\n", b+1);
    }
    else {

        ll f = 0;
        for(ll i = lim - 1; i >= 1; i--) {
            if(b[i] != '9') {
                f = i;
                break;
            }
        }

        ll now = b[f] - '0';
        now++;
        ll idx = f;
        while(idx <= n) {
            b[idx] = now + '0';
            idx += k;
        }
        for(ll i = f+1; i < lim; i++) {
            idx = i;
            while(idx <= n) {
                b[idx] = '0';
                idx += k;
            }
        }

        pf("%lld\n", n);
        pf("%s\n", b+1);
    }

    return 0;
}