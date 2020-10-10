#include <bits/stdc++.h>
using namespace std;

#define ll long long
ll ara[200009], cum[200009], n;

bool cmp(ll a, ll b)

{
    return a > b;
}

ll fnd(ll num)

{
    ll lo = 1, hi = n, ans = 0;
    while(lo <= hi) {
        ll mid = (lo + hi) / 2;
        if(ara[mid] > num) {
            lo = mid + 1;
        }
        else if(ara[mid] <= num) {
            ans = mid;
            hi = mid - 1;
        }
    }

    return ans;
}

ll end1(ll num, ll s)

{
    ll lo = s, hi = n, ans = 0;
    while(lo <= hi) {
        ll mid = (lo + hi) / 2;
        if(cum[mid] - cum[s - 1] > num) {
            hi = mid - 1;
        }
        else if(cum[mid] - cum[s - 1] <= num) {
            ans = mid;
            lo = mid + 1;
        }
    }

    return ans;
}

ll fnd2(ll num, ll s)

{
    ll lo = s, hi = n, ans = 0;
    while(lo <= hi) {
        ll mid = (lo + hi) / 2;
        if(ara[mid] > num) {
            lo = mid + 1;
        }
        else if(ara[mid] <= num) {
            ans = mid;
            hi = mid - 1;
        }
    }

    return ans;
}


int main()

{
    ll q;
    cin >> n >> q;
    for(ll i = 1; i <= n; i++) {
        scanf("%lld", &ara[i]);

    }

    sort(ara + 1, ara + n + 1, cmp);

    for(ll i = 1; i <= n; i++) {
        cum[i] = ara[i] + cum[i - 1];
    }

    for(ll i = 1; i <= q; i++) {
        ll num;
        scanf("%lld", &num);

        ll start = fnd(num);

        if(start == 0) {
            printf("-1\n");
            continue;
        }

        //cout << start << endl;
        ll indx1 = end1(num, start);

        if(indx1 == 0) {
            printf("-1\n");
            continue;
        }

        ll now = cum[indx1] - cum[start - 1];
        ll rest = num - now;

        if(rest == 0) {
            printf("%lld\n", indx1 - start + 1);
            continue;
        }

        ll cnt = indx1 - start + 1;
        ll prv = indx1 + 1;
        while(rest != 0) {
            ll st2 = fnd2(rest, prv);
            if(st2 == 0) {
                printf("-1\n");
                break;
            }

            ll indx2 = end1(rest, st2);

            if(indx2 == 0)
            {
                printf("-1\n");
                break;
            }

            ll now2 = cum[indx2] - cum[st2 - 1];
            rest -= now2;
            cnt += (indx2 - st2 + 1);
            prv = indx2 + 1;
        }

        if(rest == 0)
            printf("%lld\n", cnt);

    }
    return 0;
}