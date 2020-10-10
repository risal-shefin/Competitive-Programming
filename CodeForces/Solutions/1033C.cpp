#include <bits/stdc++.h>
using namespace std;

#define ll long long

ll dp[2][100009], n, ara[100009];

bool solve(ll pos, bool flag)

{
    ll &ret = dp[flag][pos];
    if(ret != -1)
        return ret;
    bool rt = 0, chk = 0;
    if(flag == 0)
        rt = 1;
    for(ll i = 1; i <= n; i++)
    {

        ll mul = ara[pos] * i;
        ll pos2 = pos + mul;

        if( (pos + mul) > n && (pos - mul) < 1)
            break;

        if(pos2 <= n)
        {
            if( ara[pos2] > ara[pos] )
            {

                bool tmp = solve(pos2, flag ^ 1);

                if(flag == 0)
                    rt &= tmp;
                else
                    rt |= tmp;

                chk = 1;

                //cout << ara[i] << "  " << tmp << " " << flag << endl;
            }
        }

        pos2 = pos - mul;
        if(pos2 >= 1)
        {
            if( ara[pos2] > ara[pos] )
            {

                bool tmp = solve(pos2, flag ^ 1);

                if(flag == 0)
                    rt &= tmp;
                else
                    rt |= tmp;

                chk = 1;

                //cout << ara[i] << "  " << tmp << " " << flag << endl;
            }
        }
    }

    if(pos != 0 && chk != 1)
    {
        if(flag == 1)
            rt = 0;
        else
            rt = 1;
    }

    return ret = rt;

}

int main()

{
    memset(dp, -1, sizeof(dp));
    cin >> n;
    for(ll i = 1; i <= n; i++)
        scanf("%lld", &ara[i]);

    for(ll i = 1; i <= n; i++)
        solve(i, 0);

    for(ll i = 1; i <= n; i++)
    {
        if(dp[0][i] == 0)
            printf("A");
        else
            printf("B");
    }

    cout << endl;

    return 0;
}