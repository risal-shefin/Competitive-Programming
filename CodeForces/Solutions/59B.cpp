#include <bits/stdc++.h>
using namespace std;

#define ll long long

ll odd[105], even[105], oid = 1, eid = 1;

int main()

{
    ll n;
    cin >> n;
    for(ll i = 1; i <= n; i++) {
        ll in;
        cin >> in;
        if(in & 1)
            odd[oid++] = in;
        else
            even[eid++] = in;
    }

    sort(odd + 1, odd + oid);
    sort(even + 1, even + eid);

    ll sum = 0;
    for(ll i = oid - 1; i >= 1; i--)
        sum += odd[i];

    if( (oid - 1) % 2 == 0)
        sum -= odd[1];

    for(ll i = 1; i < eid; i++)
        sum += even[i];

    if(sum & 1)
        cout << sum << endl;
    else
        cout << "0" << endl;

    return 0;
}