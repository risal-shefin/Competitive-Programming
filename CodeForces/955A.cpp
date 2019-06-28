#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define inf (1LL << 62)
int main()
{
    ll hh, mm;
    cin >> hh >> mm;
    ll h, d, c, n;
    cin >> h >> d >> c >> n;
    double dc = c * 0.8;
    if(hh >= 20) {
        ll bun = h / n;
        if(h % n != 0) {
            bun++;
        }
        double ans = bun * dc;
        printf("%0.4f\n", ans);
        return 0;
    }
    else {
        ll difh = 20 - hh;
        ll difm;
        if(mm > 0) {
            difh--;
            difm = 60 - mm;
        }
        else {
            difm = 0;
        }
        ll totm = difh * 60 + difm;
        ll totalh = totm * d + h;
        ll bun2 = totalh / n;
        if(totalh % n != 0) {
            bun2++;
        }
        double ans2 = bun2 * dc;
        //cout << ans2 << endl;
        ll bun = h / n;
        if(h % n != 0) {
            bun++;
        }
        double ans1 = bun * c * 1.0;
        double ans = min(ans1, ans2);
        printf("%0.4f\n", ans);
    }
    return 0;
}
