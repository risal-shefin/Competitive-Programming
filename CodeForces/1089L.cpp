#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define sl(n) scanf("%lld", &n)
vector <ll> v[100009], idl;
ll cst[100009];
bool cmp(ll a, ll b)
{
    //cout << cst[a] << "  " << cst[b] << endl;
    return cst[a] < cst[b];
}
int main()
{
    ll n, k;
    cin >> n >> k;
    set <ll> st;
    for(ll i = 1; i <= n; i++) {
        ll in;
        scanf("%lld", &in);
        v[in].push_back(i);
        st.insert(in);
    }
    for(ll i = 1; i <= n; i++) {
        scanf("%lld", &cst[i]);
    }
    if(st.size() == k) {
        printf("0\n");
        return 0;
    }
    ll lagbe = k - st.size();
    for(ll i = 1; i <= k; i++) {
        sort(v[i].begin(), v[i].end(), cmp);
        for(ll j = 0; j < (ll)v[i].size() - 1; j++) {
            idl.pb(v[i][j]);
        }
    }
    sort(idl.begin(), idl.end(), cmp);
    ll sum = 0;
    for(ll i = 0; i < idl.size(); i++) {
        sum += cst[ idl[i] ];
        lagbe--;
        if(lagbe == 0)
            break;
    }
    cout << sum << endl;
    return 0;
}
