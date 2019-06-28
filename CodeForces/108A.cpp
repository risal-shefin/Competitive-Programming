#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    ll hh, mm;
    scanf("%lld:%lld", &hh, &mm);
    ll cnt1 = 0, cnt2 = 0, ansh, ansm;
    while(1) {
        mm++;
        cnt1++;
        if(mm == 60) {
            mm = 0;
            hh++;
        }
        if(hh > 23)
            hh = 0;
        ll th = hh;
        if(th < 10)
            th *= 10;
        else {
            ll tmp = th;
            th = 0;
            while(tmp != 0) {
                ll rem = tmp % 10;
                tmp /= 10;
                th = th * 10 + rem;
            }
        }
        if(th == mm) {
            ansh = hh;
            ansm = mm;
            break;
        }
    }
    if(ansh < 10)
        printf("0");
    cout << ansh << ":";
    if(ansm < 10)
        cout << 0;
    cout << ansm << endl;
    return 0;
}
