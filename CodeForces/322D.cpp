#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll n, m, aid = 1, did = 1, atk[105], def[105], c[105];
char s[10];
int main()
{
    cin >> n >> m;
    for(ll i = 1; i <= n; i++)
    {
        scanf("%s", s);
        if(s[0] == 'A')
            scanf("%lld", &atk[aid++]);
        else
            scanf("%lld", &def[did++]);
    }
    for(ll i = 1; i <= m; i++)
    {
        scanf("%lld", &c[i]);
    }
    sort(atk + 1, atk + aid);
    sort(c + 1, c + m + 1, greater <ll> ());
    ll indx = 1, sum = 0, off = 0;
    for(ll i = 1; i <= m; i++)
    {
        if(i >= aid)
            break;
        if(c[i] < atk[i])
        {
            off = 1;
            break;
        }
        sum += (c[i] - atk[i]);
        indx = i + 1;
    }
    multiset <ll> cel;
    bool flag = 1;
    if(off == 1 || indx > m)
    {
        goto p;
        return 0;
    }
    for(ll i = indx; i <= m; i++)
        cel.insert( c[i] );
    for(ll i = 1; i < did; i++)
    {
        auto it = cel.upper_bound(def[i]);
        if(it == cel.end())
        {
            goto p;
        }
        cel.erase(it);
    }
    while(!cel.empty())
    {
        auto it = cel.begin();
        sum += *it;
        cel.erase(it);
        //cout << *it << "  " << 5 << endl;
    }
    p:
    ll sum2 = 0, cnt = 0;
    multiset <ll> cel2;
    for(ll i = 1; i <= m; i++)
        cel2.insert( c[i] );
    for(ll i = 1; i < did; i++)
    {
        auto it = cel2.upper_bound(def[i]);
        if(it == cel2.end())
            continue;
        cnt++;
        cel2.erase(it);
    }
    for(ll i = 1; i < aid; i++)
    {
        auto it = cel2.upper_bound(atk[i]);
        if(it == cel2.end())
            continue;
        cnt++;
        sum2 += (*it - atk[i]);
        cel2.erase(it);
    }
    while(!cel2.empty() && cnt == n)
    {
        auto it = cel2.begin();
        sum2 += *it;
        cel2.erase(it);
    }
    cout << max(sum, sum2) << endl;
    return 0;
}
