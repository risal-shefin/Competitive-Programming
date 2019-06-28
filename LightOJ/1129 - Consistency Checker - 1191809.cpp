#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll pwr[15];
string ara[100009];
bool cmp(string s1, string s2)
{
    return s1.length() < s2.length();
}
int main()
{
    std::ios::sync_with_stdio(false);
    pwr[0] = 1;
    for(ll i = 1; i <= 10; i++) {
        pwr[i] = pwr[i - 1] * 11;
    }
      ll t, caseno = 0;
    cin >> t;
    while(t--) {
        map <ll, bool> mark;
        bool state = 1;
        ll n;
        cin >> n;
          for(ll i = 0; i < n; i++) {
            cin >> ara[i];
        }
          sort(ara, ara + n);
        for(ll i = 0; i < n; i++)
        {
            ll hsh = 0;
            ll len = ara[i].length();
            for(ll j = 0; j < len; j++)
            {
                hsh = ( (ara[i][j] - 47) * pwr[j]) + hsh;
                if(mark[hsh] == 1)
                {
                    //cout << "  " << hsh << endl;
                    state = 0;
                }
            }
            mark[hsh] = 1;
        }
          if(state)
            printf("Case %lld: YES\n", ++caseno);
        else
            printf("Case %lld: NO\n", ++caseno);
    }
      return 0;
}
