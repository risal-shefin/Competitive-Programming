#include <bits/stdc++.h>
using namespace std;

#define ll long long

ll dp[10009][105][2], n, mv;

ll solve(ll num, ll mov, ll state)

{
    if(mov > mv) {
        if(num > n) {
            if(state == 0)
                return 1;
            else
                return 0;
        }
        else {
            if(state == 0)
                return 0;
            else
                return 1;
        }
    }

    ll &ret = dp[num][mov][state];
    if(ret != -1)
        return ret;

    ll rt = 0;
    if(num > 999) {
        if(num % 10 != 9)
            rt |= !solve(num + 1, mov + 1, state ^ 1);
        else
            rt |= !solve(num - 9, mov + 1, state ^ 1);

        if(num % 100 < 90)
            rt |= !solve(num + 10, mov + 1, state ^ 1);
        else
            rt |= !solve(num - 90, mov + 1, state ^ 1);

        if(num % 1000 < 900)
            rt |= !solve(num + 100, mov + 1, state ^ 1);
        else
            rt |= !solve(num - 900, mov + 1, state ^ 1);

        if(num % 10000 < 9000)
            rt |= !solve(num + 1000, mov + 1, state ^ 1);
        else
            rt |= !solve(num - 9000, mov + 1, state ^ 1);
    }
    else if(num > 99) {
        if(num % 10 != 9)
            rt |= !solve(num + 1, mov + 1, state ^ 1);
        else
            rt |= !solve(num - 9, mov + 1, state ^ 1);

        if(num % 100 < 90)
            rt |= !solve(num + 10, mov + 1, state ^ 1);
        else
            rt |= !solve(num - 90, mov + 1, state ^ 1);

        if(num % 1000 < 900)
            rt |= !solve(num + 100, mov + 1, state ^ 1);
        else
            rt |= !solve(num - 900, mov + 1, state ^ 1);

        rt |= !solve(num + 1000, mov + 1, state ^ 1);
    }

    else if(num > 9) {
        if(num % 10 != 9)
            rt |= !solve(num + 1, mov + 1, state ^ 1);
        else
            rt |= !solve(num - 9, mov + 1, state ^ 1);

        if(num % 100 < 90)
            rt |= !solve(num + 10, mov + 1, state ^ 1);
        else
            rt |= !solve(num - 90, mov + 1, state ^ 1);

        rt |= !solve(num + 100, mov + 1, state ^ 1);
        rt |= !solve(num + 1000, mov + 1, state ^ 1);
    }

    else {
        if(num % 10 != 9)
            rt |= !solve(num + 1, mov + 1, state ^ 1);
        else
            rt |= !solve(num - 9, mov + 1, state ^ 1);

        rt |= !solve(num + 10, mov + 1, state ^ 1);
        rt |= !solve(num + 100, mov + 1, state ^ 1);
        rt |= !solve(num + 1000, mov + 1, state ^ 1);
    }

    //cout << num << "  " << rt << "  " << state << endl;
    return ret = rt;
}

int main()

{
    ll t;
    cin >> t;
    while(t--) {
        memset(dp, -1, sizeof(dp));
        scanf("%lld %lld", &n, &mv);

        if( solve(n, 1, 0) == 1)
            printf("Ada\n");
        else
            printf("Vinit\n");
    }

    return 0;
}
