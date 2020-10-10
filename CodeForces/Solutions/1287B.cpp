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

string ara[1509];
unordered_map <string, int> cnt;

string need[3000009];
bool ase[3000009];

int main()

{
    fastio;
    ll n, k;
    cin >> n >> k;
    for1(i, n) {
        cin >> ara[i];

        cnt[ ara[i] ]++;
    }

    ll idx = 0;
    for1(i, n) {
        need[idx] = "";

        for(ll j = i+1; j <= n; j++) {

            bool chk = 1;
            for(ll l = 0; l < k; l++) {
                if(ara[i][l] != ara[j][l]) {
                    chk = 0;
                    if(ara[i][l] != 'S' && ara[j][l] != 'S')
                        need[idx].pb('S');
                    else if(ara[i][l] != 'E' && ara[j][l] != 'E')
                        need[idx].pb('E');
                    else if(ara[i][l] != 'T' && ara[j][l] != 'T')
                        need[idx].pb('T');
                }
                else
                    need[idx].pb(ara[i][l]);
            }

            ase[idx] = chk;
            idx++;
        }
    }

    ll ans = 0;
    for(ll i = 0; i < idx; i++) {
        if(ase[i])
            ans += (cnt[ need[i] ] - 2);
        else {
            if(cnt.find( need[i] ) != cnt.end())
                ans += cnt[ need[i] ];
        }
    }

    cout << (ans / 3) << endl;

    return 0;
}