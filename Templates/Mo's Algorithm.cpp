#include <bits/stdc++.h>
using namespace std;

#define block 320
#define ll long long
ll ara[100009], ans[100009], answer = 0, cnt[100009];

struct query {
    ll l, r, i;
} qry[100009];

bool compare(query a, query b)

{
    ll tmp = a.l / block;
    if(tmp != b.l / block)
    {
        return a.l < b.l;
    }

    if( tmp & 1)
        return a.r < b.r;

    return a.r > b.r;
}

inline void del(ll indx)

{
    cnt[ ara[indx] ]--;
    if(cnt[ ara[indx] ] == 0)
        answer--;
}

inline void add(ll indx)

{
    cnt[ ara[indx] ]++;
    if(cnt[ ara[indx] ] == 1)
        answer++;
}

int main()

{

    ll t, caseno = 0;
    scanf("%lld", &t);
    while(t--) {
        ll n, q;
        scanf("%lld %lld", &n, &q);
        answer = 0;

        for(ll i = 0; i < n; i++)
            scanf("%lld", &ara[i]);

        for(ll i = 0; i < q; i++) {
            scanf("%lld %lld", &qry[i].l, &qry[i].r);
            qry[i].l--;
            qry[i].r--;
            qry[i].i = i;
        }

        sort(qry, qry + q, compare);

        ll curl = 0, curr = 0;
        for(ll i = 0; i < q; i++) {

            while(curl < qry[i].l) {
                del(curl);
                curl++;
            }

            while(curl > qry[i].l) {
                add(curl - 1);
                curl--;
            }

            while(curr <= qry[i].r) {
                add(curr);
                curr++;
            }

            while(curr > qry[i].r + 1) {
                del(curr - 1);
                curr--;
            }

            ans[ qry[i].i ] = answer;
        }

        printf("Case %lld:\n", ++caseno);
        for(ll i = 0; i < q; i++)
            printf("%lld\n", ans[i]);

        for(ll i = 0; i <= 100000; i++)
            cnt[i] = 0;

    }

    return 0;
}
/* To handle updates:
// Block Size = (2*n*n)^(1/3). Complexity: O(n*n^(2/3))
// qry[i].t = count of updates before this query
Comparator:
const bool operator <(const query &a, const query &b) {
    if(a.l / block != b.l / block) return a.l < b.l;
    const ll tmp2 = a.r/block;
    if(tmp2 != b.r/block) return a.r < b.r;
    if(tmp2 & 1) return a.t < b.t;
    return a.t > b.t;
}
// in doUpdate(), you’ve to either perform an update or revert the update based on the status of this update.
ll curl = 0, curr = 0, unow = -1;
for(ll i = 0; i < q; i++) {
    while(unow < qry[i].t ) {
        unow++;
        doUpdate(unow);
    }
    while(unow > qry[i].t) {
        doUpdate(unow);
        unow--;
    }
    // Mo’s typical add,del, ans calc etc. part here
}
*/
