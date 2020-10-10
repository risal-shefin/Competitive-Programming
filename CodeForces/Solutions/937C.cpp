#include <bits/stdc++.h>

using namespace std;

#define dd double
#define ll long long
#define eps 1e-9

int main()

{
    ll k, d, t;
    cin >> k >> d >> t;

    if(k % d == 0 || (k >= t)) {
        printf("%0.10f\n", (dd)t);
        return 0;
    }

    if(k > d) {
        ll mul = k / d;
        d = (mul + 1) * d;
    }
    if(k < d) {
        dd tmp2 = k * 1.0;
        dd tmp3 = (d - k) * 0.5;
        dd sum = tmp2 + tmp3;
        dd tot = (dd)t;
        if(abs(sum - tot) <= eps) {
            printf("%0.10f\n", (dd)d);
            return 0;
        }

        if(sum > tot) {
            dd tp = (t - k) * 2.0;
            dd ans = k + tp;
            printf("%0.10f\n", ans);
        }
        else {
            dd tp2 = t / sum;
            ll intg = (ll)tp2;
            tp2 = sum * intg;
            dd ans = intg * d * 1.0;
            tp2 = t - tp2;
            if(tp2 < k || abs(k - tp2) <= eps)
                ans += tp2;
            else {
                ans += k;
                tp2 = (tp2 - k) * 2.0;
                ans += tp2;
            }
            //cout << sum << endl;
            printf("%0.10f\n", ans);
            return 0;
        }
    }

    return 0;
}

///2124 6621 12695