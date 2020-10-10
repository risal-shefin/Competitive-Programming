#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define inf (1LL << 62)
#define siz 1000009
#define mxm 1000000000000000000
vector <ll> prime, num;
bool check[siz];
unordered_map <ll, bool> mark;

void sieve()

{
    prime.push_back(2);
    for(ll i = 3; i < siz; i += 2) {
        if(check[i] == 0) {
            for(ll j = i * i; j <= siz; j += i + i) {
                check[j] = 1;
            }
            prime.push_back(i);
        }
    }
}

int main()

{
    //sieve();
    num.push_back(1);
    for(ll i = 2; i <= 1000000; i++) {
        ll nm = i;
        for(ll j = 2; j <= 60; j++) {
            nm = nm * i;
            if(nm >= mxm) {
                break;
            }
            if(mark.find(nm) != mark.end())
                continue;

            num.push_back(nm);
            mark[nm] = 1;
        }
    }

    sort(num.begin(), num.end());
    ll Q, L, R;
    cin >> Q;
    for(ll i = 1; i <= Q; i++) {
        scanf("%lld %lld", &L, &R);
        ll start = lower_bound(num.begin(), num.end(), L) - num.begin();
        ll stop = lower_bound(num.begin(), num.end(), R) - num.begin();
        //cout << start << "  " << stop << endl;
        ll ans = stop - start;
        if(num[stop] == R)
            ans++;
        printf("%lld\n", ans);
    }

    return 0;
}