#include <bits/stdc++.h>
using namespace std;
#define ll int
int main()
 {
    ll t, caseno = 0;
    cin >> t;
    while(t--) {
        ll q;
        scanf("%d", &q);
        printf("Case %d:\n", ++caseno);
         stack <ll> mango;
        multiset <ll> big;
         char ch;
        ll x;
        for(ll i = 1; i <= q; i++) {
            scanf(" %c", &ch);
            if(ch == 'A') {
                scanf("%d", &x);
                mango.push(x);
                big.insert(-x);
            }
            else if(ch == 'Q') {
                if(big.empty())
                    printf("Empty\n");
                else
                    printf("%d\n", -*(big.begin() ));
            }
            else {
                if(!mango.empty()) {
                    big.erase( big.find(-mango.top() ) );
                    mango.pop();
                }
            }
        }
    }
     return 0;
}
