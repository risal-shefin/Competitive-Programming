#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    scanf("%d", &n);
    int ara[n + 5];
    for(int i = 0; i < n; i++) {
        scanf("%d", &ara[i]);
    }
    int half = 180;
    int checker[half + 5] = {};
    int mx = 0;
    int ans = INT_MAX;
    for(int i = 0; i < n; i++) {
        int sum = ara[i];
        ans = min(ans, abs(360 - sum - sum) );
        for(int j = i + 1; j < n; j++) {
            sum += ara[j];
            ans = min(ans, abs(360 - sum - sum));
        }
    }
    cout << ans << endl;
    return 0;
}
