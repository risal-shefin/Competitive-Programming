#include <iostream>
#include <cstdio>
#include <algorithm>
#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll ara1[55], ara2[55], dp[55][55], n;
ll solve(ll idx1, ll idx2)
{
    if(idx1 > n || idx2 > n)
         return 0;
    ll &ret = dp[idx1][idx2];
    if(ret != -1)
        return ret;
        ll rt = 0;
    if(ara2[idx2] > ara1[idx1])
         rt = solve(idx1 + 1, idx2);
    if(ara2[idx2] == ara1[idx1]) {
        rt = 1 + solve(idx1 + 1, idx2 + 1);
        rt = max(rt, solve(idx1+1, idx2));
    }
    if(ara2[idx2] < ara1[idx1]) {
        rt = 2 + solve(idx1 + 1, idx2 + 1);
    }
        return ret = rt;
    }
int main()
{
        ll t, caseno = 0;
    cin >> t;
    while(t--) {
        memset(dp, -1, sizeof(dp));
        scanf("%lld", &n);
        for(ll i = 1; i <= n; i++)
             scanf("%lld", &ara1[i]);
        for(ll i = 1; i <= n; i++)
             scanf("%lld", &ara2[i]);
                   sort(ara1 + 1, ara1 + n + 1);
         sort(ara2 + 1, ara2 + n + 1);
         printf("Case %lld: %lld\n", ++caseno, solve(1, 1));
    }
    return 0;
}
