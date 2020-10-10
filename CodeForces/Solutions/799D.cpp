#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define inf (1LL << 60)
ll a, b, h, w, n, ans = inf, indx = 0;
ll ara[100009];

void solve(ll pos, ll hh, ll ww, ll step)

{
    if(hh >= a && ww >= b) {
        ans = min(ans, step);
        return;
    }
    if(pos >= indx)
        return;

    if(ara[pos] == 2) {
        while(pos < indx && hh < a)
            step++, hh *= ara[pos], pos++;
        while(pos < indx && ww < b)
            step++, ww *= ara[pos], pos++;

        if(hh >= a && ww >= b)
            ans = min(ans, step);
        return;
    }

    if(hh < a)
        solve(pos + 1, hh * ara[pos], ww, step + 1);
    if(ww < b)
        solve(pos + 1, hh, ww * ara[pos], step + 1);
}

int main()

{
    cin >> a >> b >> h >> w >> n;

    for(ll i = 1; i <= n; i++) {
        scanf("%lld", &ara[indx]);
        if(ara[indx] == 1)
            continue;
        indx++;
    }

    if(a > b) swap(a, b);
    if(h > w) swap(h, w);
    if(a <= h && b <= w) {
        cout << 0 << endl;
        return 0;
    }
    if(indx == 0) {
        cout << -1 << endl;
        return 0;
    }

    sort(ara, ara + indx, greater <ll> ());
    solve(0, h, w, 0);
    solve(0, w, h, 0);

    if(ans == inf)
        cout << -1 << endl;
    else
        cout << ans << endl;

    return 0;
}