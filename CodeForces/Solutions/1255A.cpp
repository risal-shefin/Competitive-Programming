#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
#define pb push_back
#define pll pair <ll, ll>
#define inf (1LL << 60)
 
int main()
 
{
    ll t;
    cin >> t;
    while(t--) {
        ll a, b;
        scanf("%lld %lld", &a, &b);
        if(a > b)
            swap(a, b);
 
        ll diff = b - a, ans = 0;
        ll lagbe = diff / 5;
        ans += lagbe;
 
        a = a + lagbe * 5;
        diff = b - a;
        lagbe = diff / 2;
        ans += lagbe;
 
        a = a + lagbe * 2;
 
        diff = b - a;
        ans += diff;
 
        printf("%lld\n", ans);
    }
 
    return 0;
}