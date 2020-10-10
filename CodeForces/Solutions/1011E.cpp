#include <bits/stdc++.h>
using namespace std;

#define ll long long
vector <ll> ans;

int main()

{
    std::ios_base::sync_with_stdio(false);
    ll n, b, in;
    cin >> n >> b;
    ll gc = b;

    for(ll i = 1; i <= n; i++) {
        cin >> in;
        gc = __gcd(gc, in);
    }

    for(ll i = 0; i < b; i++)
        if(i % gc == 0)
            ans.push_back(i);

    cout << ans.size() << endl;
    for(ll i = 0; i < ans.size(); i++)
        cout << ans[i] << " ";

    return 0;
}