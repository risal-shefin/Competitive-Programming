#include <bits/stdc++.h>
using namespace std;
#define ll long long
bool check[35];
int main()
{
    std::ios_base::sync_with_stdio(false);
    ll m, n, in, x;
    cin >> m >> n;
    for(ll i = 1; i <= n; i++) {
        cout << m << endl;
        cin >> in;
        if(in == 0)
            exit(0);
        if(in == 1)
            check[i] = 1;
        else
            check[i] = 0;
    }
    ll lo = 1, hi = m, id = 1;
    while(lo <= hi) {
        ll mid = (lo + hi) / 2;
        cout << mid << endl;
        //fflush(stdout);
        cin >> in;
        if(in == 0) {
            exit(0);
        }
        if(in == -2)
            exit(0);
        if(check[id] == 0)
            in *= -1;
        if(in == -1)
            lo = mid + 1;
        else
            hi = mid - 1;
        id++;
        if(id > n)
            id = 1;
    }
    return 0;
}
