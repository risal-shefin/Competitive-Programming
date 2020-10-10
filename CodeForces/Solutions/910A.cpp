#include <bits/stdc++.h>
using namespace std;

#define ll long long

ll dp[105], n, d;
char s[105];

ll solve(ll indx)

{
    if(indx == n)
        return 0;
    ll &ret = dp[indx];
    if(ret != -1)
        return ret;

    ll rt = 1e15;

    for(ll i = indx + 1; i <= n; i++) {
        if(i - indx > d)
            break;
        if(s[i] != '1')
            continue;

        rt = min(rt, solve(i) + 1);
    }

    return ret = rt;
}

int main()

{
    memset(dp, -1, sizeof(dp));
    cin >> n >> d;
    scanf("%s", s + 1);
    ll ret = solve(1);

    if(ret >= 1e15)
        cout << -1 << endl;
    else
        cout << ret << endl;

    return 0;
}