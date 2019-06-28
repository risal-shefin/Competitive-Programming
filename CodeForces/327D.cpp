#include <bits/stdc++.h>
using namespace std;
char grid[509][509];
bool vis[509][509];
#define ll long long
vector <string> v;
ll n, m;
string make_string(string s, ll x, ll y)
{
    string tmp1 = "";
    while(x != 0) {
        ll tmp = x % 10;
        x /= 10;
        tmp1 += (tmp + '0');
    }
    reverse(tmp1.begin(), tmp1.end());
    string tmp2 = "";
    while(y != 0) {
        ll tmp = y % 10;
        y /= 10;
        tmp2 += (tmp + '0');
    }
    reverse(tmp2.begin(), tmp2.end());
    string ans = s + " " + tmp1 + " " + tmp2;
    return ans;
}
void dfs(ll x, ll y, ll cnt)
{
    if(x < 1 || y < 1 || x > n || y > m)
        return;
    if(grid[x][y] == '#')
        return;
    if(vis[x][y])
        return;
    vis[x][y] = 1;
    v.push_back( make_string("B", x, y) );
    dfs(x, y + 1, cnt + 1);
    dfs(x, y - 1, cnt + 1);
    dfs(x + 1, y, cnt + 1);
    dfs(x - 1, y, cnt + 1);
    if(cnt != 1) {
        v.push_back( make_string("D", x, y) );
        v.push_back( make_string("R", x, y) );
    }
}
int main()
{
    cin >> n >> m;
    for(ll i = 1; i <= n; i++)
        scanf(" %s", grid[i] + 1);
    for(ll i = 1; i <= n; i++) {
        for(ll j = 1; j <= m; j++) {
            if(grid[i][j] == '#')
                continue;
            dfs(i, j, 1);
        }
    }
    printf("%d\n", v.size());
    for(ll i = 0; i < v.size(); i++) {
        printf("%s\n", v[i].c_str());
    }
    return 0;
}
