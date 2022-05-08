#include <bits/stdc++.h>
#define MAX_N 90001
using namespace std;
typedef long long ll;

int n, t;
string s;
int SA[MAX_N], LCP[MAX_N];
int tmp[MAX_N], poz[MAX_N];

//Complexity: O(n log^2 n) Suffix Array, O(n) LCP

inline bool suff_compare(int i, int j)
{
    if (poz[i] != poz[j]) return (poz[i] < poz[j]);
    i += t;
    j += t;
    if (i < n && j < n) return (poz[i] < poz[j]);
    else return (i > j);
}

inline void buildSA()
{
    for (int i=0;i<n;i++)
    {
        SA[i] = i;
        poz[i] = s[i];
    }
    for (t = 1 ; t < 2*n+1; t *= 2)
    {
        sort(SA, SA + n, suff_compare);
        for (int i=0;i<n-1;i++)
        {
            tmp[i+1] = tmp[i];
            if (suff_compare(SA[i],SA[i+1])) tmp[i+1]++;
        }
        for (int i=0;i<n;i++)
        {
            poz[SA[i]] = tmp[i];
        }
        if (tmp[n-1] == n-1) break;
    }
}

inline void buildLCP()
{
    int k = 0;
    for (int i=0;i<n;i++)
    {
        if (poz[i] != n-1)
        {
            int j = SA[poz[i]+1];
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

int main()
{
    n = 6;
    s = "banana";

    memset(LCP, 0, sizeof(LCP));
    buildSA();
    buildLCP();

    for (int i=0;i<n;i++) printf("%d ",SA[i]);
    printf("\n");
    for (int i=0;i<n;i++) printf("%d ",LCP[i]);
    printf("\n");

    return 0;
}
