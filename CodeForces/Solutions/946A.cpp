#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define inf (1LL << 62)

int main()

{
    ll n, sum1 = 0, sum2 = 0;
    cin >> n;
    while(n--) {
        ll in;
        cin >> in;
        if(in >= 0)
            sum1 += in;
        else {
           sum2 += in;
        }
    }


        cout << (sum1 - sum2) << endl;
    return 0;
}