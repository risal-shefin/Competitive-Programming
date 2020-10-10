#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
ll dp[2][200009][2][2], tst = 0;
ll num[200009], sz;
int check[2][200009][2][2];
char inp[200009];

ll solve(ll isStart, ll pos, bool cnt, bool mOne)

{
    if(pos == 0)
        return 0;

    ll &ret = dp[isStart][pos][cnt][mOne];
    if(check[isStart][pos][cnt][mOne] == tst)
        return ret;

    ll pos2 = sz - pos;
    bool lim = num[pos2];

    ll rt = 0;
    if(!isStart) {
        ll tmp = cnt ^ lim;
        if(tmp & mOne)
            rt++;

        rt += solve(0, pos - 1, cnt ^ lim, mOne | lim);
    }
    else {
        rt += solve(0, pos - 1, lim, 0);

        rt += solve(1, pos - 1, 0, 0);
    }

    check[isStart][pos][cnt][mOne] = tst;
    return ret = rt;
}

int main()

{
    ll t, caseno = 0;
    cin >> t;
    while(t--) {
        tst++;
        scanf("%lld", &sz);

        scanf("%s", inp);
        for(int i = 0; i < sz; i++) {
            //ch = getchar();
            num[i] = (inp[i] - '0');
        }

        ll ans = solve(1, sz, 0, 0);

        printf("%lld\n", ans);
    }

    return 0;
}