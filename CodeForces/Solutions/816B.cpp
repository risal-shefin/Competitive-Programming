#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main()

{
    ll n, k, q;
    cin >> n >> k >> q;
    ll cm[200009] = {};
    memset(cm, 0, sizeof(cm));
    for(int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        cm[a]++;
        cm[b + 1]--;
    }

    for(int i = 1; i <= 200000; i++) {
        cm[i] += cm[i - 1];
    }

    for(int i = 1; i <= 200000; i++) {
        if(cm[i] >= k)
            cm[i] = 1;
        else
            cm[i] = 0;
        cm[i] += cm[i - 1];
    }

    for(int i = 0; i < q; i++) {
        int a, b;
        cin >> a >> b;
        cout << cm[b] - cm[a - 1] << endl;
    }
    return 0;
}