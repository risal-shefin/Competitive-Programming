#include <bits/stdc++.h>

using namespace std;

#define ll long long

int main()

{
    ll n;
    cin >> n;
    ll ara[n + 5];
    for(ll i = 0; i < n; i++)
        scanf("%I64d", &ara[i]);

    ll rev = 0, state = 1, present, mx = INT_MIN;
    while(1) {
        ll last = ara[0], cnt = 1;
        if(rev == 0)
            last = last ^ 3;
        for(ll i = 1; i < n; i++) {

            present = ara[i];
            if(i >= rev && state == 1) {
                ll tmp = ara[i] ^ 3;
                if(tmp < last && rev != i)
                    state = 0;
                else
                    present = tmp;
            }

            if(present >= last) {
                cnt++;
                mx = max(mx, cnt);
                /*if(cnt == 4) {
                    cout << rev << "  " << i << endl;
                }*/
            }
            else {
                cnt = 1;
            }

            last = present;
        }

        mx = max(mx, cnt);
        rev++;
        state = 1;
        if(rev == n)
            break;
    }

    cout << mx << endl;

    return 0;
}