#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define x first
#define y second
#define pii pair <ll, ll>

int main()

{

    vector <pii> points, opposite;
    ll n;
    scanf("%lld", &n);
    for(ll i = 1; i <= n; i++)
    {
        ll xx, yy;
        scanf("%lld %lld", &xx, &yy);
        points.push_back( make_pair(xx, yy));
    }

    for(ll i = 0; i < points.size(); i++)
    {
        for(ll j = i + 1; j < points.size(); j++)
        {
            opposite.push_back( make_pair(points[i].x + points[j].x, points[i].y + points[j].y));
        }
    }

    sort(opposite.begin(), opposite.end());
    ll cnt = 0, res = 0;
    for(ll i = 1; i < opposite.size(); i++)
    {
        if(opposite[i] == opposite[i - 1])
        {
            cnt++;
        }
        else
        {
            res += (cnt * (cnt + 1)) / 2;
            cnt = 0;
        }
    }

    res += (cnt * (cnt + 1)) / 2;
    printf("%lld\n", res);


    return 0;
}