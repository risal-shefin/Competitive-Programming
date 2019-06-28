#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    ll a, b;
    cin >> a >> b;
    ll ca = 0, cb = 0, cc = 0;
    for(ll i = 1; i <= 6; i++) {
        if(abs(a-i) < abs(b-i))
            ca++;
        else if(abs(a-i) == abs(b - i))
            cb++;
        else
            cc++;
    }
    cout << ca << " " << cb << " " << cc << endl;
    return 0;
}
