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

deque <char> lst;

int main()
{
    ll a1, a2, a3, a4;
    cin >> a1 >> a2 >> a3 >> a4;

    if(abs(a3-a4) > 1) {
        cout << -1 << endl;
        return 0;
    }

    for1(i, a4) lst.pb('7'), lst.pb('4');

    a1 -= a4, a2 -= a4;

    if(a3 < a4) {
        lst.pop_back();

        while(a2 >= 1) lst.pb('7'), a2--;

        lst.pb('4');

        lst.pop_front();

        while(a1 >= 1) lst.push_front('4'), a1--;

        lst.push_front('7');

    }
    else if(a3 == a4) {

        if(a1 > 0) {

            lst.pop_back();

            while(a2 >= 1) lst.pb('7'), a2--;

            lst.pb('4');
        }
        else {
            lst.pb('7');
            a2--;
        }
    }
    else {
        lst.push_front('4');
        lst.pb('7');

        a1--, a2--;
    }

    while(a1 >= 1) lst.push_front('4'), a1--;
    while(a2 >= 1) lst.pb('7'), a2--;

    if(a1 != 0 || a2 != 0) cout << -1 << EL;
    else {
        for(char &ch : lst) pf("%c", ch);
        pn;
    }

    return 0;
}