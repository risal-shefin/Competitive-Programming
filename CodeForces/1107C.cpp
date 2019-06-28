#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll n, k, hit[200009];
char ara[200009];
int main()
{
    scanf("%lld %lld", &n, &k);
    for(ll i = 1; i <= n; i++) {
        scanf("%lld", &hit[i]);
    }
    scanf("%s", ara + 1);
    char ch;
    ll start = -1, stop, sum = 0;
    for(ll i = 1; i <= n; i++) {
        if(i == 1 || start == -1) {
            ch = ara[i];
            start = i;
            continue;
        }
        if(ch != ara[i]) {
            stop = i;
            sort(hit + start, hit + stop, greater <ll> ());
            for(ll j = start, s = 1; j < stop && s <= k; j++, s++)
                sum += hit[j];
            start = i;
            ch = ara[i];
        }
    }
    stop = n + 1;
    sort(hit + start, hit + stop, greater <ll> ());
    for(ll j = start, s = 1; j < stop && s <= k; j++, s++)
        sum += hit[j];
    cout << sum << endl;
    return 0;
}
