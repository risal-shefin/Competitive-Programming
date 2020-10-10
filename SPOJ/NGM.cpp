#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main()

{
    ll n;
    cin >> n;
    if(n < 10) {
        cout << 1 << endl << n << endl;
    }
    else if(n % 10 == 0) {
        printf("2\n");
    }
    else {
        cout << 1 << endl << n % 10 << endl;
    }

    return 0;
}
