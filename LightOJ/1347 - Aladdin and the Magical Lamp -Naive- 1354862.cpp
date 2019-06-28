#include <bits/stdc++.h>
#define MAX_N 90001
using namespace std;
typedef long long ll;
ll n, t;
string s;
ll SA[MAX_N], LCP[MAX_N];
ll tmp[MAX_N], poz[MAX_N];
//Complexity: O(n log^2 n) Suffix Array, O(n) LCP
inline bool suff_compare(ll i, ll j)
{
    if (poz[i] != poz[j]) return (poz[i] < poz[j]);
    i += t;
    j += t;
    if (i < n && j < n) return (poz[i] < poz[j]);
    else return (i > j);
}
inline void buildSA()
{
    for (ll i=0;i<n;i++)
    {
        SA[i] = i;
        poz[i] = s[i];
    }
    for (t = 1 ; t < 2*n+1; t *= 2)
    {
        sort(SA, SA + n, suff_compare);
        for (ll i=0;i<n-1;i++)
        {
            tmp[i+1] = tmp[i];
            if (suff_compare(SA[i],SA[i+1])) tmp[i+1]++;
        }
        for (ll i=0;i<n;i++)
        {
            poz[SA[i]] = tmp[i];
        }
        if (tmp[n-1] == n-1) break;
    }
}
inline void buildLCP()
{
    ll k = 0;
    for (ll i=0;i<n;i++)
    {
        if (poz[i] != n-1)
        {
            ll j = SA[poz[i]+1];
            while (s[i+k] == s[j+k]) k++;
            LCP[poz[i]] = k;
            if (k > 0) k--;
        }
    }
}
// n = string length
// s = the string
// memset(LCP, 0, sizeof(LCP));  setting all index of LCP to zero
// buildSA(); for building suffix array
// buildLCP(); for building LCP array
int main()
{
    //freopen("in.txt", "r", stdin);
    std::ios_base::sync_with_stdio(false);
    ll ts, caseno = 0;
    cin >> ts;
    while(ts--) {
        string s1, s2, s3;
        cin >> s1 >> s2 >> s3;
        s = s1 + "!" + s2 + "@" + s3;
        n = s.length();
          memset(LCP, 0, sizeof(LCP));
        buildSA();
        buildLCP();
          bool chk = 0, chk2 = 0, chk3 = 0;
        ll cnt = 0, mx = 0, prvl = -1;
        ll len1 = s1.length();
        ll len2 = len1 + 1 + s2.length();
        ll lo = 1, hi = min(s1.length(), min(s2.length(), s3.length()) );
          while(lo <= hi)
        {
            ll len = (lo + hi) / 2;
            chk = 0, chk2 = 0, chk3 = 0;
            for(ll i = 0; i < n; i++)
            {
                //cout << SA[i] << " " << LCP[i] << endl;
                if(LCP[i] < len)
                    continue;
                  chk = 0, chk2 = 0, chk3 = 0;
                ll stp = SA[i] + len - 1;
                if(stp < len1) chk = 1;
                else if(stp  < len2) chk2 = 1;
                else chk3 = 1;
                  for(ll j = i + 1; j < n; j++)
                {
                      stp = SA[j] + len - 1;
                      if(stp < len1) chk = 1;
                    else if(stp  < len2) chk2 = 1;
                    else chk3 = 1;
                      if(chk & chk2 & chk3)
                        break;
                    //cout << 5 << " kkk " << chk << endl;
                    if(LCP[j] < len)
                        break;
                }
                  if(chk & chk2 & chk3)
                    break;
            }
              if(chk & chk2 & chk3) {
                lo = len + 1;
                mx = len;
            }
            else
                hi = len - 1;
        }
          printf("Case %lld: %lld\n", ++caseno, mx);
    }
        return 0;
}
   
