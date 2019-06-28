#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int ara[n + 5];
    int mx = INT_MIN;
    int mn = INT_MAX;
    int mxi, mni;
    for(int i = 1; i <= n; i++) {
        scanf("%d", &ara[i]);
        if(mx < ara[i]) {
            mx = ara[i];
            mxi = i;
        }
        if(mn > ara[i]) {
            mn = ara[i];
            mni = i;
        }
    }
    /*if(mni == n && mxi == 1) {
        cout << n - 1 << endl;
        return 0;
    }*/
    if(mxi > mni) {
        int tmp1 = n - mxi;;
        int tmp2 = mni - 1;
        if(tmp1 > tmp2) {
            cout << n - mni << endl;
        }
        else if(tmp2 > tmp1) {
            cout << mxi - 1 << endl;
        }
        else {
            cout << mxi - 1 << endl;
        }
    }
    else if(mxi < mni) {
        int tmp1 = mxi - 1;
        int tmp2 = n - mni;
        if(tmp1 > tmp2) {
            cout << mni - 1 << endl;
        }
        else if(tmp2 > tmp1) {
            cout << n - mxi << endl;
        }
        else {
            cout << mni - 1 << endl;
        }
    }
    return 0;
}
