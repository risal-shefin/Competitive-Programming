#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("avx,avx2,fma")

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
#define EL '\n'
#define fastio std::ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

string s1, s2;
ll pref, suf;

ll calc_ans(string &a, string &b)
{
    ll ptr1 = pref+1, ptr2 = pref+2;
    //cout << ptr1 << " " << ptr2 << endl;
    for(; ptr2 < suf; ptr1++, ptr2++) {
        //cout << a[ptr1] << "  || " << a[ptr2] << endl;
        if(a[ptr1] != b[ptr2])
            return 0;
    }

    //cout << suf << " " << pref << endl;
    ll len = (suf - pref) - 2;
    if(len == 0) return 2;
    return 1;
}

int main()
{
    fastio;
    ll n;
    cin >> n;
    cin >> s1 >> s2;

    pref = -1, suf = n;
    for(ll i = 0; i < n; i++) {
        if(s1[i] != s2[i])
            break;

        pref = i;
    }

    for(ll i = n-1; i >= 0; i--) {
        if(s1[i] != s2[i])
            break;

        suf = i;
    }

    ll ans1 = calc_ans(s1, s2);
    ll ans2 = calc_ans(s2, s1);

    ll ans = max(ans1, ans2);
    if(ans1 != 2 && ans2 != 2)
        ans = ans1 + ans2;

    cout << ans << endl;

    return 0;
}