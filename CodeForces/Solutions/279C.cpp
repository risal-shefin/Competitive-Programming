#include <bits/stdc++.h>
using namespace std;

#define ll long long

ll ara[100009], ics[100009], dcs[100009];
bool icon[100009], dcon[100009];

int main()

{
    bool iflag = 0, dflag = 0;
    ll n, m;
    cin >> n >> m;
    for(ll i = 1; i <= n; i++) {
        scanf("%lld", &ara[i]);

        if(i != 1) {
            if(ara[i] > ara[i - 1]) {
                if(!iflag) {
                    ics[i] = 1;
                    iflag = 1;
                    dflag = 0;
                }
                else
                    icon[i] = 1;
            }
            else if(ara[i] < ara[i - 1]) {
                if(!dflag) {
                    //cout << ara[i - 1] << "  " << ara[i] << endl;
                    dcs[i] = 1;
                    iflag = 0;
                    dflag = 1;
                }
                else
                    dcon[i] = 1;
            }
        }

    }

    for(ll i = 1; i <= n; i++) {
        ics[i] += ics[i - 1];
        dcs[i] += dcs[i - 1];
    }

    for(ll i = 1; i <= m; i++) {
        ll l, r;
        scanf("%lld %lld", &l, &r);

        ll a = ics[r] - ics[l];
        ll b = dcs[r] - dcs[l];

        ll pos1 = -1, pos2 = -1;

        //cout << dcs[r] << "  " << dcs[l] << endl;
        if(l != r) {
            if(icon[l + 1]) {
                a++;
                pos1 = l + 1;
            }
            if(dcon[l + 1]) {
                b++;
                pos2 = l + 1;
            }
        }

        if(a > 1 || b > 1) {
            printf("No\n");
            continue;
        }

        if(a == 0 || b == 0) {
            printf("Yes\n");
            continue;
        }

        if(pos1 == -1)
            pos1 = lower_bound(ics + l, ics + r + 1, ics[r]) - ics;
        if(pos2 == -1)
            pos2 = lower_bound(dcs + l, dcs + r + 1, dcs[r]) - dcs;

        if(pos2 < pos1)
            printf("No\n");
        else
            printf("Yes\n");
    }

    return 0;
}