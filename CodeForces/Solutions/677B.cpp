#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main()

{
    ll n, h, k;

    cin >> n >> h >> k;
    ll cur = 0, time = 0;
    for(int i = 1 ; i <= n; i++) {
        ll p;
        scanf("%I64d", &p);

        if(cur + p > h) {
            cur = 0;
            time++;
        }
        cur += p;
        time += cur / k;
        cur = cur % k;
    }

    if(cur > 0)
        time++;
    cout << time << endl;
    return 0;
}