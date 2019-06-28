#include <bits/stdc++.h>
#define MAX_N 50001
using namespace std;
typedef unsigned long long ll;
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
// LCP is the longest common prefix with the next suffix here
struct point {
    ll start, stop;
} pnt[MAX_N];
bool operator <(point a, point b)
{
    return a.start < b.start;
}
ll hsh[MAX_N], pwr[MAX_N];
int main()
{
    std::ios_base::sync_with_stdio(false);
    pwr[0] = 1;
    for(ll i = 1; i < MAX_N; i++)
        pwr[i] = pwr[i - 1] * 47;
      ll t, cs = 0;
    cin >> t;
    while(t--) {
        string s2;
        cin >> s;
        cin >> s2;
        n = s.length();
          memset(LCP, 0, sizeof(LCP));
        buildSA();
        buildLCP();
          for(ll i = 0; i < n; i++) {
            if(i == 0)
                hsh[i] = s[i] - 'a' + 1;
            else
                hsh[i] = hsh[i - 1] * 47 + (s[i] - 'a' + 1);
        }
          ll hsh2 = 0;
        for(ll i = 0; i < s2.length(); i++)
            hsh2 = hsh2 * 47 + (s2[i] - 'a' + 1);
          ll indx = 0;
        for(ll i = 0; i + s2.length() - 1 < n; i++) {
            ll tmp;
            if(i == 0)
                tmp = hsh[i + s2.length() - 1];
            else
                tmp = hsh[i + s2.length() - 1] - (hsh[i - 1] * pwr[s2.length()]);
              if(hsh2 == tmp) {
                pnt[indx].start = i;
                pnt[indx].stop = i + s2.length() - 1;
                //cout << pnt[indx].start << "  " << pnt[indx].stop << endl;
                indx++;
            }
        }
          ll ans = 0;
        //cout << indx << endl;
        for(ll i = 0; i < n; i++) {
            ll len = n - SA[i];
            ll start = SA[i];
            point tmp;
            tmp.start = start, tmp.stop = 0;
            ll ns = lower_bound(pnt, pnt + indx, tmp) - pnt;
            //cout << start << "  " << pnt[ns].start << "  " << ns << endl;
            if(ns == indx)
                ans += (len - LCP[i]);
            else {
                if(pnt[ns].stop > start + len - 1)
                    ans += (len - LCP[i]);
                else {
                    ll stp;
                    if(LCP[i] > 0) {
                        if(start + LCP[i] < pnt[ns].stop)
                            ans += (pnt[ns].stop - (start + LCP[i]) );
                    }
                    else
                        ans += (pnt[ns].stop - start);
                      //cout << ans << endl;
                }
            }
              //cout << ans << endl;
        }
          cout << "Case " << ++cs << ": " << ans << endl;
      }
      return 0;
}
   
