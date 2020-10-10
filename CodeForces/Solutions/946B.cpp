#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define inf (1LL << 62)

ll n, m;

int main()

{
    cin >> n >> m;

    if(n == 0 || m == 0) {
        cout << n << " " << m << endl;
        return 0;
    }

    while(1) {
        if(n >= 2 * m) {
            ll tmp = 2 * m;
            n = n % tmp;
        }
        else {
            if(m >= 2 * n) {
                ll tmp = 2 * n;
                m = m % tmp;
            }
            else {
                cout << n << " " << m << endl;
                return 0;
            }
        }

        if(n == 0 || m == 0) {
            cout << n << " " << m << endl;
            return 0;
        }
    }

    return 0;
}