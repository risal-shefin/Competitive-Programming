#include <bits/stdc++.h>
#define MAX_N 10009
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
    std::ios_base::sync_with_stdio(false);
    ll t, caseno = 0;
    cin >> t;
    while(t--) {
        cin >> s;
        n = s.length();
        ll p, q;
        cin >> p >> q;
          memset(LCP, 0, sizeof(LCP));
        buildSA();
        buildLCP();
          ll ans = 0;
        for(ll i = 0; i < n; i++) {
            ll len = n - SA[i];
            ll start = max(p, LCP[i] + 1);
            ll stop = min(q, len);
            //cout << len << "  " << LCP[i] << endl;
            ans += max(0LL, stop - start + 1);
        }
          cout << "Case " << ++caseno << ": " << ans << endl;
    }
      return 0;
}
   
