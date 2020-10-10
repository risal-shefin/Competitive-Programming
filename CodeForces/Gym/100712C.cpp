#include <bits/stdc++.h>
using namespace std;

#define ll long long

char grid[105];

int main()

{
    ll t;
    cin >> t;
    while(t--) {
        ll n;
        scanf("%lld", &n);
        scanf(" %s", grid);

        if(n == 1) {
            if(grid[0] == '*')
                printf("0\n");
            else
                printf("1\n");
            continue;
        }

        ll cnt = 0;
        for(ll i = 0; i < n; i++) {
            if(i == 0) {
                if(grid[i + 1] != '*' && grid[i] != '*') {
                    cnt++;
                    grid[i + 1] = '*';
                }
            }
            else if(i == n - 1)
            {
                if(grid[i - 1] != '*' && grid[i] != '*')
                {
                    cnt++;
                    grid[i - 1] = '*';
                }
            }
            else {
                if(grid[i - 1] != '*' && grid[i] != '*' && grid[i + 1] != '*')
                {
                    grid[i + 1] = '*';
                    cnt++;
                }
            }

        }

        printf("%lld\n", cnt);
    }
    return 0;
}