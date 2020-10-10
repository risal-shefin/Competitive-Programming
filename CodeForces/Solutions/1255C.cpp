#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define pll pair <ll, ll>
#define inf (1LL << 60)

vector <ll> pos[100009], ans;

ll ara[100009][3], counter[100009];
bool check[100009], checker[100009];

int main()

{
    ll n;
    scanf("%lld", &n);

    for(ll i = 1; i <= n - 2; i++) {
        ll a, b, c;
        scanf("%lld %lld %lld", &a, &b, &c);
        pos[a].pb(i), pos[b].pb(i), pos[c].pb(i);

        ara[i][0] = a, ara[i][1] = b, ara[i][2] = c;
    }

    ll id = -1, now;
    for(ll i = 1; i <= n; i++) {
        if(pos[i].size() == 1) {
            id = pos[i][0];
            ans.pb(i);
            check[i] = 1;

            for(ll j = 0; j < 3; j++) {
                if(!check[ ara[id][j] ]) {
                    ans.pb(ara[id][j]);
                    check[ara[id][j]] = 1;
                }

                if(pos[ara[id][j]].size() > 1) {

                    for(ll idx: pos[ara[id][j]]) {
                        if(idx == id)
                            continue;

                        counter[idx]++;
                        if(counter[idx] == 2)
                            now = idx;
                    }
                }
            }
            break;
        }
    }

    if(pos[ans[1]].size() > pos[ans[2]].size())
        swap(ans[1], ans[2]);

    memset(counter, 0, sizeof(counter));
    checker[id] = 1;

    //cout << id << " " << now << endl;

    while(ans.size() < n) {

        checker[now] = 1;
        //cout << now << " LOL " << endl;

        ll ekhon;
        for(ll i = 0; i < 3; i++) {

            ll num = ara[now][i];
            if(!check[num]) {
                ans.pb(num);
                check[num] = 1;
            }

            for(ll idx: pos[num]) {
                if(checker[idx])
                    continue;

                //if(now == 5)
//                    cout << num << " " << idx << endl;
                counter[idx]++;
                if(counter[idx] == 2) {
//                    if(now == 5)
//                        cout << idx << endl;
                    ekhon = idx;
                }
            }
        }

        for(ll i = 0; i < 3; i++) {

            ll num = ara[now][i];

            for(ll idx: pos[num]) {
                if(checker[idx])
                    continue;

                counter[idx]--;
            }
        }

        now = ekhon;
    }

    for(ll i = 0; i < ans.size(); i++) {
        if(i != 0)
            printf(" ");
        printf("%lld", ans[i]);
    }

    cout << endl;

    return 0;
}