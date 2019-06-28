#include <bits/stdc++.h>
using namespace std;
#define ll long long
struct node {
    string s;
    ll id;
} ara[100009], ara2[100009];
ll BITree[100009];
bool cmp(node a, node b)
 {
    return a.s < b.s;
}
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
    std::ios_base::sync_with_stdio(false);
     ll n;
    cin >> n;
    for(ll i = 1; i <= n; i++)
        cin >> ara[i].s;
     sort(ara + 1, ara + n + 1, cmp);
     for(ll i = 1; i <= n; i++) {
        ara[i].id = i;
         string tmp = ara[i].s;
        reverse(tmp.begin(), tmp.end());
         ara2[i].s = tmp;
        ara2[i].id = i;
    }
     sort(ara2 + 1, ara2 + n + 1, cmp);
     ll ans = 0;
    for(ll i = 1; i <= n; i++) {
        updateBIT(n, ara2[i].id, 1);
         ans += (getSum(n) - getSum(ara2[i].id) );
    }
     cout << ans << endl;
     return 0;
}
