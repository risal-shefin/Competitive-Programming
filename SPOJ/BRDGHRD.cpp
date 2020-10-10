#include <bits/stdc++.h>
using namespace std;

#define ll long long

struct node {
    ll start;
    ll stop;
} ara[100009], indx[100009];

bool cmp(node a, node b)

{
    if(a.start != b.start)
        return a.start < b.start;
    return a.stop < b.stop;
}

int main()

{
    ll t, lo, hi, mx, ansi;
    cin >> t;
    while(t--) {
        mx = 0;
        for(ll i = 0; i <= 100005; i++) {
            indx[i].start = 1e18;
            indx[i].stop = 1e18;
        }

        ll n;
        scanf("%lld", &n);
        for(ll i = 1; i <= n; i++)
            scanf("%lld", &ara[i].start);
        for(ll i = 1; i <= n; i++)
            scanf("%lld", &ara[i].stop);

        sort(ara + 1, ara + n + 1, cmp);

        for(ll i = 1; i <= n; i++) {
            lo = 1, hi = n, ansi = -1;
            while(lo <= hi) {
                ll mid = (lo + hi) / 2;
                if(indx[mid].start > ara[i].start) {
                    hi = mid - 1;
                }
                else if(indx[mid].stop > ara[i].stop) {
                    hi = mid - 1;
                }
                else {
                    ansi = mid;
                    lo = mid + 1;
                }
            }

            if(ansi == -1)
                ansi = 1;
            else
                ansi++;

            indx[ ansi ].start = ara[i].start;
            indx[ ansi ].stop = ara[i].stop;

            mx = max(mx, ansi);
        }

        printf("%lld\n", mx);
    }

    return 0;
}
