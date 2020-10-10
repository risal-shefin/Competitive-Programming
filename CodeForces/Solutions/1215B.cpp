#include <bits/stdc++.h>
using namespace std;

#define ll long long

ll pos[200009], ara[200009], id = 0;

ll neg = 0, posi = 0;

ll sum[2][200009];
bool state[200009];

int main()

{
    ll n;
    cin >> n;
    for(ll i = 1; i <= n; i++) {
        scanf("%lld", &ara[i]);
        if(ara[i] < 0)
            pos[id++] = i;
    }
    pos[id++] = n + 1;
    bool s = 1;
    for(ll i = id-2; i >= 0; i--) {

        state[i] = s;
        sum[s][i] = (pos[i + 1] - pos[i]) + sum[s][i+1];

        sum[s ^ 1][i] = sum[s^1][i+1];

       // cout << sum[s][i] << " " << pos[i] << endl;

        s ^= 1;
    }

    for(ll i = 1; i <= n; i++) {
        ll ase = lower_bound(pos, pos + id, i) - pos;

        ll start = pos[ase];
        ll len = start - i;

        posi += len;

        bool st = state[ase];
        neg += sum[st][ase];
        posi += sum[st ^ 1][ase];
    }

    cout << neg << " " << posi << endl;

    return 0;
}