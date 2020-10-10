#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main()

{
    string s;
    cin >> s;

    ll len = s.length();
    ll cntB = 0, cntC = 0, cntS = 0, B, C, S;
    cin >> B >> S >> C;
    ll costB, costC, costS;
    cin >> costB >> costS >> costC;
    ll total;
    cin >> total;

    for(int i = 0; i < len; i++) {
        if(s[i] == 'B') cntB++;
        else if(s[i] == 'C') cntC++;
        else if(s[i] == 'S') cntS++;
    }

    ll lo = 0, hi = 10000000000000;
    ll ans = 0;
    while(lo <= hi) {
        ll mid = (lo + hi) / 2;
        ll tmpB, tmpC, tmpS;

        if(cntB * mid <= B)
            tmpB = 0;
        else
            tmpB =costB * (cntB * mid - B);

        if(cntS * mid <= S)
            tmpS = 0;
        else
            tmpS = costS * (cntS * mid - S);

        if(cntC * mid <= C)
            tmpC = 0;
        else
            tmpC = costC * (cntC * mid - C);

        ll sum = tmpB + tmpS + tmpC;

        if(sum <= total) {
            ans = mid;
            lo = mid + 1;
        }

        else
            hi = mid - 1;
    }

    cout << ans << endl;

    return 0;
}