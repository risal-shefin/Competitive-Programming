#include <bits/stdc++.h>
using namespace std;

#define ll long long
ll ara[110], odd[110], even[110];
ll mark[110];

vector <ll> num[110];

int main()

{
    ll n, b;
    cin >> n >> b;
    for(ll i = 1; i <= n; i++) {
        cin >> ara[i];
        num[0].push_back(ara[i]);
    }

    for(ll i = 1; i <= n; i++) {
        if(ara[i] % 2 != 0) {
            odd[i] = 1;
        }
        else
            even[i] = 1;

        odd[i] += odd[i - 1];
        even[i] += even[i - 1];
    }

    ll indx = 1, cnt = 0, tot = 0;
    while(1) {

        ll cst = 1e18, resi = -1, ci, cj;
        for(ll i = 0; i < indx; i++) {
            if(mark[i])
                continue;

            ll co = 0, ce = 0;

            for(ll j = 0; j < num[i].size() - 1; j++) {
                if(num[i][j] % 2 != 0)
                    co ++;
                else
                    ce++;

                if(co != ce)
                    continue;
                ll tmp = abs(num[i][j] - num[i][j + 1]);

                if(cst > tmp) {
                    cst = tmp;
                    resi = i;
                    ci = j;
                    cj = j + 1;
                }

            }
        }

        if(resi == -1)
            break;

        mark[resi] = 1;
        if(tot + cst > b)
            break;

        cnt++;
        tot += cst;
        for(ll j = 0; j <= ci; j++)
            num[indx].push_back( num[resi][j] );

        indx++;
        for(ll j = cj; j < num[resi].size(); j++)
            num[indx].push_back( num[resi][j] );

        indx++;
    }

    cout << cnt << endl;

    return 0;
}