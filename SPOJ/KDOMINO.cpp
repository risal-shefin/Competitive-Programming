#include <bits/stdc++.h>
using namespace std;

#define block 1000
#define ll long long
#define ad 200002

ll ara[200009], answer = 0, answer2;
bool ans[200009];
unordered_map <ll, ll> cnt;
ll cntcnt[ad + 200009];

struct query {
    ll l, r, k, i;
} qry[200009];

bool compare(query a, query b)

{
    if(a.l / block != b.l / block) {
        return a.l / block < b.l / block;
    }

    return a.r < b.r;
}

void del(ll indx)

{
    ll tmp = cnt[ ara[indx] ]--;
    cntcnt[ad + tmp]--;
    cntcnt[ad + tmp - 1]++;

    if(cntcnt[ad + answer] == 0)
        answer--;
}

void add(ll indx)

{
    ll tmp = cnt[ ara[indx] ]++;
    cntcnt[ad + tmp ]--;
    cntcnt[ad + tmp + 1 ]++;
    answer = max(answer, tmp + 1);
}

int main()

{

    ll n, q;
    scanf("%lld %lld", &n, &q);
    answer = 0;

    for(ll i = 1; i <= n; i++)
        scanf("%lld", &ara[i]);

    for(ll i = 0; i < q; i++)
    {
        scanf("%lld %lld %lld", &qry[i].l, &qry[i].r, &qry[i].k);
        qry[i].i = i;
    }

    sort(qry, qry + q, compare);

    ll curl = 1, curr = 1;
    for(ll i = 0; i < q; i++)
    {

        while(curl < qry[i].l)
        {
            del(curl);
            curl++;
        }

        while(curl > qry[i].l)
        {
            add(curl - 1);
            curl--;
        }

        while(curr <= qry[i].r)
        {
            add(curr);
            curr++;
        }

        while(curr > qry[i].r + 1)
        {
            del(curr - 1);
            curr--;
        }

        //cout << i << "  " << endl;

        answer2 = answer * qry[i].k;
        ll len = qry[i].r - qry[i].l + 1;
        if(answer2 >= len)
            ans[ qry[i].i ] = 1;
        else
            ans[ qry[i].i ] = 0;
    }

    for(ll i = 0; i < q; i++) {
        if(ans[i] != 1)
            printf("NO\n");
        else
            printf("YES\n");
    }

    return 0;
}


