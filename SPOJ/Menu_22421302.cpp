#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll n, m, k, cst[55], v[55];
struct node {
    ll id;
    ll prof;
    ll cst;
     node(ll _id = 0, ll _p = 0, ll _c = 0) {
        id = _id;
        prof = _p;
        cst = _c;
    }
};
node dp[25][55][2][105];
node mx(node a, node b)
 {
    if(a.prof > b.prof)
        return a;
    else if(a.prof < b.prof)
        return b;
    else {
        if(a.cst < b.cst)
            return a;
        else
            return b;
    }
}
node solve(ll day, ll prv, ll prvv, ll rem)
 {
    if(day > k)
        return node(0, 0, 0);
     node &ret = dp[day][prv][prvv][rem];
    if(ret.id != -1)
        return ret;
     node rt;
    for(ll i = 1; i <= n; i++) {
        if(rem < cst[i])
            continue;
         node tmp;
        if(i == prv)
            tmp = solve(day + 1, i, 1, rem - cst[i]);
        else
            tmp = solve(day + 1, i, 0, rem - cst[i]);
         if(tmp.id == 0 && day != k)
            continue;
         if(i == prv && prvv == 1)
            tmp.cst += cst[i];
        else if(i == prv) {
            tmp.cst += cst[i];
            tmp.prof += (v[i] / 2);
        }
        else {
            tmp.cst += cst[i];
            tmp.prof += v[i];
        }
        tmp.id = i;
         rt = mx(rt, tmp);
    }
     //cout << day << "  " << prv << "  " << prvv << "  " << rem << endl;
    return ret = rt;
}
int main()
 {
    while(scanf("%lld %lld %lld", &k, &n, &m) && !(n == 0 && m == 0 && k == 0)) {
         for(ll i = 1; i <= n; i++) {
            scanf("%lld %lld", &cst[i], &v[i]);
            v[i] *= 2;
        }
         for(ll i = 0; i <= 22; i++) {
            for(ll j = 0; j <= 51; j++)
                for(ll k = 0; k <= 1; k++)
                    for(ll l = 0; l <= 101; l++)
                        dp[i][j][k][l].id = -1;
        }
         node ans = solve(1, 0, 0, m);
        printf("%0.1f\n", ans.prof / 2.0);
         if(ans.prof != 0) {
             printf("%lld", ans.id);
            ll rem2 = m - cst[ans.id], prv = ans.id, prvv = 0;
            for(ll i = 2; i <= k; i++) {
                 ll id = dp[i][prv][prvv][rem2].id;
                printf(" %lld", id);
                //cout << i << "  " << prv << "  " << prvv << "  " << rem2 << endl;
                rem2 -= cst[id];
                if(id == prv)
                    prvv = 1;
                else
                    prvv = 0;
                prv = id;
            }
        }
         printf("\n");
    }
     return 0;
