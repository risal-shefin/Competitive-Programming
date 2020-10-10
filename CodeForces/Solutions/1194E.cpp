#include <bits/stdc++.h>
using namespace std;

#define ll int
#define pll pair <ll, ll>
#define x first
#define y second
const ll ad = 5002;
ll sz = ad + 5002;

struct line {
    ll x1, x2, y;
} hor[5009];

struct vline {
    ll y1, y2, x;
} vl[5009];

vector <pll> hz[ad+5009];
vector <ll> track[ad+5009];
ll h = 0, v = 0;

bool cmp(line &a, line &b) {
    return a.y < b.y;
}

ll BITree[10009];

///do this for range: getSum(r) - getSum(l - 1)
ll getSum(ll index)
{
    ll sum = 0; // Iniialize result

    // Traverse ancestors of BITree[index]
    while (index>0)
    {
        // Add current element of BITree to sum
        sum += BITree[index];

        // Move index to parent node in getSum View
        index -= index & (-index);
    }
    return sum;
}

void updateBIT(ll n, ll index, ll val)

{

    // Traverse all ancestors and add 'val'
    while (index <= n)
    {
       // Add 'val' to current node of BI Tree
       BITree[index] += val;

       // Update index to that of parent in update View
       index += index & (-index);
    }
}

int main()

{
    ll n, x1, y1, x2, y2;
    scanf("%d", &n);
    for(ll i = 1; i <= n; i++) {
        scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
        if(x1 > x2) swap(x1, x2);
        if(y1 > y2) swap(y1, y2);
        x1 += ad, x2 += ad, y1 += ad, y2 += ad;

        if(x1 == x2)
            vl[v++] = {y1, y2, x1};
        else {
            hor[h++] = {x1, x2, y1};
            hz[y1].push_back(pll(x1, x2));
        }
    }
    sort(hor, hor + h, cmp);

    long long ans = 0;
    for(ll i = 0; i < h; i++) {

        for(ll j = 0; j < v; j++) {
            if(vl[j].x < hor[i].x1 || vl[j].x > hor[i].x2)
                continue;
            if(vl[j].y1 > hor[i].y || vl[j].y2 <= hor[i].y)
                continue;

            updateBIT(sz, vl[j].x, 1);
            track[vl[j].y2].push_back(vl[j].x);
        }

        for(ll j = hor[i].y + 1; j < sz; j++) {
            for(pll p: hz[j]) {
                ll res = getSum(p.second) - getSum(p.first - 1);
                ans += ((long long)res * (res - 1)) / 2;
            }

            for(ll xx: track[j]) updateBIT(sz, xx, -1);
            track[j].clear();
        }
    }

    cout << ans << endl;

    return 0;
}