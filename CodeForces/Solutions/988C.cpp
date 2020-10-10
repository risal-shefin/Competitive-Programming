#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define sc(x) scanf("%lld", &x)

map <ll, ll> sumc;
vector <ll> ara[200009];
ll sm[200009];

ll ansi1, ansi2, seq1, seq2, chk = 0, asum;

int main()

{
    //ios::sync_with_stdio(false);
    ll k;
    cin >> k;
    for(ll i = 1; i <= k; i++) {
        ll n, in;
        scanf("%lld", &n);
        ll sum = 0;
        for(ll j = 1; j <= n; j++) {
            scanf("%lld", &in);
            ara[i].push_back(in);
            sum += in;
        }

        sm[i] = sum;
        if(chk)
            continue;

        for(ll j = 0; j < ara[i].size(); j++) {
            ll tmp = sm[i] - ara[i][j];

            if(sumc.find(tmp) != sumc.end()) {
                if(sumc[tmp] == i)
                    continue;
                asum = tmp;
                seq1 = sumc[tmp];
                seq2 = i;
                ansi2 = j + 1;
                chk = 1;
                break;
            }
            sumc[tmp] = i;
        }
    }

    if(!chk) {
        cout << "NO" << endl;
        return 0;
    }

    else {
        cout << "YES" << endl;
        for(ll i = 0; i < ara[seq1].size(); i++) {
            if(sm[seq1] - ara[seq1][i] == asum) {
                ansi1 = i + 1;
                break;
            }
        }

        cout << seq1 << " " << ansi1 << endl;
        cout << seq2 << " " << ansi2 << endl;
    }
    return 0;
}