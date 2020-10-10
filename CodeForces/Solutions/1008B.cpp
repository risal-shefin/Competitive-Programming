#include <bits/stdc++.h>
using namespace std;

#define ll long long

struct node {
    ll h, w;
} rec[100009];

int main()

{
    ll n;
    cin >> n;

    bool flag = 1;
    for(ll i = 1; i <= n; i++) {
        scanf("%lld %lld", &rec[i].h, &rec[i].w);

        if(i == 1) {
            if(rec[i].w > rec[i].h)
                swap( rec[i].w, rec[i].h);
            continue;
        }

        if(rec[i].h > rec[i - 1].h) {
            if(rec[i].w <= rec[i - 1].h)
                swap( rec[i].w, rec[i].h);
            else
                flag = 0;
        }

        if(rec[i].h <= rec[i - 1].h) {
            if(rec[i].w <= rec[i - 1].h && rec[i].w > rec[i].h)
                swap( rec[i].w, rec[i].h);
        }
    }

    if(flag) {
        cout << "YES" << endl;
    }
    else
        cout << "NO" << endl;

    return 0;
}