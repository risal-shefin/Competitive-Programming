#include <bits/stdc++.h>
using namespace std;

#define ll long long

vector <char> ch;

char grid[102][102], ans[102][102];

int main()

{
    for(char c = '0'; c <= '9'; c++)
        ch.push_back(c);
    for(char c = 'A'; c <= 'Z'; c++)
        ch.push_back(c);
    for(char c = 'a'; c <= 'z'; c++)
        ch.push_back(c);

    ll t;
    cin >> t;
    while(t--) {
        ll n, m, tot;
        scanf("%lld %lld %lld", &n, &m, &tot);

        ll rice = 0;
        for(ll i = 1; i <= n; i++) {
            scanf(" %s", grid[i] + 1);

            for(ll j = 1; grid[i][j] != '\0'; j++) {
                if(grid[i][j] == 'R')
                    rice++;
            }
        }

        ll per = rice / tot, now = 0, cnt = 0, rem = rice % tot;
        bool state = 0;

        for(ll i = 1; i <= n; i++) {
            for(ll j = state==0? 1 : m ; state==0? j <= m : j >= 1; state==0? j++ : j--) {
                if(grid[i][j] == '.') {
                    ans[i][j] = ch[now];
                    continue;
                }

                ans[i][j] = ch[now];
                cnt++;
                if(now <= rem - 1) {
                    if(cnt == per + 1) {
                        cnt = 0;
                        now++;
                    }
                }
                else if(cnt == per && now != tot - 1) {
                    cnt = 0;
                    now++;
                }
            }
            ans[i][m+1] = '\0';
            state ^= 1;
        }

        for(ll i = 1; i <= n; i++)
            printf("%s\n", ans[i]+1);
    }

    return 0;
}