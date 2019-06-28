#include <bits/stdc++.h>
using namespace std;
#define ll long long
struct node {
    ll x, y, sz;
    node(ll _x, ll _y, ll _sz) {
        x = _x;
        y = _y;
        sz = _sz;
    }
};
vector <node> ans;
char grid[105][105];
bool check[105][105];
int main()
{
    ll n, m;
    cin >> n >> m;
    for(ll i = 1; i <= n; i++) {
        scanf("%s", grid[i] + 1);
    }
    for(ll i = 2; i < n; i++) {
        for(ll j = 2; j < m; j++) {
            //cout << grid[i][j];
            if(grid[i][j] != '*')
                continue;
            ll cnt1 = 0, cnt2 = 0, cnt3 = 0, cnt4 = 0;
            for(ll k = j - 1; k >= 1; k--) {
                if(grid[i][k] != '*')
                    break;
                cnt1++;
            }
            //cout << 5;
            for(ll k = j + 1; k <= m; k++) {
                if(grid[i][k] != '*')
                    break;
                cnt2++;
            }
            for(ll k = i - 1; k >= 1; k--) {
                if(grid[k][j] != '*')
                    break;
                cnt3++;
            }
            for(ll k = i + 1; i <= n; k++) {
                if(grid[k][j] != '*')
                    break;
                cnt4++;
            }
            ll cnt = min(cnt1, cnt2);
            cnt = min(cnt3, cnt);
            cnt = min(cnt4, cnt);
            if(cnt == 0)
                continue;
            check[i][j] = 1;
            ans.push_back( node(i, j, cnt));
            for(ll k = j - 1, l = 1; l <= cnt; k--, l++) {
                check[i][k] = 1;
            }
            for(ll k = j + 1, l = 1; l <= cnt; k++, l++) {
               check[i][k] = 1;
            }
            for(ll k = i - 1, l = 1; l <= cnt; k--, l++) {
                check[k][j] = 1;
            }
            for(ll k = i + 1, l = 1; l <= cnt; k++, l++) {
                check[k][j] = 1;
            }
        }
        //cout <<endl;
    }
    for(ll i = 1; i <= n; i++) {
        for(ll j = 1; j <= m; j++) {
            if(grid[i][j] == '*' && check[i][j] == 0) {
                printf("-1\n");
                return 0;
            }
        }
    }
    cout << ans.size() << endl;
    for(ll i = 0; i < ans.size(); i++) {
        printf("%lld %lld %lld\n", ans[i].x, ans[i].y, ans[i].sz);
    }
    return 0;
}
