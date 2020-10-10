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

ll mat[5][5];

int main()
{
    ll k = 0;
    cin >> k;

    ll n = 3, m = 3;
    cout << n << " " << m << endl;

    ll fake = (1 << 17), act = k;

    mat[1][1] = fake | act, mat[1][2] = k;
    mat[2][1] = fake, mat[2][2] = k;
    mat[3][1] = fake, mat[3][2] = fake | k, mat[3][3] = k;

    for1(i, 3) {
        for1(j, 3) {
            if(j != 1)
                pf(" ");
            pf("%lld", mat[i][j]);
        }
        pn;
    }

    return 0;
}