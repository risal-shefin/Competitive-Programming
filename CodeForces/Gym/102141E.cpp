#include <bits/stdc++.h>
using namespace std;

#define ll long long

char s[200009];
set <ll> start[30], stop[30];

int main()

{
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t, cs = 0;
    cin >> t;
    while(t--) {
        cin >> s;
        ll len = strlen(s);

        char prv = 0;
        for(ll i = 0; i < len; i++) {
            if(s[i] != prv) {
                start[s[i] - 'A'].insert(i);
                if(prv != 0)
                    stop[ s[i - 1] - 'A'].insert(i - 1);

                prv = s[i];
            }
        }
        stop[prv - 'A'].insert(len - 1);

        ll q;
        cin >> q;
        cout << "Case " << ++cs << ":" << endl;
        while(q--) {
            ll state, indx;
            cin >> state >> indx;
            if(state == 2) {
                bool chk = 0;
                ll pos = s[indx] - 'A';
                if(start[pos].find(indx) != start[pos].end()) {
                    start[pos].erase(indx);
                    if(indx < (len - 1) )
                        start[pos].insert(indx + 1);

                    chk = 1;
                }
                if(stop[pos].find(indx) != stop[pos].end()) {
                    stop[pos].erase(indx);
                    if(indx > 0)
                        stop[pos].insert(indx - 1);

                    chk = 1;
                }

                if(!chk) {
                    if(indx < (len - 1) )
                        start[pos].insert(indx + 1);
                    if(indx > 0)
                        stop[pos].insert(indx - 1);
                }
            }
            else {
                ll pos = s[indx] - 'A';
                auto it1 = start[pos].lower_bound(indx);
                assert(start[pos].size() > 0);
                assert( !(it1 == start[pos].begin() && *it1 > indx) );
                if(it1 == start[pos].end())
                    it1--;
                else if(*it1 > indx)
                    it1--;

                assert(it1 != start[pos].end());
                auto it2 = stop[pos].lower_bound(indx);
                assert(stop[pos].size() > 0 && it2 != stop[pos].end());

                cout << (ll)(*it2 - *it1 + 1) << '\n';
            }
        }

        for(ll i = 0; i <= 28; i++) {
            start[i].clear();
            stop[i].clear();
        }
    }

    return 0;
}