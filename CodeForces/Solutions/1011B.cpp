#include <bits/stdc++.h>
using namespace std;

#define ll long long
ll ara[105];
ll cnt[105], cnt2[105];

int main()

{
    std::ios_base::sync_with_stdio(false);
    ll n, m;
    cin >> n >> m;
    for(ll i = 1; i <= m; i++) {
        cin >> ara[i];
        cnt[ ara[i] ]++;
    }

    vector <ll> v;
    for(ll i = 1; i <= 100; i++) {
        if(cnt[i])
            v.push_back(cnt[i]);
    }

    sort(v.begin(), v.end(), greater <ll> ());

    ll last, ase = 1e18;
    for(ll i = 1; i <= n; i++) {

        ll mx = 0, indx = -1;
        for(ll j = 0; j < v.size(); j++) {
            ll tmp1 = v[j] / (cnt2[j] + 1);
            if(tmp1 > mx) {
                mx = tmp1;
                indx = j;
            }
        }

        if(indx == -1) {
            cout << "0" << endl;
            return 0;
        }
        cnt2[indx]++;
        ase = min(ase, mx);
    }

    cout << ase << endl;

    return 0;
}