#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define pb push_back

set <ll> l1, l2;
set <ll> :: iterator it, it2;

int main()

{
    string  s;
    cin >> s;
    ll indx1 = 0, indx2 = 0;
    for(ll i = 0; i < s.length(); i++) {
        if(s[i] == '0') {
            l1.insert(i + 1);
            indx1++;
        }
        else {
            l2.insert(i + 1);
            indx2++;
        }
    }
    //it = l2.upper_bound(1);
    vector <ll> ans[indx1 + 5];

    if(indx1 == 0) {
        printf("-1\n");
        return 0;
    }

    if(indx2 >= indx1) {
        printf("-1\n");
        return 0;
    }

    ll counter = 0, indx = 0, tmp;
    while(1) {
        if(l1.size() == 0) {
            if(counter != s.length()) {
                printf("-1\n");
                return 0;
            }
            break;
        }

        it = l1.begin();
        tmp = *it;
        ans[indx].pb(tmp);

        l1.erase(tmp);
        counter++;

        while(1) {
            it = l2.upper_bound(tmp);
            if(it == l2.end())
                break;
            ll tp = *it;
            it2 = l1.upper_bound(tp);
            if(it2 == l1.end())
                break;
            tmp = *it2;
            if(tmp > tp) {
                ans[indx].pb(tp);
                ans[indx].pb(tmp);
                l1.erase(tmp);
                l2.erase(tp);
                counter += 2;
            }
        }
        indx++;
    }

    printf("%lld\n", indx);
    for(ll i = 0; i < indx; i++) {
        printf("%lld ", ans[i].size());

        for(ll j = 0; j < ans[i].size(); j++) {
            printf("%lld", ans[i][j]);
            if(j < ans[i].size() - 1)
                printf(" ");
            else
                printf("\n");
        }
    }

    return 0;
}