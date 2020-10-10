#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair <ll, ll>
pll rad1, rad2, rad3;

set <pll> num;
set <pll> :: iterator it, it2, it3;
unordered_map <ll, ll> cnt;
unordered_map <ll, ll> :: iterator mit;

ll ans[100009][3];

int main()

{
    ll n;
    cin >> n;
    for(ll i = 0; i < n; i++) {
        ll in;
        scanf("%lld", &in);
        cnt[in]++;
    }

    for(mit = cnt.begin(); mit != cnt.end(); mit++) {
        ll radii = mit -> first;
        ll counter = mit -> second;

        num.insert( make_pair(counter, radii) );
    }

    ll indx = 0;
    while(num.size() >= 3) {

        it = num.end();
        it--;
        rad1 = *it;
        num.erase(it);

        it2 = num.end();
        it2--;
        rad2 = *it2;
        num.erase(it2);

        it3 = num.end();
        it3--;
        rad3 = *it3;
        num.erase(it3);

        ans[indx][0] = rad1.second, ans[indx][1] = rad2.second, ans[indx][2] = rad3.second;
        indx++;

        rad1.first--, rad2.first--, rad3.first--;
        if(rad1.first)
            num.insert( rad1);
        if(rad2.first)
            num.insert(rad2);
        if(rad3.first)
            num.insert(rad3);

    }

    cout << indx << endl;
    for(ll i = 0; i < indx; i++) {
        sort(ans[i], ans[i] + 3, greater <ll> ());
        printf("%lld %lld %lld\n", ans[i][0], ans[i][1], ans[i][2]);
    }

    return 0;
}