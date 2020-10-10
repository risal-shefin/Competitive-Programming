#include <bits/stdc++.h>
using namespace std;

#define ll long long


int main()

{
    ll n;
    cin >> n;
    ll ara[1009];
    for(ll i = 0; i < n; i++) {
        scanf("%lld", &ara[i]);
    }

    sort(ara, ara + n);
    deque <ll> dq;
    for(ll i = 0; i < n; i++) {
        dq.push_back( ara[i] );
    }

    bool turn = 0;
    ll num;
    while(!dq.empty()) {
        if(!turn) {
            num = dq.back();
            dq.pop_back();
        }
        else {
            num = dq.front();
            dq.pop_front();
        }

        turn ^= 1;
    }

    cout << num << endl;
    return 0;
}