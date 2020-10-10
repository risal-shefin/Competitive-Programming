#include <bits/stdc++.h>
using namespace std;

#define block 800
#define ll int
ll ara[500009], ans[500009], cnt[500009], cntblock[block], num[500009], tot = 0;


struct query
{
    ll l, r, i;
} qry[500009];

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
    ll val = ara[indx];
    if(cnt[ val ] == 1) {
        cntblock[ val / block ]--;
        tot--;
    }
    cnt[ val ]--;
    if(cnt[ val ] == 1) {
        cntblock[ val / block ]++;
        tot++;
    }
}

inline void add(ll indx)

{
    ll val = ara[indx];
    if(cnt[ val ] == 1) {
        cntblock[ val / block ]--;
        tot--;
    }
    cnt[ val ]++;
    if(cnt[ val ] == 1) {
        cntblock[ val / block ]++;
        tot++;
    }
}

inline ll res()

{
    if(tot == 0)
        return 0;

    for(ll i = 0; i < block; i++) {
        if(cntblock[i] > 0)
        {

            for(ll j = i * block; j < i * block + block ; j++)
                if(cnt[j] == 1)
                    return j;
        }
    }

    return 0;
}

int main()

{

    ll n, q;
    scanf("%d", &n);

    for(ll i = 0; i < n; i++)
        scanf("%d", &ara[i]);

    scanf("%d", &q);
    for(ll i = 0; i < q; i++)
    {
        scanf("%d %d", &qry[i].l, &qry[i].r);
        qry[i].l--;
        qry[i].r--;
        qry[i].i = i;
    }

    sort(qry, qry + q, compare);

    ll curl = 0, curr = -1;
    for(ll i = 0; i < q; i++)
    {

        while(curr < qry[i].r)
        {
            curr++;
            add(curr);
        }

        while(curr > qry[i].r)
        {
            del(curr);
            curr--;
        }

        while(curl > qry[i].l)
        {
            curl--;
            add(curl);
        }

        while(curl < qry[i].l)
        {
            del(curl);
            curl++;
        }

        ans[ qry[i].i ] = res();
    }

    for(ll i = 0; i < q; i++)
        printf("%d\n", ans[i]);



    return 0;
}