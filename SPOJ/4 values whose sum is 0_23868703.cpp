#include <bits/stdc++.h>
using namespace std;
#define ll int
ll ara[2500][4], lst1[2500*2500 + 5], lst2[2500*2500 + 5], id1 = 0, id2 = 0;
int main()
 {
    ll n;
    cin >> n;
    for(ll i = 0; i < n; i++) {
        for(ll j = 0; j < 4; j++)
            scanf("%d", &ara[i][j]);
    }
     for(ll i = 0; i < n; i++) {
        for(ll j = 0; j < n; j++)
            lst1[id1++] = ara[i][0] + ara[j][1];
    }
    sort(lst1, lst1 + id1);
     for(ll i = 0; i < n; i++) {
        for(ll j = 0; j < n; j++)
            lst2[id2++] = ara[i][2] + ara[j][3];
    }
    sort(lst2, lst2 + id2, greater <ll> ());
//    cout << endl;
//    for(ll i = 0; i < id1; i++)
//        cout << lst1[i] << " ";
//    cout << endl;
//    for(ll i = 0; i < id2; i++)
//        cout << lst2[i] << " ";
//    cout << endl;
     ll ans = 0, cnt1 = 0, cnt2 = 0, k = 0;
    for(ll i = 0; i < id1;) {
        cnt1 = 1;
        i++;
        while(i < id1 && lst1[i] == lst1[i - 1]) {
            i++;
            cnt1++;
        }
         while(k < id2 && lst2[k] > -lst1[i-1])
            k++;
        if(k == id2 || lst2[k] < -lst1[i-1])
            continue;
         cnt2 = 1;
        k++;
        while(k < id2 && lst2[k] == lst2[k - 1]) {
            k++;
            cnt2++;
        }
          ans += (cnt1 * cnt2);
    }
     cout << ans << endl;
     return 0;
}
