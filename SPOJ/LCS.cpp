#include <bits/stdc++.h>
#define MAX_N 1000020
using namespace std;
#define ll int

int n, t;
char s[500099];
char punc[] = {'~', '!', '@', '#', '$', '%', '^' , '&', '*', '('};
int length[12], tree[4 * MAX_N], nxt[10][MAX_N], prv[10];
vector <int> id[2];

int SA[MAX_N], LCP[MAX_N];


int RA[MAX_N], tempRA[MAX_N];
int tempSA[MAX_N];
int c[MAX_N];
int Phi[MAX_N], PLCP[MAX_N];
// second approach: O(n log n)
// the input string, up to 100K characters
// the length of input string
// rank array and temporary rank array
// suffix array and temporary suffix array
// for counting/radix sort
void countingSort(int k) {
// O(n)
	int i, sum, maxi = max(300, n);
// up to 255 ASCII chars or length of n
	memset(c, 0, sizeof c);
// clear frequency table
	for (i = 0; i < n; i++)
// count the frequency of each integer rank
		c[i + k < n ? RA[i + k] : 0]++;
	for (i = sum = 0; i < maxi; i++) {
		int t = c[i]; c[i] = sum; sum += t;
	}
	for (i = 0; i < n; i++)
// shuffle the suffix array if necessary
		tempSA[c[SA[i] + k < n ? RA[SA[i] + k] : 0]++] = SA[i];
	for (i = 0; i < n; i++)
// update the suffix array SA
		SA[i] = tempSA[i];
}



void buildSA() {
// this version can go up to 100000 characters
	int i, k, r;
	for (i = 0; i < n; i++) RA[i] = s[i];
// initial rankings
	for (i = 0; i < n; i++) SA[i] = i;
// initial SA: {0, 1, 2, ..., n-1}
	for (k = 1; k < n; k <<= 1) {
// repeat sorting process log n times
		countingSort(k); // actually radix sort: sort based on the second item
		countingSort(0);
// then (stable) sort based on the first item
		tempRA[SA[0]] = r = 0;
// re-ranking; start from rank r = 0
		for (i = 1; i < n; i++)
// compare adjacent suffixes
			tempRA[SA[i]] = // if same pair => same rank r; otherwise, increase r
			    (RA[SA[i]] == RA[SA[i - 1]] && RA[SA[i] + k] == RA[SA[i - 1] + k]) ? r : ++r;
		for (i = 0; i < n; i++)
// update the rank array RA
			RA[i] = tempRA[i];
		if (RA[SA[n - 1]] == n - 1) break;
// nice optimization trick
	}
}

void buildLCP() {
	int i, L;
	Phi[SA[0]] = -1;
// default value
	for (i = 1; i < n; i++)
// compute Phi in O(n)
		Phi[SA[i]] = SA[i - 1];
// remember which suffix is behind this suffix
	for (i = L = 0; i < n; i++) {
// compute Permuted LCP in O(n)
		if (Phi[i] == -1) { PLCP[i] = 0; continue; }
// special case
		while (s[i + L] == s[Phi[i] + L]) L++;
// L increased max n times
		PLCP[i] = L;
		L = max(L - 1, 0);
// L decreased max n times
	}
	for (i = 0; i < n; i++)
// compute LCP in O(n)
		LCP[i] = PLCP[SA[i]];
// put the permuted LCP to the correct position
}

// n = string length
// s = the string
// memset(LCP, 0, sizeof(LCP));  setting all index of LCP to zero
// buildSA(); for building suffix array
// buildLCP(); for building LCP array
// LCP is the longest common prefix with the next suffix here

void build(ll lo, ll hi, ll node)

{
    if(lo == hi) {
        tree[node] = LCP[lo];
        return;
    }

    ll mid = (lo + hi) / 2;
    build(lo, mid, 2 * node);
    build(mid + 1, hi, 2 * node + 1);

    tree[node] = min(tree[2 * node], tree[2 * node + 1]);
}

ll query(ll lo, ll hi, ll left, ll right, ll node)

{
    if(lo > right || hi < left)
        return 1e9;
    if(lo >= left && hi <= right)
        return tree[node];

    ll mid = (lo + hi) / 2;
    ll p1 = query(lo, mid, left, right, 2 * node);
    ll p2 = query(mid + 1, hi, left, right, 2 * node + 1);

    return min(p1, p2);
}

int main()

{
    int add = 0, cnt = 0;
    while(scanf("%s", s + add) != EOF) {
        int len = strlen(s + add);
        s[add + len] = punc[cnt];
        length[cnt] = add + len;
        cnt++;
        add += len + 1;
    }
    s[add - 1] = '\0';
    n = strlen(s);

    if(cnt == 1) {
        printf("%s\n", s);
        return 0;
    }

    memset(LCP, 0, sizeof(LCP));
    buildSA();
    //cout << 5 << endl;
    buildLCP();

//    for (int i=0;i<n;i++) printf("%d ",SA[i]);
//    printf("\n");
//    for (int i=0;i<n;i++) printf("%d ",LCP[i]);
//    printf("\n");

//    ll start;
//    for(int i = 0; i < n; i++) {
//        start = SA[i];
//        for(ll j = 0; j < cnt; j++) {
//            if(start <= length[j]) {
//                id[j].push_back(i);
//                break;
//            }
//        }
//    }
    for(int i = 0; i < n; i++) {
        for(ll j = 0; j < cnt; j++) {
            if(SA[i] <= length[j]) {

                for(ll k = prv[j]; k <= i; k++)
                    nxt[j][k] = i;
                prv[j] = i + 1;

                break;
            }
        }
    }

    build(0, n - 1, 1);

    ll ans = 0, mark, now;
    for(ll i = 0; i < n; i++) {
        if(LCP[i] == 0)
            continue;

        mark = 0, now = i-1;
//        for(ll j = 0; j < cnt; j++) {
//            if(SA[i] <= length[j] && mark == -1)
//                mark = j;
//            else {
//                pos = upper_bound(id[j].begin(), id[j].end(), i) - id[j].begin();
//                if(pos == id[j].size()) {
//                    pos = -1;
//                    break;
//                }
//                now = max(id[j][pos], now);
//            }
//        }
        for(ll j = 0; j < cnt; j++) {
            if(i != 0 && nxt[j][i-1] == 0) {
                now = -1;
                break;
            }
            else if(nxt[j][i-1] == 0)
                mark++;
            now = max(now, nxt[j][i-1]);
        }

        if(now <= i - 1 || mark > 1)
            continue;

        ans = max(ans, query(0, n - 1, i, now, 1));
        //cout << i << "  " << now << " " << LCP[22] << " " << LCP[23] << endl;
    }

    cout << ans << endl;

    return 0;
