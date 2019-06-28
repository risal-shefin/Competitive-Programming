#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    ll t;
    cin >> t;
    while(t--) {
        ll n, l, r;
        scanf("%lld %lld %lld", &n, &l, &r);
        ll lo = 1, hi = 1e9;
        bool check = 0;
        while(lo <= hi) {
            ll mid = (lo + hi) / 2;
            double avg = n / (mid * 1.0);
            //cout << avg << "  " << mid << endl;
            if(avg < (double)l)
                hi = mid - 1;
            else if(avg > (double)r)
                lo = mid + 1;
            else {
                check = 1;
                break;
            }
        }
        if(check)
            printf("Yes\n");
        else
            printf("No\n");
    }
    return 0;
}
