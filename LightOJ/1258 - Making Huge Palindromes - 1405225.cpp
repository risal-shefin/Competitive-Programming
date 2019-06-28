#include <bits/stdc++.h>
using namespace std;
#define ll unsigned long long
const ll sz = 1000000;
ll pw[sz + 9], hsh[sz + 9], hrev[sz + 9];
string s;
int main()
{
    std::ios_base::sync_with_stdio(false);
    pw[0] = 1;
    for(ll i = 1; i <= sz + 5; i++)
        pw[i] = pw[i - 1] * 47;
      ll t, cs = 0;
    cin >> t;
    while(t--) {
        cin >> s;
          for(ll i = 0; i < s.size(); i++) {
            if(i == 0) {
                hsh[i] = (s[i] - 'a' + 1);
                continue;
            }
            hsh[i] = hsh[i - 1] * 47 + (s[i] - 'a' + 1);
        }
          hrev[s.size()] = 0;
        for(ll i = s.size() - 1; i >= 0; i--) {
            hrev[i] = hrev[i + 1] * 47 + (s[i] - 'a' + 1);
            if(i == 0)
                break;
        }
          ll toadd = s.size() - 1;
        for(ll i = 0; i < s.size(); i++) {
            ll now1 = i == 0? hsh[s.size() - 1]: hsh[s.size() - 1] - (hsh[i - 1] * pw[s.size() - i]);
            ll now2 = hrev[i];
              if(now1 == now2) {
                toadd = i;
                break;
            }
        }
          cout << "Case " << ++cs << ": " << s.size() + toadd << endl;
    }
      return 0;
}
 
