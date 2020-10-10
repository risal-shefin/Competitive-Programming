#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main()

{
    ll vp, vd, t, f, c;
    cin >> vp >> vd >> t >> f >> c;
    double girld = vp * t * 1.0;
    double drag= 0.0;
    ll cnt = 0;
    if(vd <= vp) {
        printf("0\n");
        return 0;
    }

    while(1) {
        if(girld >= c) {
            printf("%lld\n", cnt);
            break;
        }

        double t = (girld * 1.0) / (vd - vp);
        double sd = t * vd;
        girld = sd;
        if(sd < c) {
            cnt++;
            double tot = t + f;
            girld += (tot * vp);
        }
        else {
            printf("%lld\n", cnt);
            break;
        }
    }

    return 0;
}