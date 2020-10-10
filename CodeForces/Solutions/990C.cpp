#include <bits/stdc++.h>
using namespace std;

#define ll long long
map <ll, ll> lst;
string ara[300009];
ll full = 0;
bool mark[300009], f[300009], frst[300009];

char in[300009];

int main()

{
    ll n;
    cin >> n;
    for(ll i = 0; i < n; i++) {
        scanf("%s", in);
        ara[i] = string(in, strlen(in));
    }

    for(ll i = 0; i < n; i++) {

        ll counter = 0;
        stack <char> st;

        for(ll j = 0; j < ara[i].length(); j++) {
            if(ara[i][j] == '(')
                st.push(ara[i][j]);
            else {
                if(st.empty()) {
                    counter++;
                    continue;
                }
                if(st.top() == '(')
                    st.pop();
            }
        }

        if(st.empty() && counter == 0) {
            mark[i] = 1;
            full++;
        }

        else if(st.empty() && counter > 0) {
            lst[counter]++;
        }
        else if(!st.empty() && counter == 0) {
            frst[i] = st.size();
            f[i] = 1;
        }
        else {
            mark[i] = 1;
        }
    }

    ll ans = full * full;

    for(ll i = 0; i < n; i++) {
        if(mark[i])
            continue;

        if(!f[i])
            continue;

        ans += (lst[ frst[i] ]);
    }

    cout << ans << endl;

    return 0;
}