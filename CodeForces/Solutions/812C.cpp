#include <bits/stdc++.h>
using namespace std;

#define ll long long
ll ara[100009], cst[100009];

int main()

{
    ll n, s;
    cin >> n >> s;
    for(ll i = 1; i <= n; i++)
        scanf("%lld", &ara[i]);

    ll lo = 1, hi = n, ansq = 0, ansp = 0;
    while(lo <= hi) {
        ll mid = (lo + hi) / 2;
        for(ll i = 1; i <= n; i++) {
            cst[i] = ara[i] + mid * i;
        }

        sort(cst + 1, cst + n + 1);

        ll paid = 0;
        for(ll i = 1; i <= mid; i++) {
            paid += cst[i];

            if(paid > s) {
                paid = 0;
                break;
            }
        }

        if(paid > 0) {
            lo = mid + 1;
            if(mid > ansq) {
                ansq = mid;
                ansp = paid;
            }
            else if(mid == ansq) {
                ansp = min(ansp, paid);
            }
        }
        else {
            hi = mid - 1;
        }
    }

    cout << ansq << " " << ansp << endl;

    return 0;
}