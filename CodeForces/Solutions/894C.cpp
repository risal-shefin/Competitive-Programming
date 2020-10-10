#include <bits/stdc++.h>
using namespace std;

int main()

{
    int n;
    cin >> n;
    int ara[n];
    cin >> ara[0];
    int g = ara[0];
    for(int i = 1; i < n; i++) {
        cin >> ara[i];
        g = __gcd(g, ara[i]);
    }

    if(g != ara[0]) {
        cout << -1 << endl;
        return 0;
    }

    cout << 2 * n << endl;
    for(int i = 0; i < n; i++) {
        cout << ara[0] << " " << ara[i];
        if(i != n - 1)
            cout << " ";
    }

    cout << endl;


    return 0;
}