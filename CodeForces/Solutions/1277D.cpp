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

string s;
bool check[200009];
unordered_map <string, int> ase;
unordered_map <string, int> :: iterator it;
deque <ll> zeros, ones, ans;

int main()

{
    fastio;
    ll t;
    cin >> t;
    while(t--) {
        ll n;
        cin >> n;
        ll one = 0, zero = 0, both = 0;
        for1(i, n) {
            cin >> s;
            if(s[0] == '0' && s.back() == '0')
                zero++;
            else if(s[0] == '1' && s.back() == '1')
                one++;
            else {
                both++;
                if(s[0] == '0')
                    zeros.pb(i);
                else
                    ones.pb(i);

                it = ase.find(s);
                if(it != ase.end()) {
                    check[ it->second ] = 1;
                    check[i] = 1;
                }
                else {
                    reverse(s.begin(), s.end());
                    ase[s] = i;
                }
            }
        }

        if(zero > 0 && one > 0 && both == 0) {
            cout << "-1" << endl;
            goto last;
        }
        else {
            if(zeros.size() >= ones.size()+2) {
                ll diff = zeros.size() - ones.size();

                for(ll pos: zeros) {
                    if(check[pos])
                        continue;

                    ans.pb(pos);
                    diff -= 2;
                    if(diff <= 1) break;
                }
            }
            else if(ones.size() >= zeros.size()+2) {
                ll diff = ones.size() - zeros.size();

                for(ll pos: ones) {
                    if(check[pos])
                        continue;

                    ans.pb(pos);
                    diff -= 2;
                    if(diff <= 1) break;
                }
            }
        }


        cout << ans.size() << endl;
        for0(i, ans.size()) {
            if(i != 0)
                cout << " ";
            cout << ans[i];
        }
        cout << endl;

        last:
        ase.clear(), ones.clear(), zeros.clear(), ans.clear();
        for1(i, n)
            check[i] = 0;
    }

    return 0;
}