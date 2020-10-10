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

vector < pair <ll, pll > > lst1, lst2;

void print(vector < pair<ll, pll > > &lst) {
    for(ll i = 0; i < lst.size(); i++) {
        if(i != 0) pf(" ");
        pf("%lld", lst[i].second.second);
    }
    pn;
}

int main()
{
    ll n;
    cin >> n;
    for1(i, n) {
        ll a, b;
        sl(a), sl(b);

        if(a < b) lst1.pb( mp(a, mp(b, i) ));
        if(a > b) lst2.pb( mp(a, mp(b, i) ) );
    }

    sort(lst1.begin(), lst1.end(), greater < pair <ll, pll > > ());
    sort(lst2.begin(), lst2.end());

    cout << max(lst1.size(), lst2.size()) << endl;
    if(lst1.size() > lst2.size()) print(lst1);
    else print(lst2);

    return 0;
}