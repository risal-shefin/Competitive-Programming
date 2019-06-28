#include <bits/stdc++.h>
#define MAX_N 15009
using namespace std;
#define ll int
int t;
char s[MAX_N];
char punc[] = {'~', '!', '@', '#', '$', '%', '^' , '&', '*', '('};
int col[MAX_N];
int AN;
int A[3 * MAX_N + 100];
int cnt[MAX_N + 1]; // Should be >= 256
int SA[MAX_N + 1], LCP[MAX_N + 1];
/* Used by suffix_array. */
void radix_pass(int* A, int AN, int* R, int RN, int* D) {
memset(cnt, 0, sizeof(int) * (AN + 1));
int* C = cnt + 1;
for(int i = 0; i < RN; i++) ++C[A[R[i]]];
for(int i = -1, v = 0; i <= AN && v < RN; v += C[i++]) swap(v, C[i]);
for(int i = 0; i < RN; i++) D[C[A[R[i]]]++] = R[i];
}
/* DC3 in O(N) using 20N bytes of memory.  Stores the suffix array of the string
* [A,A+AN) into SA where SA[i] (0<=i<=AN) gives the starting position of the
* i-th least suffix of A (including the empty suffix).
*/
void suffix_array(int* A, int AN) {
// Base case... length 1 string.
if(!AN) {
    SA[0] = 0;
} else if(AN == 1) {
    SA[0] = 1; SA[1] = 0;
    return;
}
    // Sort all strings of length 3 starting at non-multiples of 3 into R.
int RN = 0;
int* SUBA = A + AN + 2;
int* R = SUBA + AN + 2;
for(int i = 1; i < AN; i += 3) SUBA[RN++] = i;
for(int i = 2; i < AN; i += 3) SUBA[RN++] = i;
A[AN + 1] = A[AN] = -1;
radix_pass(A + 2, AN - 2, SUBA, RN, R);
radix_pass(A + 1, AN - 1, R, RN, SUBA);
radix_pass(A + 0, AN - 0, SUBA, RN, R);
    // Compute the relabel array if we need to recursively solve for the
// non-multiples.
int resfix, resmul, v;
if(AN % 3 == 1) {
    resfix = 1; resmul = RN >> 1;
} else {
    resfix = 2; resmul = RN + 1 >> 1;
}
for(int i = v = 0; i < RN; i++) {
    v += i && (A[R[i - 1] + 0] != A[R[i] + 0] ||
               A[R[i - 1] + 1] != A[R[i] + 1] ||
               A[R[i - 1] + 2] != A[R[i] + 2]);
    SUBA[R[i] / 3 + (R[i] % 3 == resfix) * resmul] = v;
}
    // Recursively solve if needed to compute relative ranks in the final suffix
// array of all non-multiples.
if(v + 1 != RN) {
    suffix_array(SUBA, RN);
    SA[0] = AN;
    for(int i = 1; i <= RN; i++) {
      SA[i] = SA[i] < resmul ? 3 * SA[i] + (resfix==1?2:1) :
                3 * (SA[i] - resmul) + resfix;
    }
} else {
    SA[0] = AN;
    memcpy(SA + 1, R, sizeof(int) * RN);
}
    // Compute the relative ordering of the multiples.
int NMN = RN;
for(int i = RN = 0; i <= NMN; i++) {
    if(SA[i] % 3 == 1) {
      SUBA[RN++] = SA[i] - 1;
    }
}
radix_pass(A, AN, SUBA, RN, R);
    // Compute the reverse SA for what we know so far.
for(int i = 0; i <= NMN; i++) {
    SUBA[SA[i]] = i;
}
    // Merge the orderings.
int ii = RN - 1;
int jj = NMN;
int pos;
for(pos = AN; ii >= 0; pos--) {
    int i = R[ii];
    int j = SA[jj];
    int v = A[i] - A[j];
    if(!v) {
      if(j % 3 == 1) {
        v = SUBA[i + 1] - SUBA[j + 1];
      } else {
        v = A[i + 1] - A[j + 1];
        if(!v) v = SUBA[i + 2] - SUBA[j + 2];
      }
    }
    SA[pos] = v < 0 ? SA[jj--] : R[ii--];
}
}
/* Copies the string in s into A and reduces the characters as needed. */
void prep_string() {
int v = AN = 0;
memset(cnt, 0, 256 * sizeof(int));
for(char* ss = s; *ss; ++ss, ++AN) cnt[*ss]++;
for(int i = 0; i < AN; i++) cnt[s[i]]++;
for(int i = 0; i < 256; i++) cnt[i] = cnt[i] ? v++ : -1;
for(int i = 0; i < AN; i++) A[i] = cnt[s[i]];
}
/* Computes the reverse SA index.  REVSA[i] gives the index of the suffix
* starting a i in the SA array.  In other words, REVSA[i] gives the number of
* suffixes before the suffix starting at i.  This can be useful in itself but
* is also used for compute_lcp().
*/
int REVSA[MAX_N + 1];
void compute_reverse_sa() {
for(int i = 0; i <= AN; i++) {
    REVSA[SA[i]] = i;
}
}
/* Computes the longest common prefix between adjacent suffixes.  LCP[i] gives
* the length of the longest common prefix between the suffix starting at
* SA[i-1] and SA[i]. Runs in O(N) time.
*/
void compute_lcp() {
int len = 0;
for(int i = 0; i < AN; i++, len = max(0, len - 1)) {
    int s = REVSA[i];
    int j = SA[s - 1];
    for(; i + len < AN && j + len < AN && A[i + len] == A[j + len]; len++);
    LCP[s] = len;
}
}
deque <pair<ll,ll>> dq;
ll counter = 0, freq[MAX_N];
inline void ad(ll &cl)
{
    freq[cl]++;
    if(freq[cl] == 1)
        counter++;
}
inline void del(ll &cl)
{
    freq[cl]--;
    if(freq[cl] == 0)
        counter--;
}
int main()
{
    ll t, cs = 0;
    cin >> t;
    while(t--)
    {
        int add = 0, cnt = 0;
        while(scanf("%s", s + add))
        {
            int len = strlen(s + add);
            s[add + len] = punc[cnt];
            cnt++;
            add += len + 1;
            if(cnt == 3) break;
        }
        s[add - 1] = '\0';
        int n = strlen(s);
        if(cnt == 1)
        {
            printf("%s\n", s);
            return 0;
        }
        prep_string();
        suffix_array(A, n);
        compute_reverse_sa();
        compute_lcp();
//    for (int i=1;i<=n;i++) printf("%d ",SA[i]);
//    printf("\n");
//    for (int i=1;i<=n;i++) printf("%d ",LCP[i]);
//    printf("\n");
        dq.clear();
        memset(freq, 0, sizeof(freq));
        memset(col, 0, sizeof(col));
        counter = 0;
        ll i, j, k;
        for(ll i = 1; i <= n; i++)
        {
            if(!isalpha(s[i]))
                col[i] = 1;
            if(i != 0)
                col[i] += col[i - 1];
        }
        ll ans = 0, L = 0;
        for(i = 1; i <= n; i++)
        {
            while(dq.size() && dq[dq.size() - 1].first > LCP[i])
                dq.pop_back();
            dq.push_back(make_pair(LCP[i], i));
            ad(col[SA[i]]);
            while(counter == cnt)
            {
                ans = max(ans, dq[0].first);
                if(L == dq[0].second)
                    dq.pop_front();
                del(col[ SA[L++] ]);
                if(counter == cnt - 1)                  // LCP[i] holds the matching between ith and (i-1)th suffix.
                    ans = max(ans, dq[0].first);        // So, the suffix just deleted still has an impact.
            }
        }
        printf("Case %d: %d\n", ++cs, ans);
    }
    return 0;
}

