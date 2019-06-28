#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll vis[27][27][27];
struct node {
    ll i, j, k, lev;
    node(ll _i, ll _j, ll _k, ll _lev) {
        i = _i;
        j = _j;
        k = _k;
        lev = _lev;
    }
};
ll ci[] = {1, -1, 0, 0, 0, 0};
ll cj[] = {0, 0, 1, -1, 0, 0};
ll ck[] = {0, 0, 0, 0, 1, -1};
int main()
{
    std::ios::sync_with_stdio(false);
    ll t, caseno = 0;
    cin >> t;
    while(t--) {
        memset(vis, 0, sizeof(vis));
        string start, stop;
        cin >> start >> stop;
          ll con;
        cin >> con;
        while(con--) {
            string a, b, c;
            cin >> a >> b >> c;
              for(ll i = 0; i < a.length(); i++) {
                for(ll j = 0; j < b.length(); j++) {
                    for(ll k = 0; k < c.length(); k++) {
                        vis[ a[i] - 'a' ][  b[j] - 'a' ][ c[k] - 'a' ] = 1;
                    }
                }
            }
        }
          cout << "Case " << ++caseno << ": ";
        if(vis[ start[0] - 'a'][ start[1] - 'a'][start[2] - 'a'] == 1) {
            cout << "-1" << endl;
            continue;
        }
        if(vis[ stop[0] - 'a'][ stop[1] - 'a'][stop[2] - 'a'] == 1) {
            cout << "-1" << endl;
            continue;
        }
          queue <node> q;
        q.push( node(start[0] - 'a', start[1] - 'a', start[2] - 'a', 0) );
        vis[ start[0] - 'a'][ start[1] - 'a'][start[2] - 'a'] = 1;
        while(!q.empty()) {
            node u = q.front();
            q.pop();
              if(u.i == stop[0] - 'a' && u.j == stop[1] - 'a' && u.k == stop[2] - 'a') {
                cout  << u.lev << endl;
                break;
            }
              for(ll i = 0; i < 6; i++) {
                ll ni = u.i + ci[i];
                ll nj = u.j + cj[i];
                ll nk = u.k + ck[i];
                  ni = (ni + 26) % 26;
                nj = (nj + 26) % 26;
                nk = (nk + 26) % 26;
                  if(vis[ni][nj][nk] == 0) {
                    vis[ni][nj][nk] = 1;
                    q.push( node(ni, nj, nk, u.lev + 1) );
                }
              }
        }
          if(vis[ stop[0] - 'a'][ stop[1] - 'a'][stop[2] - 'a'] == 0) {
            cout << "-1" << endl;
            continue;
        }
    }
      return 0;
}
 
