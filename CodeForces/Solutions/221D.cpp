#include <bits/stdc++.h>
using namespace std;

#define block 320

int ara[100009], ans[100009], cnt[100009], answer = 0;

struct query {
    int l, r, i;
} qry[100009];

bool compare(query a, query b)

{
    if(a.l / block != b.l / block) {
        return a.l / block < b.l / block;
    }

    return a.r < b.r;
}

void del(int indx)

{
    if(ara[indx] > 100000)
        return;
    cnt[ ara[indx] ]--;
    if(cnt[ ara[indx] ] == ara[indx] - 1)
        answer--;
    if(cnt[ ara[indx] ] == ara[indx])
        answer++;
}

void add(int indx)

{
    if(ara[indx] > 100000)
        return;
    cnt[ ara[indx] ]++;
    if(cnt[ ara[indx] ] == ara[indx])
        answer++;

    if(cnt[ ara[indx] ] == ara[indx] + 1)
        answer--;
}

int main()

{
    int n, q;
    scanf("%d %d", &n, &q);
    answer = 0;

    for(int i = 0; i < n; i++)
        scanf("%d", &ara[i]);

    for(int i = 0; i < q; i++)
    {
        scanf("%d %d", &qry[i].l, &qry[i].r);
        qry[i].l--;
        qry[i].r--;
        qry[i].i = i;
    }

    sort(qry, qry + q, compare);

    int curl = 0, curr = 0;
    for(int i = 0; i < q; i++)
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

        ans[ qry[i].i ] = answer;
    }

    for(int i = 0; i < q; i++)
        printf("%d\n", ans[i]);

    for(int i = 0; i <= 100000; i++)
        cnt[i] = 0;


    return 0;
}