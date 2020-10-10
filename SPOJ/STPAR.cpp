#include <bits/stdc++.h>
using namespace std;

#define ll long long

ll ara[1009];

stack <ll> st;

int main()

{
    ll n;
    while(scanf("%lld", &n) && n != 0) {
        for(ll i = 1; i <= n; i++)
            scanf("%lld", &ara[i]);

        ll last = 0;
        for(ll i = 1; i <= n; i++) {
            if(ara[i] - last != 1)
                st.push(ara[i]);
            else {
                last = ara[i];
                while(!st.empty() && st.top() - last == 1) {
                    last = st.top();
                    st.pop();
                }
            }
        }

        if(st.empty()) {
            printf("yes\n");
        }
        else {
            printf("no\n");

            while(!st.empty())
                st.pop();
        }
    }

    return 0;
}
