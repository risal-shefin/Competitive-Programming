#include <bits/stdc++.h>
using namespace std;

#define ll long long

ll co[100009], cz[100009], uo[100009], uz[100009];

char a[100009], b[100009];

int main()

{
    ll n;
    cin >> n;
    scanf("%s", a + 1);
    scanf("%s", b + 1);

    for(ll i = 1; i <= n; i++) {
        if(a[i] == '1')
            co[i] = 1;
        if(a[i] == '0')
            cz[i] = 1;

        co[i] += co[i - 1];
        cz[i] += cz[i - 1];
    }

    ll way = 0;
    for(ll i = 1; i <= n; i++) {
        if(b[i] == '1') {
            if(a[i] == '1')
                uo[i] = 1;
            else
                uz[i] = 1;

            uo[i] += uo[i - 1];
            uz[i] += uz[i - 1];
            continue;
        }

        if(a[i] == '0') {
            way += (co[n] - co[i]);
            way += uo[i - 1];
        }
        else {
            way += (cz[n] - cz[i]);
            way += uz[i - 1];
        }

        uo[i] += uo[i - 1];
        uz[i] += uz[i - 1];
    }

    cout << way << endl;

    return 0;
}