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

string s1, s2, s3;

int main()
{
    fastio;
    ll t;
    cin >> t;
    while(t--) {
        ll n;
        cin >> n;
        cin >> s1;

        ll eq = 1;
        s2 = s3 = "";
        for(char ch: s1) {
            if(ch == '0') {
                s2.pb('0');
                s3.pb('0');
            }
            else if(ch == '1') {
                if(eq) {
                    s2.pb('1'), s3.pb('0');
                    eq = 0;
                }
                else
                    s2.pb('0'), s3.pb('1');
            }
            else {
                if(eq)
                    s2.pb('1'), s3.pb('1');
                else
                    s2.pb('0'), s3.pb('2');
            }
        }

        cout << s2 << endl;
        cout << s3 << endl;
     }

    return 0;
}